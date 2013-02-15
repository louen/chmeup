#include <assert.h>
#include "CollisionSolver.h"
#include "GameObjectCollision.h"
#include "GameObject.h"
using namespace std;


void CollisionSolver::solve(pair< GameObject *, GameObject *> collided)
{

  //first we get a specialized GameObjectCollision from the objects.
  // There we get the concrete type of the first object of the pair
  GameObjectCollision * collA = collided.first->getCollision() ;
  GameObjectCollision * collB = collided.second->getCollision() ;

  // then we send it to the opposite object so it can access the type
  // of the second object. The control then returns to the GOCollision
  // object, knowing both types of the colliding objects
  collided.first->accept(collB) ;
  collided.second->accept(collA) ;

  delete collA ;
  delete collB ;
}

