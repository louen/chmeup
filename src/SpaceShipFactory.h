#ifndef SPACE_SHIP_FACTORY_H
#define SPACE_SHIP_FACTORY_H
#include "GameObjectFactory.h"
#include "GameObject.h"
#include "SpaceShip.h"
#include "AnimatedShip.h"

//! SpaceShipFactory : a class abstracting the creation of SpaceShips

/*! This class builds SpaceShips when needed. It is an implementation of the Abstract Factory
design pattern. Since SpaceShip is abstract, it is also */
class SpaceShipFactory : public GameObjectFactory
{
  public:
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a) =0;
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a, QString model_a) =0;
};

#endif // SPACE_SHIP_FACTORY_H
