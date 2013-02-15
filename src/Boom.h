#ifndef BOOM_H
#define BOOM_H

#include "GameObjectCollision.h"

class GameObject;
class GameEngine;
//! Boom : a class representing a destroyed ship's explosion
/*! This class is represents an explosion remaining after the destruction of
    a destroyed ship, lasting a small number of frames. It does not interfere
    with other objects.
*/
class Boom : public GameObject
{

public:
    Boom(QPoint pos_a);//!< constructor
    void setHasToBeDeleted(bool var);//!< toggle the flag to be sweeped by the GameEngine
    virtual void updateBehaviour(float timeElapsed, GameEngine * theGameEngine);//!< updates the
    virtual void accept(GameObjectCollision * visitor);//!< accept the collision event to send its real class
    virtual GameObjectCollision * getCollision(); //!< returns a BoomCollision for the
};

#endif // BOOM_H
