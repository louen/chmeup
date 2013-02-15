#include "PotatoesCollision.h"
#include "Potatoes.h"
#include "SpaceShip.h"
#include "Bullet.h"

PotatoesCollision::PotatoesCollision(Potatoes * p) : mine(p) {}

void PotatoesCollision::collide (SpaceShip * ship)
{
  ship->takeDamage(20);
}

void PotatoesCollision::collide (Bullet * bullet)
{
  bullet->needToBeDeleted(true);
}

void PotatoesCollision::collide (Potatoes * potato)
{
  //
}

void PotatoesCollision::collide (Boom * boom)
{
  // do nothing
}
