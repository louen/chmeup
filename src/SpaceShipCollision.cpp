#include "SpaceShipCollision.h"
#include "SpaceShip.h"
#include "Bullet.h"
#include "Potatoes.h"

SpaceShipCollision::SpaceShipCollision(SpaceShip *s) : mine(s) {}

void SpaceShipCollision::collide (SpaceShip * ship)
{
  ship->takeDamage(mine->getMass());
}

void SpaceShipCollision::collide (Bullet * bullet)
{
    if(bullet->getPlayerId() != mine->getPlayerId())
    {
      bullet->needToBeDeleted(true);
    }
}

void SpaceShipCollision::collide (Potatoes * potato)
{
  potato->explode();
}

void SpaceShipCollision::collide (Boom * boom)
{
  // do nothing
}
