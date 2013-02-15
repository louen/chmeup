#include "CollisionDetector.h"
using namespace std ;

vector< pair<GameObject *,GameObject * > > CollisionDetector::detectCollisions()
{
  vector<GameObject * >::const_iterator a;
  vector<GameObject * >::const_iterator b;



  vector< pair<GameObject *,GameObject * > > result ;

//   // naive object collision algorithm. TODO ; optimize...
//cf. Constant Grids, quadTree,, AABB, remove objects that did not move previously ?
//nb. premature optimization is the root of all evil
for (a = (gameEngine->getGameObjects()).begin() ; a != (gameEngine->getGameObjects()).end() ; ++a)
  {
    for (b = (gameEngine->getGameObjects()).begin() ; *b != *a ; ++b)
    {
      if (((*a)->getHitRect()).intersects((*b)->getHitRect()))
      {
        result.push_back(pair<GameObject *, GameObject *>(*a,*b));
      }
    }
  }
  return result ;
}
