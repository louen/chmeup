#ifndef PLAYER_SPACE_SHIP_FACTORY_H
#define PLAYER_SPACE_SHIP_FACTORY_H
#include "SpaceShipFactory.h"
#include "GameObject.h"
#include "PlayerSpaceShip.h"
#include "AnimatedShip.h"
//! PlayerSpaceShipFactory : a class abstracting the creation of EnnemySpaceShips

/*! This class builds PlayerSpaceShips when needed. It is an implementation of the Abstract Factory
design pattern. It sets the target and the strategy of the built ennemy ships*/
class PlayerSpaceShipFactory : public SpaceShipFactory
{
  public:
    //! creates a default PlayerSpaceShip
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration_a, QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a);
    //! creates a PlayerSpaceShip specifying a model name as a QString.
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration, QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a, QString model_a);
};

#endif // PLAYER_SPACE_SHIP_FACTORY_H
