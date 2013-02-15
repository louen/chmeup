#ifndef ANIMATEDBULLET_H
#define ANIMATEDBULLET_H
#include "AnimatedObject.h"
//! AnimatedBullet : class representing a sprite for Bullet.
/*!
This class specialises AnimatedObject to represent the sprite for a bullet.
*/
class AnimatedBullet : public AnimatedObject
{
public:
  AnimatedBullet(QString spriteName_a, GameObject* parent_a);//!< Constructor
  virtual QGraphicsItem* getCurrentSprite();//!< Returns the sprite in QGraphicsItem to display
};

#endif // ANIMATEDBULLET_H
