#include "constants.h"
#include "Bullet.h"
#include "GameEngine.h"
#include "BulletCollision.h"

extern int screenWidthGlobal;
extern int screenHeightGlobal;

Bullet::Bullet(QPoint position, QVector2D acceleration ,QVector2D speed, QSize hitbox, int damage) :
GameObject(position, acceleration , speed, hitbox, 0), m_damage(damage)
{
      setOrientation(RAD_TO_DEG*asin(speed.x()/BULLET_SPEED_LIMIT));
}

void Bullet::setDamage(int d)
{
  m_damage = d ;
}

int Bullet::getDamage() const
{
  return m_damage ;
}

void Bullet::setPlayerId(int id)
{
  m_playerId = id ;
}

int Bullet::getPlayerId() const
{
  return m_playerId ;
}

void Bullet::updateBehaviour(float timeElapsed, GameEngine * theGameEngine)
{
    if(this->getPosition().x() <= 8 || this->getPosition().x() >= screenWidthGlobal - 8 || this->getPosition().y() <= 8 ||  this->getPosition().y() >= screenHeightGlobal - 8 )
    {
        this->m_hasToBeDeleted = true ;
    }
   else
    GameObject::updatePosition(timeElapsed) ;
}

void Bullet::accept(GameObjectCollision * visitor)
{
  visitor->collide(this) ;
}

GameObjectCollision * Bullet::getCollision()
{
  return new BulletCollision(this) ;
}
