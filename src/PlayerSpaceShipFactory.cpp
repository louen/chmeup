#include "PlayerSpaceShipFactory.h"
// WARN : playerID is fixed to 1 for the moment, but could be changed when we will allow several players
GameObject * PlayerSpaceShipFactory::create(QPoint pos_a, QVector2D acceleration_a, QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a){

  PlayerSpaceShip * ship = new PlayerSpaceShip(pos_a,acceleration_a ,speed_a,hitbox_a,mass_a,1, 15) ;

  switch(difficultyLevel_a)
  {
  case 1 : // normal
      ship->setHP(150);
      ship->setShootingRate(10);
      break;
  case 2 : // nightmare
      ship->setHP(100);
      ship->setShootingRate(10);
      break;
  case 3 ://hell
      ship->setHP(50);
      ship->setShootingRate(15);
      break;
  default ://set to nightmare
       ship->setHP(100);
       ship->setShootingRate(10);
       break;
  }

  ship->setAnimation(new AnimatedShip("player", ship));
  ship->setFrictionCoef(PLAYER_SPACE_SHIP_FRICTION_COEF);
  ship->setMaxSpeed(PLAYER_SPACE_SHIP_SPEED_LIMIT);
  return ship;
}


GameObject *PlayerSpaceShipFactory::create(QPoint pos_a, QVector2D acceleration, QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a ,QString model_a)
{
    PlayerSpaceShip * ship = new PlayerSpaceShip(pos_a,acceleration,speed_a,hitbox_a,mass_a, 1,15) ;
    switch(difficultyLevel_a)
    {
    case 1 : // normal
        ship->setHP(150);
        ship->setShootingRate(10);
        break;
    case 2 : // nightmare
        ship->setHP(100);
        ship->setShootingRate(10);
        break;
    case 3 ://hell
        ship->setHP(50);
        ship->setShootingRate(15);
        break;
    default ://set to nightmare
         ship->setHP(100);
         ship->setShootingRate(10);
         break;
    }
    ship->setAnimation(new AnimatedShip(model_a, ship));
    ship->setFrictionCoef(PLAYER_SPACE_SHIP_FRICTION_COEF);
    ship->setMaxSpeed(PLAYER_SPACE_SHIP_SPEED_LIMIT);
    ship->setHP(PLAYER_SPACE_SHIP_HP);
    return ship;
}
