#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include "GameObject.h"
//! GameObjectFactory : abstract base class for all the GameObject's subclasses factories

/*! This class is the base class for the classes governing the creation of GameObject's
    sublclasses, conforming to the Abstract Factory design pattern */
class GameObjectFactory
{
  public:
    //! creation of a GameObject with default properties
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a) = 0 ;
    //! creation of a GameObject with a model specified as a QString
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a, QString model_a)=0;
};

#endif // GAME_OBJECT_FACTORY_H
