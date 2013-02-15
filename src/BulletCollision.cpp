#include "BulletCollision.h"
#include "Bullet.h"
#include "SpaceShip.h"

BulletCollision::BulletCollision(Bullet * b) : mine(b){}

void BulletCollision::collide (SpaceShip * ship)
{
  if(ship->getPlayerId() != mine->getPlayerId())
  {
    ship->takeDamage(mine->getDamage()) ;
  }
}

void BulletCollision::collide (Bullet * bullet)
{
  // do nothing
}

void BulletCollision::collide (Potatoes * potato)
{
  // do nothing ? Can we destroy asteroids ?
}

void BulletCollision::collide (Boom * boom)
{
  // do nothing
}
