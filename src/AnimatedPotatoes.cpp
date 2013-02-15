#include "AnimatedPotatoes.h"
#include <QApplication>
AnimatedPotatoes::AnimatedPotatoes(GameObject* parent_a) :
    AnimatedObject("", parent_a)
{
    spriteName = QString::number(rand() % 3 + 1);
}


QGraphicsItem * AnimatedPotatoes::getCurrentSprite()
{
  QPixmap* currentPixmap;
  currentPixmap = new QPixmap(qApp->applicationDirPath()+"/data/sprites/potatoes_"+ spriteName +".png");
  return this->centeredPixmap(*currentPixmap) ;
}
