#ifndef ANIMATEDSHIP_H
#define ANIMATEDSHIP_H

#include "AnimatedObject.h"
//! AnimatedShip : class representing a sprite for SpaceShip.
/*!
This class specialises AnimatedObject to represent the sprite for a ship.
*/
class AnimatedShip : public AnimatedObject
{
protected:
    int ignitionTimer;//!< timer for reactor's flames
public:
  AnimatedShip(QString spriteName_a, GameObject* parent_a);//!< Constructor
  virtual QGraphicsItem* getCurrentSprite();//!< Returns the sprite in QGraphicsItem to display
};

#endif // ANIMATEDSHIP_H
