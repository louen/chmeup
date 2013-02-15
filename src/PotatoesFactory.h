#ifndef POTATOESFACTORY_H
#define POTATOESFACTORY_H
#include "GameObjectFactory.h"
#include "Potatoes.h"
#include "AnimatedPotatoes.h"

//! PotatoesFactory : a class abstracting the creation of Potatoes
/*! This class builds Potatoes when needed. It is an implementation of the Abstract Factory
design pattern */
class PotatoesFactory : public GameObjectFactory
{

public:
    //! creates a default Potatoes without mass
    virtual GameObject * create(QPoint pos_a, QVector2D speed_a, QSize hitbox_a);
    //! creates a default Potatoes
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a);
    //! creates a Potatoes with a model name as a QString
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a, QString model_a);

};

#endif // POTATOESFACTORY_H
