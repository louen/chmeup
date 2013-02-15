#include "AnimatedShip.h"
#include "SpaceShip.h"
#include "constants.h"

#include <QApplication>
AnimatedShip::AnimatedShip(QString spriteName_a, GameObject* parent_a) :
    AnimatedObject(spriteName_a, parent_a), ignitionTimer(0)
{
}


QGraphicsItem * AnimatedShip::getCurrentSprite()
{
    QPixmap* currentPixmap;
    SpaceShip* ship = (SpaceShip*)parent;
    int throttle = ship->getThrottle();
    if (throttle <= 0)
    {
      --ignitionTimer;
      if (ignitionTimer < 0)
      {
          ignitionTimer = 0;
      }
    }
    else
    {
      ++ignitionTimer;
      if (ignitionTimer > 4)
      {
          ignitionTimer = 4;
      }
    }
    if (ignitionTimer != 0)
    {
      currentPixmap = new QPixmap(qApp->applicationDirPath()+"/data/sprites/" + spriteName + "_vroom" + QString::number(ignitionTimer) + ".png");
    }
    else
    {
     currentPixmap = new QPixmap(qApp->applicationDirPath()+"/data/sprites/" + spriteName + "_quiet.png");
    }
  return this->centeredPixmap(*currentPixmap) ;
}
