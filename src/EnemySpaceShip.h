#ifndef ENEMYSPACESHIP_H_
#define ENEMYSPACESHIP_H_

#include "SpaceShip.h"
#include "PlayerSpaceShip.h"
#include "GameEngine.h"
#include <QObject>
//! Ennemy ships strategies
/*! Enumerates the different "AI" strategies for ennemy ships.
*/
enum EnemySpaceShipStrategy
{
  STRATEGY_KAMIKAZE, //!< ennemy rushing to the player
  STRATEGY_ATTACK //!< ennemy turning around the player and shooting
};

//! EnemySpaceShip : AI-controlled ships opposed to the player

/*! This class specializes the SpaceShip to represent a CPU-controlled ship
    that tries to destroy the player's ship. Its behavior is governed by
    different strategies, that determine its moves and shooting state */

class EnemySpaceShip : public QObject, public SpaceShip
{
  Q_OBJECT
  public:
    //! constructor
    EnemySpaceShip(QPoint position, QVector2D acceleration, QVector2D speed, QSize hitBox, int mass, int shootingRate, PlayerSpaceShip* pPlayerSpaceShip, EnemySpaceShipStrategy strategy);
    void updateBehaviour(float timeElapsed, GameEngine * theGameEngine);//!< updates position, shooting state, etc. based on the strategy

  protected :
      void updateShooting(GameEngine * theGameEngine);//!< updates the shooting state of the ship
      virtual void updatePosition(float timeElapsed); //!< physics movement processing

  private:
    PlayerSpaceShip* m_pPlayerSpaceShip; //!< the player's space ship (aka the target)
    EnemySpaceShipStrategy m_strategy; //!< strategy adopted by the ship

};

#endif /* ENEMYSPACESHIP_H_ */
