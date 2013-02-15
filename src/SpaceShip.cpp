#include "SpaceShip.h"
#include "GameEngine.h"
#include "SpaceShipCollision.h"

SpaceShip::SpaceShip(QPoint position, QVector2D acceleration , QVector2D speed, QSize hitBox, int mass, int playerId,int shootingRate) :
GameObject(position,acceleration ,speed,hitBox, mass),m_playerId(playerId), m_throttle(0),m_shootingRate(shootingRate),m_readyToFire(true),m_cooldownTimer(0),m_shooting(false)
{

}

void SpaceShip::setThrottle(int throttle)
{
  m_throttle= throttle ;
}

int SpaceShip::getThrottle() const
{
  return m_throttle ;
}

void SpaceShip::setShooting(bool on)
{
  m_shooting = on ;
}

bool SpaceShip::getShooting() const
{
  return m_shooting ;
}

void SpaceShip::setShootingRate(int shootingRate)
{
   m_shootingRate = shootingRate ;
}

void SpaceShip::takeDamage(int damage)
{
  m_HP -=damage ;
  if (m_HP<=0)
  {
     m_hasToBeDeleted = true ;
  }
}

int SpaceShip::getPlayerId() const
{
  return m_playerId ;
}

void SpaceShip::updatePosition(float timeElapsed)
{
    //Update acceleration with throttle and mass
    acceleration = ((float)m_throttle/(float)mass)*QVector2D(sin(DEG_TO_RAD*(float)angle),-cos(DEG_TO_RAD*(float)angle)) ; // Beware : clockwise way ! / 90° shift !
    //Beware 2: Not "+=", "=" !
    if(acceleration.length()>=SPACE_SHIP_ACCELERATION_LIMIT )
        acceleration= SPACE_SHIP_ACCELERATION_LIMIT*acceleration.normalized();

    //Update position
    GameObject::updatePosition(timeElapsed);

}

void SpaceShip::accept(GameObjectCollision * visitor)
{
  visitor->collide(this) ;
}

GameObjectCollision * SpaceShip::getCollision()
{
  return new SpaceShipCollision(this) ;
}

int SpaceShip::getHP() const
{
    return m_HP ;
}

void SpaceShip::setHP(int HPNubmer)
{
    m_HP = HPNubmer ;
}

GameObject* SpaceShip::destruct(BoomFactory* theBoomFactory)
{
    GameObject* boomer = theBoomFactory->create(this->getPosition());
    return boomer;
}
