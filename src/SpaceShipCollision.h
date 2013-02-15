#ifndef SPACE_SHIP_COLLISION
#define SPACE_SHIP_COLLISION

#include "GameObjectCollision.h"

//!SpaceShipCollision : collision object with a ship
/*! This class implements the rule of collision of GameObjects when colliding with a
SpaceShip,according to the Visitor design pattern.It takes a subclass of GameObject
as its parameter and change its states according to the game rules. */
class SpaceShipCollision : public GameObjectCollision
{
  protected :
    SpaceShip * mine ;//!< the ship colliding with others (constant)
  public :
    SpaceShipCollision(SpaceShip* s);
    virtual void collide(SpaceShip * ship)  ;//!< collision with a SpaceShip
    virtual void collide(Bullet * bullet)  ;//!< collision with a Bullet
    virtual void collide(Potatoes * potato)  ;//!< collition with Potatoes
    virtual void collide(Boom * boom) ; //!< collision with a Boom

} ;

#endif //SPACE_SHIP_COLLISION
