#include "GameObject.h"
#include "Boom.h"

Boom::Boom(QPoint pos_a) :
    GameObject(pos_a, QVector2D(0,0) , QVector2D(0,0), QSize(0,0), 0)
{
}

void Boom::setHasToBeDeleted(bool var)
{
    this->m_hasToBeDeleted = var ;
}

void Boom::updateBehaviour(float timeElapsed, GameEngine * theGameEngine)
{
}

void Boom::accept(GameObjectCollision * visitor)
{
}

GameObjectCollision * Boom::getCollision()
{
    return NULL;
}
