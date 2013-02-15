#include "AnimatedBoom.h"
#include "constants.h"

#include <QApplication>

AnimatedBoom::AnimatedBoom(GameObject* parent_a) :
    AnimatedObject("", parent_a), timer(BOOM_TIMER)
{
}

bool AnimatedBoom::decreaseTimer()
{
    --timer;
    return (timer < 1);
}

QGraphicsItem * AnimatedBoom::getCurrentSprite()
{
  if (decreaseTimer())
  {
      Boom* origin = (Boom*)parent;
      origin->setHasToBeDeleted(true);
  }
  QPixmap* currentPixmap;
  currentPixmap = new QPixmap(qApp->applicationDirPath()+"/data/sprites/boom.png");
  return this->centeredPixmap(*currentPixmap) ;
}
