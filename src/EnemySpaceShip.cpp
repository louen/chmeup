#include "EnemySpaceShip.h"
#include "GameEngine.h"
#include <math.h>
#include <iostream>

extern int screenWidthGlobal;
extern int screenHeightGlobal;

EnemySpaceShip::EnemySpaceShip(QPoint position, QVector2D acceleration , QVector2D speed, QSize hitBox, int mass, int shootingRate, PlayerSpaceShip* pPlayerSpaceShip, EnemySpaceShipStrategy strategy ) :
SpaceShip(position, acceleration ,speed, hitBox, mass, 0, shootingRate), m_pPlayerSpaceShip(pPlayerSpaceShip), m_strategy(strategy)
{
}

void EnemySpaceShip::updatePosition(float timeElapsed)
{
  //Setup throttle & angle according to strategy and the player's spaceship position
  QVector2D targetVector;
  bool targetVector_init = false;
  //Look for the closest spaceship object in a virtual 3x3 square
  for(int col = -1; col <= 1; col++)
  {
    for(int row = -1; row <= 1; row++)
    {
      QVector2D targetVector_i = QVector2D(m_pPlayerSpaceShip->getPosition() - getPosition()) + QVector2D(m_pPlayerSpaceShip->getSpeed() - getSpeed())*timeElapsed + QVector2D(row*screenHeightGlobal, col*screenWidthGlobal);
      if(!targetVector_init || targetVector_i.length() < targetVector.length())
      {
        targetVector = targetVector_i;
        targetVector_init = true;
      }
    }
  }

  //Find angle to follow in a [-180; 180] interval
  float targetAngle = (180 - ( atan2(targetVector.x(), targetVector.y()) / DEG_TO_RAD ));
  while(targetAngle>180)
    targetAngle-=360;
  while(targetAngle<=-180)
    targetAngle+=360;
  float targetDistance = targetVector.length();

  float deltaAngle = targetAngle - angle;
  while(deltaAngle>180)
    deltaAngle-=360;
  while(deltaAngle<=-180)
    deltaAngle+=360;

  switch(m_strategy)
  {
  case STRATEGY_ATTACK:

    //Fuzzy logic controller !
    if( abs(deltaAngle) > ENEMY_SPACE_SHIP_ROTATION_SPEED )
    {
      if( deltaAngle < 0 )
        angle = (angle - ENEMY_SPACE_SHIP_ROTATION_SPEED)%360 ;
      else //if( deltaAngle > 0)
        angle = (angle + ENEMY_SPACE_SHIP_ROTATION_SPEED)%360 ;
    }
    else
    {
      angle = targetAngle;
    }

    //Recompute delta angle
    deltaAngle = targetAngle - angle;
    while(deltaAngle>180)
      deltaAngle-=360;
    while(deltaAngle<=-180)
      deltaAngle+=360;


    if( targetDistance > 100 )
    {
      m_shooting = false;
      m_throttle = ENEMY_SPACE_SHIP_ACCELERATION_QUANTA;
    }
    else if( targetDistance > 50 )
    {
      if(QVector2D::dotProduct(speed, targetVector) <0)
      {
        if(abs(deltaAngle) < 90)
        {
          m_throttle = ENEMY_SPACE_SHIP_ACCELERATION_QUANTA;
        }
        else
        {
          m_throttle = 0;
        }
        m_shooting = false;
      }
      else
      {
        m_shooting = true;
        if(speed.length() < 5)
        {
          m_throttle = ENEMY_SPACE_SHIP_ACCELERATION_QUANTA;
        }
        else if(speed.length() > 20)
        {
          m_throttle = -ENEMY_SPACE_SHIP_DECELERATION_QUANTA;
        }
        else
        {
          m_throttle = 0;
        }
      }
    }
    else // if( targetDistance < 30 )
    {
      m_shooting = true;
      m_throttle = -ENEMY_SPACE_SHIP_DECELERATION_QUANTA;
    }

    break;

  case STRATEGY_KAMIKAZE:
  default:
    //Fuzzy logic controller !
    if( abs(deltaAngle) > ENEMY_SPACE_SHIP_ROTATION_SPEED )
    {
      if( deltaAngle < 0 )
        angle = (angle - ENEMY_SPACE_SHIP_ROTATION_SPEED)%360 ;
      else //if( deltaAngle > 0)
        angle = (angle + ENEMY_SPACE_SHIP_ROTATION_SPEED)%360 ;
    }
    else
    {
      angle = targetAngle;
    }

    //Recompute delta angle
    deltaAngle = targetAngle - angle;
    while(deltaAngle>180)
      deltaAngle-=360;
    while(deltaAngle<=-180)
      deltaAngle+=360;

    if( abs(deltaAngle) < 30 )
    {
      m_throttle = ENEMY_SPACE_SHIP_ACCELERATION_QUANTA;
    }
    else if( abs(deltaAngle) > 90 )
    {
      if(QVector2D::dotProduct(speed, targetVector) <0)
      {
        m_throttle = ENEMY_SPACE_SHIP_ACCELERATION_QUANTA;
      }
      else
      {
        if(speed.length() < 5)
        {
          m_throttle = 0;
        }
        else
        {
          m_throttle = -ENEMY_SPACE_SHIP_DECELERATION_QUANTA;
        }
      }
    }
    else
    {
      m_throttle = 0;
    }

    break;
  }

  SpaceShip::updatePosition(timeElapsed);
}

