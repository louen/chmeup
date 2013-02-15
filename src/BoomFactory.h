#ifndef BOOMFACTORY_H
#define BOOMFACTORY_H

#include "GameObjectFactory.h"
#include "Boom.h"
#include "AnimatedBoom.h"

//! BoomFactory : a class abstracting the creation of Bullets

/*! This class builds Booms when needed. It is an implementation of the Abstract Factory
design pattern */
class BoomFactory : public GameObjectFactory
{

public:
    GameObject * create(QPoint pos_a);
    //! creates a default explosion
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a);
    //! creates a Boom with a model as a QString
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a, QString model_a);

};

#endif // BOOMFACTORY_H
