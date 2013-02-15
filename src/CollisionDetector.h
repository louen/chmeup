//! CollisionDetector : analyse the game data and return colliding GameObjects

/*! This class implements the detection of collision between GameObjects.
    One day maybe it should be made a functionnal object (with () operator
    overloaded) . It returns pairs of colliding GameObjects to be managed
    by the CollisionSolver.
*/
#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include <utility>
#include <vector>

#include "GameEngine.h"
#include "GameObject.h"

class CollisionDetector
{
  protected:
     GameEngine* gameEngine; //!< reference to the current game engine
  public:
    inline CollisionDetector(GameEngine *  g_a) : gameEngine(g_a) {} ;//!< default constructor
    std::vector< std::pair<GameObject *,GameObject * > > detectCollisions() ; //!< returns a list of objects that are colliding
};

#endif// COLLISION_DETECTOR_H
