#ifndef GAME_OBJECT_COLLISION
#define GAME_OBJECT_COLLISION
class SpaceShip ;
class Bullet ;
class Potatoes ;
class Boom ;

//! GameObjectCollision : abstract base class for collision visitors classes
/*! This  class is an implementation of the Visitor design pattern. Its purpose is to
    get the concrete class of both collifing objects and taking appropriate action.
    The 'collide' methods will perform the consequences of the collision on their argument.
    The implementation is left to the subclasses. They usually hold a pointer to the first
    colliding object
*/
class GameObjectCollision
{
  public :
    virtual void collide(SpaceShip * ship) = 0 ;//!< collision with a SpaceSship
    virtual void collide(Bullet * bullet) = 0 ;//!< collision with a Bullet
    virtual void collide(Potatoes * potato) = 0 ;//!< collision with a Potatoes
    virtual void collide(Boom * boom) = 0 ;//!< collision with an explosion
} ;

#endif //GAME_OBJECT_COLLISION
