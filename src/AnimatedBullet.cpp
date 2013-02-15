#include "AnimatedBullet.h"
#include <QApplication>
AnimatedBullet::AnimatedBullet(QString spriteName_a, GameObject* parent_a) :
    AnimatedObject(spriteName_a, parent_a)
{
}


QGraphicsItem * AnimatedBullet::getCurrentSprite()
{
  QPixmap* currentPixmap;
  currentPixmap = new QPixmap(qApp->applicationDirPath()+"/data/sprites/" + spriteName + "_bullet.png");
  return this->centeredPixmap(*currentPixmap) ;
}
