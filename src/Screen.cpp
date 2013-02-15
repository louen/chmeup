#include "Screen.h"
#include "GameObject.h"
#include "constants.h"

#include <vector>
#include <iostream>
#include <QPen>
#include <QGraphicsItem>

using namespace std ;

extern int screenWidthGlobal;
extern int screenHeightGlobal;

Screen::Screen (QWidget * parent) :
  QGraphicsView (parent)
{
  scene = new QGraphicsScene(this) ;
}

Screen::~Screen()
{
  delete scene ;
}

void Screen::update(GameEngine * const game)
{
  QPen pen ;
  vector<GameObject * >::const_iterator o ;

  scene->clear();
    // sets black background
  scene->setSceneRect(0,0,screenWidthGlobal,screenHeightGlobal);
  scene->addRect(0,0,screenWidthGlobal,screenHeightGlobal,pen,bgBrush);



  for (o = (game->getGameObjects()).begin() ; o!= (game->getGameObjects()).end() ; ++o)
  {
    QGraphicsItem  * item = (*o)->getAnimation();
    item->setPos((*o)->getPosition());
    item->setRotation((*o)->getOrientation()) ;
    scene->addItem(item);

  }
  QFont HPCounterFont = QFont("Arial",14);
  HPCounterFont.setBold(true);
  HPCounter = scene->addText("HP: "+ QString::number(game->getPlayerSpaceShipHP())) ;
  HPCounter->setFont(HPCounterFont);
  HPCounter->setPos(screenWidthGlobal - 80 , 0);
  HPCounter->setDefaultTextColor("white");

  setScene(scene);
}

void Screen::gameOverScreen()
{
   QPen pen ;
   QGraphicsTextItem * GameOverText ;
   QFont gameOverFont = QFont("georgia",32,3);
   gameOverFont.setBold(true);

   scene->clear();
   scene->setSceneRect(0,0,screenWidthGlobal,screenHeightGlobal);
   scene->addRect(0,0,screenWidthGlobal,screenHeightGlobal,pen,bgBrush);

   GameOverText = scene->addText("Game Over... You failed !") ;
   GameOverText->setDefaultTextColor ("red");
   GameOverText->setFont(gameOverFont);
    GameOverText->setPos((screenWidthGlobal - GameOverText->sceneBoundingRect().width())/2 , (screenHeightGlobal - GameOverText->sceneBoundingRect().height())/2);

}

void Screen::gameWonScreen()
{
    QPen pen ;
    QGraphicsTextItem * GameOverText ;
    QFont gameOverFont = QFont("georgia",32,3);
    gameOverFont.setBold(true);

    scene->clear();
    scene->setSceneRect(0,0,screenWidthGlobal,screenHeightGlobal);
    scene->addRect(0,0,screenWidthGlobal,screenHeightGlobal,pen,bgBrush);

    GameOverText = scene->addText("You finished this level !!!\n\tYou're so badass !") ;
    GameOverText->setDefaultTextColor ("green");
    GameOverText->setFont(gameOverFont);
    GameOverText->setPos((screenWidthGlobal - GameOverText->sceneBoundingRect().width())/2 , (screenHeightGlobal - GameOverText->sceneBoundingRect().height())/2);
}
