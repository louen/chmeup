#include <time.h>

#include "ScenarioDemoLevel.h"

#include "constants.h"

#define POTATO_INTERVAL 5
#define KAMIKAZE_COOLDOWN 3
#define ATTAQUER_COOLDOWN 6

extern int screenWidthGlobal;
extern int screenHeightGlobal;

ScenarioDemoLevel::ScenarioDemoLevel(GameEngine* pGameEngine) : Scenario(pGameEngine), m_kamikasesLeft(5), m_attaquersLeft(5), m_nextPotato(POTATO_INTERVAL),
m_kamikasesCoolDown(KAMIKAZE_COOLDOWN),m_attaquersCoolDown(ATTAQUER_COOLDOWN)
{
  srand(time(NULL)); //For random position generator
  registerGE(m_pGameEngine) ;
}

ScenarioDemoLevel::~ScenarioDemoLevel()
{

}

void ScenarioDemoLevel::initialize(int difficultyLevel)
{
  cleanup();

  m_difficultyLevel = difficultyLevel ;
  switch(m_difficultyLevel)
  {
     case 1 : //for Normal
         m_kamikasesNumber = 5 ;
         m_attaquerNumber = 5;
         break ;
     case 2: //for Nightmare
         m_kamikasesNumber = 10 ;
         m_attaquerNumber = 10;
         break;
     case 3: //for Hell
         m_kamikasesNumber = 20 ;
         m_attaquerNumber = 20;
         break;
     default : // set to normal
         m_kamikasesNumber = 10 ;
         m_attaquerNumber = 10;
         break;
  }

  m_kamikasesLeft = m_kamikasesNumber ;
  m_attaquersLeft = m_attaquerNumber ;

  //Insert PlayerSpaceShip in GameEngine
  m_pPlayerSpaceShip = (PlayerSpaceShip *) m_PSSFactory.create(QPoint(200,200),QVector2D(0,0) ,QVector2D(0,0),QSize(15,15),10,m_difficultyLevel); //Ownership will be passed to the GameEngine
  m_pGameEngine->addPlayerSpaceShip(m_pPlayerSpaceShip) ;
  m_ESSFactory.setPlayerSpaceShip(m_pPlayerSpaceShip);
}

void ScenarioDemoLevel::update(float timeElapsed)
{
  m_nextPotato -= timeElapsed;
  while(m_nextPotato<0)
  {
    m_nextPotato+=POTATO_INTERVAL;
    //Inject potato at random position
    QPoint pos;
    QVector2D speed;
    QSize size(35,35);
    getRandomPosition(&pos, &speed, 50, size);
    GameObject* potato = m_PFactory.create(pos, speed, size);
    m_pGameEngine->addGameObject(potato);
    m_lpPotatoes.push_back(potato);
  }
  if(m_lpAttaquersEnemySpaceShips.size() < 1 && m_attaquersLeft)
  {
      if(m_attaquersCoolDown < 0)
      {
        m_attaquersCoolDown = ATTAQUER_COOLDOWN;
        QPoint pos;
        QVector2D speed;
        QSize size(20,20);
        getRandomPosition(&pos, &speed, 50, size);
        GameObject* enemy = m_ESSFactory.create(pos,QVector2D(0,0),speed,size,10,m_difficultyLevel,"enemy2");
        m_pGameEngine->addGameObject(enemy);
        m_lpAttaquersEnemySpaceShips.push_back(enemy);
        m_attaquersLeft--;
        }
      else
          m_attaquersCoolDown-=timeElapsed;
  }
  if(m_lpKamikazesEnemySpaceShips.size() < 1 && m_kamikasesLeft)
  {
      if(m_kamikasesCoolDown < 0)
      {
        m_kamikasesCoolDown = KAMIKAZE_COOLDOWN ;
        QPoint pos;
        QVector2D speed;
        QSize size(20,20);
        getRandomPosition(&pos, &speed, 50, size);
        GameObject* enemy = m_ESSFactory.create(pos,QVector2D(0,0),speed,size,10,m_difficultyLevel,"enemy1");
        m_pGameEngine->addGameObject(enemy);
        m_lpKamikazesEnemySpaceShips.push_back(enemy);
        m_kamikasesLeft--;
      }
      else
          m_kamikasesCoolDown-=timeElapsed;
  }
  // If all the ennemies have been killed, we end the level
  if(m_lpAttaquersEnemySpaceShips.size()==0 && !m_attaquersLeft && m_lpKamikazesEnemySpaceShips.size()==0 && !m_kamikasesLeft)
  {
      m_pGameEngine->endGame(true);
  }
}

void ScenarioDemoLevel::destroyed(GameObject* pObject)
{
  if(m_pPlayerSpaceShip == pObject)
  {
    m_pPlayerSpaceShip = NULL;
    cleanup();
  }
  else
  {
    m_lpAttaquersEnemySpaceShips.remove(pObject);
    m_lpKamikazesEnemySpaceShips.remove(pObject);
    m_lpPotatoes.remove(pObject);
  }
}

void ScenarioDemoLevel::gameOver()
{
  cleanup();
}

void ScenarioDemoLevel::cleanup()
{
  m_pPlayerSpaceShip = NULL;
  m_lpAttaquersEnemySpaceShips.clear();
  m_lpKamikazesEnemySpaceShips.clear();
  m_lpPotatoes.clear();
}

void ScenarioDemoLevel::getRandomPosition(QPoint* pPos, QVector2D* pSpeed, unsigned int speedMagnitude, const QSize& size)
{
  int side = rand() % 4;
  float angle = (rand() % 180) * DEG_TO_RAD - 90;
  switch(side)
  {
  case 0: //Left
    pPos->setX(0 - size.width());
    pPos->setY(rand() % screenHeightGlobal);
    pSpeed->setX(speedMagnitude*cos(angle));
    pSpeed->setY(speedMagnitude*sin(angle));
    break;
  case 1: //Top
    pPos->setX(rand() % screenWidthGlobal);
    pPos->setY(0 - size.height());
    pSpeed->setX(speedMagnitude*sin(angle));
    pSpeed->setY(-speedMagnitude*cos(angle));
    break;
  case 2: //Right
    pPos->setX(screenWidthGlobal - 1 + size.width());
    pPos->setY(rand() % screenHeightGlobal);
    pSpeed->setX(-speedMagnitude*cos(angle));
    pSpeed->setY(speedMagnitude*sin(angle));
    break;
  case 3: //Bottom
    pPos->setX(rand() % screenWidthGlobal);
    pPos->setY(screenHeightGlobal - 1 + size.height());
    pSpeed->setX(speedMagnitude*sin(angle));
    pSpeed->setY(speedMagnitude*cos(angle));
    break;
  }
}

