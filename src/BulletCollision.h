#ifndef BULLET_COLLISION
#define BULLET_COLLISION

#include "GameObjectCollision.h"
//!BulletCollision : collision object with a bullet
/*! This class implements the rule of collision of GameObjects when colliding with a Bullet,
    according to the Visitor design pattern.It takes a subclass of GameObject as its
    parameter and change its states according to the game rules. */

class BulletCollision : public GameObjectCollision
{
  protected:
    Bullet * mine ;//!< the bullet colliding with others (constant)
  public :
    BulletCollision(Bullet* b) ; //!< constructor
    virtual void collide(SpaceShip * ship)  ; //!<collision with a SpaceShip
    virtual void collide(Bullet * bullet)  ; //!<collision with a Bullet
    virtual void collide(Potatoes * potato)  ; //!<collision with a Potatoes
    virtual void collide(Boom * boom) ; //!< collision with an exploding ship (ignored)
} ;

#endif //BULLET_COLLISION
