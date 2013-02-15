#ifndef BOOMCOLLISION_H
#define BOOMCOLLISION_H

#include "GameObjectCollision.h"
//!BulletCollision : collision object with a bullet
/*! This class implements the rule of collision of GameObjects when colliding with a Bullet,
according to the Visitor design pattern.It takes a subclass of GameObject as its
parameter and change its states according to the game rules. */

class BoomCollision : public GameObjectCollision
{
public:
    BoomCollision(Boom * b);//!<constructor
    virtual void collide(SpaceShip * ship) ;//!< collision with a ship
    virtual void collide(Bullet * bullet) ; //!<collision with a bullet
    virtual void collide(Potatoes * potato) ;//!< collision with an asteroid
    virtual void collide(Boom * boom) ; //!< collision with an explosion
};

#endif // BOOMCOLLISION_H
