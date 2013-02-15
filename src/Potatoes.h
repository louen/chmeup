#ifndef POTATOES_H
#define POTATOES_H
#include "GameObject.h"
//! Potatoes : a class representing an asteroid


/*! This class represents an asteroid floating through space. Its behaviour is just
    to drift and to collide with objects to destroy them
*/
class Potatoes : public GameObject
{

public:
    Potatoes(QPoint position, QVector2D speed, QSize hitbox);//!< constructor
    void explode(); //!<Fry the potato!
    virtual void updatePosition(float timeElapsed);//!<update the position according to physics of the asteorid
    virtual void updateBehaviour(float timeElapsed, GameEngine * theGameEngine);//!<!Implements the correct behavior for the asteroids
    virtual void accept(GameObjectCollision * visitor) ; //!< Receive a collision event to send it its real class
    virtual GameObjectCollision * getCollision(); //!< Return a PotatoesCollision for the CollisionSolver
};

#endif // POTATOES_H