void EnemySpaceShip::updateBehaviour(float timeElapsed, GameEngine * theGameEngine)
{
    updateShooting(theGameEngine);
    updatePosition(timeElapsed);
}

void EnemySpaceShip::updateShooting(GameEngine * theGameEngine)
{
  if(m_strategy == STRATEGY_KAMIKAZE)
    return; //Won't shoot



    // We check if the ship is able to fire, according it's shooting rate.
    // If it's not the case, we increment the counter until it's ok
    if(!m_readyToFire){
        m_cooldownTimer++;
        if(m_cooldownTimer==m_shootingRate){
            m_readyToFire = true;
            m_cooldownTimer = 0;
        }
    }
    if(m_readyToFire && m_shooting)
    {
        m_readyToFire = 0 ;
        float currentAngle = DEG_TO_RAD*this->getOrientation();
        QPoint currentPosition = this->getPosition();
        theGameEngine->addGameObject(( theGameEngine->getBulletFactory())->create(
                                                                                            currentPosition + QPoint(-10*sin(currentAngle) -10*cos(currentAngle), 10*cos(currentAngle)-10*sin(currentAngle)), // position of the first bullet
                                                                                            QVector2D(0,0), // acceleration of the bullet
                                                                                            BULLET_SPEED_LIMIT*QVector2D(sin(currentAngle),-cos(currentAngle)) ,//speed of the bullet
                                                                                            QSize(5,5), // size of the bullet hitbox
                                                                                            1, // mass of the bullet
                                                                                            theGameEngine->getDifficultyLevel(), //difficultyLevel
                                                                                            QString("enemy") // type of the bullet
                                                                                              ) );
        theGameEngine->addGameObject(( theGameEngine->getBulletFactory())->create(
                                                                                            currentPosition + QPoint(-10*sin(currentAngle) +10*cos(currentAngle), 10*cos(currentAngle)+10*sin(currentAngle)), // position of the first bullet
                                                                                            QVector2D(0,0), // acceleration of the bullet
                                                                                            BULLET_SPEED_LIMIT*QVector2D(sin(currentAngle),-cos(currentAngle)) ,//speed of the bullet
                                                                                            QSize(5,5), // size of the bullet hitbox
                                                                                            1, // mass of the bullet
                                                                                            theGameEngine->getDifficultyLevel(), //difficultyLevel
                                                                                            QString("enemy") // type of the bullet
                                                                                              ) );
    }
}
