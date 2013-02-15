#include "EnemySpaceShipFactory.h"

void EnemySpaceShipFactory::setPlayerSpaceShip(PlayerSpaceShip* pPlayerSpaceShip)
{
  m_pPlayerSpaceShip = pPlayerSpaceShip;
}


GameObject * EnemySpaceShipFactory::create(QPoint pos_a, QVector2D acceleration_a, QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a)
{
  EnemySpaceShipStrategy strategy = STRATEGY_KAMIKAZE;
  EnemySpaceShip * ship = new EnemySpaceShip(pos_a,acceleration_a ,speed_a,hitbox_a,mass_a, 15, m_pPlayerSpaceShip, strategy) ;

  switch(difficultyLevel_a)
  {
  case 1 : // normal
      ship->setHP(10);
      ship->setShootingRate(30);
      break;
  case 2 : // nightmare
      ship->setHP(20);
      ship->setShootingRate(25);
      break;
  case 3 ://hell
      ship->setHP(30);
      ship->setShootingRate(20);
      break;
  default ://set to nightmare
       ship->setHP(20);
       ship->setShootingRate(25);
       break;
  }

  ship->setAnimation(new AnimatedShip("enemy1", ship));
  ship->setFrictionCoef(ENEMY_SPACE_SHIP_FRICTION_COEF);
  ship->setMaxSpeed(ENEMY_SPACE_SHIP_SPEED_LIMIT);
  return ship;
}

GameObject *EnemySpaceShipFactory::create(QPoint pos_a, QVector2D acceleration, QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a, QString model_a)
{
    EnemySpaceShipStrategy strategy;
    if(!model_a.compare("enemy1"))
      strategy = STRATEGY_KAMIKAZE;
    else
      strategy = STRATEGY_ATTACK;
    EnemySpaceShip * ship = new EnemySpaceShip(pos_a,acceleration,speed_a,hitbox_a,mass_a, 15, m_pPlayerSpaceShip, strategy) ;

    switch(difficultyLevel_a)
    {
    case 1 : // normal
        ship->setHP(10);
        ship->setShootingRate(30);
        break;
    case 2 : // nightmare
        ship->setHP(20);
        ship->setShootingRate(25);
        break;
    case 3 ://hell
        ship->setHP(30);
        ship->setShootingRate(20);
        break;
    default ://set to nightmare
         ship->setHP(20);
         ship->setShootingRate(25);
         break;
    }

    ship->setAnimation(new AnimatedShip(model_a, ship));
    ship->setFrictionCoef(ENEMY_SPACE_SHIP_FRICTION_COEF);
    ship->setMaxSpeed(ENEMY_SPACE_SHIP_SPEED_LIMIT);
    return ship;
}

