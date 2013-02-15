#ifndef POTATOES_COLLISION
#define POTATOES_COLLISION

#include "GameObjectCollision.h"

//!PotatoesCollision : collision object with a ship
/*! This class implements the rule of collision of GameObjects when colliding with a
Potatoes,according to the Visitor design pattern.It takes a subclass of GameObject
as its parameter and change its states according to the game rules. */
class PotatoesCollision : public GameObjectCollision
{
  protected :
    Potatoes * mine;//!< the asteroid colliding with others (constant)
  public :
    PotatoesCollision(Potatoes * p) ;//!< constructor
    virtual void collide(SpaceShip * ship)  ;//!<collision with a SpaceShip
    virtual void collide(Bullet * bullet)  ;//!<collision with a Bullet
    virtual void collide(Potatoes * potato)  ;//!<collision with a Potatoes
    virtual void collide(Boom * boom) ;//!< collision with an explosion
} ;

#endif //POTATOES_COLLISION
