#include "GameEngine.h"
#include "CollisionDetector.h"
#include "CollisionSolver.h"
#include "constants.h"
#include "PlayerSpaceShip.h"
#include "SpaceShip.h"
#include "Boom.h"
#include <utility>
#include <vector>

#include <iostream>

using namespace std ;

GameEngine::GameEngine()
{
  collisionDetector = new CollisionDetector(this);
  collisionSolver = new CollisionSolver;
  //scenario = new Scenario ;
  timer = new QTimer(this) ;
  theBulletFactory = new BulletFactory ;
  theBoomFactory = new BoomFactory ;
  playerSpaceShip = NULL ;
  timer->setInterval(1000 / FRAME_RATE) ;
  connect(timer,SIGNAL(timeout()),this,SLOT(nextFrame()));
}

GameEngine::~GameEngine()
{
  deleteGameObjects() ;

  delete collisionDetector ;
  delete collisionSolver ;
  delete timer ;
  delete theBulletFactory ;
}


const vector<GameObject * >& GameEngine::getGameObjects() const
{
  return gameObjects;
}


void GameEngine::setDifficultyLevel(int level)
{
   difficultyLevel = level; // 1 for normal, 2 for Nightmare, 3 for Hell
}

int GameEngine::getDifficultyLevel() const
{
    return difficultyLevel ;
}

void GameEngine::addGameObject(GameObject * object)
{
  gameObjects.push_back(object) ;
}

void GameEngine::addPlayerSpaceShip(PlayerSpaceShip * PSS)
{
  if (playerSpaceShip != NULL)
  // if there is already a pss, we must find it and delete it before adding the new one
  {
    vector<GameObject*>::iterator o ;
    for (o = gameObjects.begin() ; o!= gameObjects.end() ; ++o)
    {
      if (*o == playerSpaceShip)
      {
        o = gameObjects.erase(o);
        break;
      }
    }
    delete playerSpaceShip;
  }
  playerSpaceShip = PSS ;
  addGameObject(PSS) ;
}

PlayerSpaceShip * GameEngine::getPlayerSpaceShip() const
{
  return playerSpaceShip ;
}

BulletFactory * GameEngine::getBulletFactory() const
{
   return theBulletFactory ;
}

void GameEngine::deleteGameObjects()
{
  playerSpaceShip = NULL;
  vector<GameObject * >::iterator o ;
  for (o = gameObjects.begin() ; o!= gameObjects.end() ; ++o)
  {
    delete (*o) ;
    //(*o) = NULL ;
  }
  gameObjects.clear();
}

void GameEngine::start()
{
  timer->stop();
  deleteGameObjects();
  scenario->initialize(difficultyLevel);
  timer->start();
  framesPlayed=0 ;
}

void GameEngine::stop()
{
  timer->stop() ;
}

void GameEngine::pause()
{
  if(timer->isActive())
  {
      //qDebug() <<"GameEngine: game paused" ;
      timer->stop() ;
  }
  else
  {
      //qDebug() <<"GameEngine: game resumed" ;
      timer->start();
  }
}


void GameEngine::getKeyFrame(KeyPressedFrame * kf)
{
  if (getPlayerSpaceShip() != NULL) {
    if (kf->left)
      getPlayerSpaceShip()->keyLeft();
    if(kf->right)
      getPlayerSpaceShip()->keyRight();
    if(kf->up&&!kf->down)
      getPlayerSpaceShip()->keyUp();
    else if(kf->down&&!kf->up)
      getPlayerSpaceShip()->keyDown();
    else
      getPlayerSpaceShip()->keyUpDownRelease();

    getPlayerSpaceShip()->setShooting(kf->shoot);
  }
  delete kf ;
}


void GameEngine::nextFrame()
{
    process();
    scenario->update(1./(float)FRAME_RATE);

}

void GameEngine::process()
{
  vector<GameObject * >::iterator o ;
  bool stuffToDelete = false ;
  // this is the main processing function, run at each frame

  // get user input
  emit requestKeyUI();
  // get movement intention from ennemy ships ("AI")

  // deduce new position of flying objects
  vector<GameObject * > gameObjectsCopy = gameObjects ; // copy of the current vector, for the iterators
  for (o = gameObjectsCopy.begin() ; o!= gameObjectsCopy.end() ; ++o)
  {
     (*o)->updateBehaviour(1./(float)FRAME_RATE,this) ;
     if(!stuffToDelete && (*o)->hasToBeDeleted())
         stuffToDelete = true ;
  }

  if(playerSpaceShip->hasToBeDeleted()) // The PlayerSpaceShip has to be deleted, the player has failed, the game is over... sad...
  {
     endGame(false);
     return ;
  }

  // delete the GameObjects that have beeen flagged
  if(stuffToDelete){
      for (o = gameObjects.begin() ; o!= gameObjects.end() ; ++o)
      {
         if((*o)->hasToBeDeleted()){
             scenario->destroyed((GameObject*) *o); //We warn the scenario that we are going to delete an object
             GameObject* explode = (*o)->destruct(theBoomFactory);
             delete *o ;
             gameObjects.erase(o);
             if (explode != NULL)
             {
                 gameObjects.push_back(explode);
             }
             o = gameObjects.begin(); //When a vector is deleted, we have to reconstruct the index, so we go back to the first element.
         }
      }
    }

  // detect collisions
  vector< pair<GameObject *,GameObject * > > collisions = collisionDetector->detectCollisions() ;
  //solve collisions
  vector< pair<GameObject *,GameObject * > >::iterator c;
  for (c=collisions.begin() ; c != collisions.end(); ++c)
  {
    collisionSolver->solve(*c) ;
  }
  // add new ennemies to the level


  // notifies UI to update itself
  emit updateUI();
  ++framesPlayed ;
}


int GameEngine::getPlayerSpaceShipHP() const
{
   return playerSpaceShip->getHP();
}

void GameEngine::endGame(bool victory)
{
   stop(); // stop the timer
   scenario->gameOver(); // warn the scenario
   deleteGameObjects(); // clear the Game Objects list
   playerSpaceShip = NULL ;
   if(victory)
      emit displayGameWonScreen(); // We notify the UI we want to display the GW Screen
   else
      emit displayGameOverScreen(); // We notify the UI we want to display the GO Screen
}


void GameEngine::registerScenario(Scenario * currentScenario)
{
   scenario = currentScenario ;
}
