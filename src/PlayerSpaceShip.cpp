#include "PlayerSpaceShip.h"
#include "GameEngine.h"
#include "constants.h"

PlayerSpaceShip::PlayerSpaceShip(QPoint position, QVector2D acceleration , QVector2D speed, QSize hitBox, int mass, int playerId, int shootingRate) :
SpaceShip(position, acceleration ,speed, hitBox, mass, playerId, shootingRate)
{
}


void PlayerSpaceShip::keyUp() {
   incThrottle();
}
void PlayerSpaceShip::keyDown() {
  decThrottle() ;
}

void PlayerSpaceShip::keyUpDownRelease()
{
  rlsThrottle();
}

void PlayerSpaceShip::keyLeft() {
    decAngle();
}
void PlayerSpaceShip::keyRight() {
    incAngle();
}

void PlayerSpaceShip::incThrottle(){
  m_throttle = PLAYER_SPACE_SHIP_ACCELERATION_QUANTA ;
}
void PlayerSpaceShip::decThrottle(){
  m_throttle = - PLAYER_SPACE_SHIP_DECELERATION_QUANTA ;
}
void PlayerSpaceShip::rlsThrottle(){
  m_throttle = 0;
}
void PlayerSpaceShip::incAngle(){
   angle = (angle + PLAYER_SPACE_SHIP_ROTATION_SPEED)%360 ;
}

void PlayerSpaceShip::decAngle(){
   angle = (angle - PLAYER_SPACE_SHIP_ROTATION_SPEED + 360)%360 ;
}

void PlayerSpaceShip::updateBehaviour(float timeElapsed, GameEngine * theGameEngine)
{
    updateShooting(theGameEngine);
    updatePosition(timeElapsed);
}

void PlayerSpaceShip::updatePosition(float timeElapsed)
{
    SpaceShip::updatePosition(timeElapsed);
}

void PlayerSpaceShip::updateShooting(GameEngine * theGameEngine)
{
    // We check if the ship is able to fire, according it's shooting rate.
    // If it's not the case, we increment the counter until it's ok
    // Shouldn't this code be merged in SpaceShip (duplicate code in EnnemySpaceShip) -- Louen
    if(!m_readyToFire){
        m_cooldownTimer++;
        if(m_cooldownTimer == m_shootingRate){
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
                                                                                  QString("player") // type of the bullet
                                                                                    ) );
        theGameEngine->addGameObject(( theGameEngine->getBulletFactory())->create(
                                                                                  currentPosition + QPoint(-10*sin(currentAngle) +10*cos(currentAngle), 10*cos(currentAngle)+10*sin(currentAngle)), // position of the first bullet
                                                                                  QVector2D(0,0), // acceleration of the bullet
                                                                                  BULLET_SPEED_LIMIT*QVector2D(sin(currentAngle),-cos(currentAngle)) ,//speed of the bullet
                                                                                  QSize(5,5), // size of the bullet hitbox
                                                                                  1, // mass of the bullet
                                                                                  theGameEngine->getDifficultyLevel(), //difficultyLevel
                                                                                  QString("player") // type of the bullet
                                                                                    ) );

    }
}


