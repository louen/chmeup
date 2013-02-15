#include "Potatoes.h"
#include "PotatoesCollision.h"
Potatoes::Potatoes(QPoint position, QVector2D speed, QSize hitbox) :
    GameObject(position, QVector2D(0,0), speed, hitbox, 0)
{

}


void Potatoes::explode()
{
  m_hasToBeDeleted = true;
}

//Default implementation
void Potatoes::updatePosition(float timeElapsed)
{
    GameObject::updatePosition(timeElapsed);
}

void Potatoes::updateBehaviour(float timeElapsed, GameEngine * theGameEngine)
{
   updatePosition(timeElapsed) ;
}

void Potatoes::accept(GameObjectCollision * visitor)
{
  visitor->collide(this) ;
}

GameObjectCollision * Potatoes::getCollision()
{
  return new PotatoesCollision(this) ;
}
