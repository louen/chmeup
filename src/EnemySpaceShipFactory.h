#ifndef ENEMYSPACESHIPFACTORY_H_
#define ENEMYSPACESHIPFACTORY_H_
#include "SpaceShipFactory.h"
#include "GameObject.h"
#include "EnemySpaceShip.h"
#include "PlayerSpaceShip.h"
#include "AnimatedShip.h"
//! EnemySpaceShipFactory : a class abstracting the creation of EnnemySpaceShips

/*! This class builds EnemySpaceships when needed. It is an implementation of the Abstract Factory
design pattern. It sets the target and the strategy of the built ennemy ships*/
class EnemySpaceShipFactory : public SpaceShipFactory
{
  public:
    void setPlayerSpaceShip(PlayerSpaceShip* pPlayerSpaceShip);//!< sets the target of created space ships
    //! creates a default EnnemySpaceShip
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration, QVector2D speed_a, QSize hitbox_a, int mass_a , int difficultyLevel_a);
    //! creates an EnnemySpaceShip specifying a model name.
    virtual GameObject * create(QPoint pos_a, QVector2D acceleration, QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a ,QString model_a);

  private:
    PlayerSpaceShip* m_pPlayerSpaceShip;//!< target of created space ships

};

#endif /* ENEMYSPACESHIPFACTORY_H_ */
