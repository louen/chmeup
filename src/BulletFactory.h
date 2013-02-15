#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include "GameObjectFactory.h"
#include "GameObject.h"
#include "Bullet.h"
#include "AnimatedBullet.h"
//! BulletFactory : a class abstracting the creation of Bullets

/*! This class builds Bullets when needed. It is an implementation of the Abstract Factory
    design pattern */
class BulletFactory : public GameObjectFactory
{
  public:
    //! creates a default Bullet
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass, int difficultyLevel_a);
    //! cureates Bullet with a model name as a QString
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass, int difficultyLevel_a ,QString model_a);
};

#endif // BULLETFACTORY_H
