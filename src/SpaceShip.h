#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include "GameObject.h"

class GameEngine ;
//! SpaceShip : a ship cruising trough space
/*! This abstract class is the base class for all ships (player's and opponents) in the game
    It is mainly responsible of getting the physics right according to the propelling
    engines's force currrent value, and to take care of emitting bullets when the ship
    is shooting.
*/
class SpaceShip : public GameObject
{
  public:
    SpaceShip(QPoint position, QVector2D acceleration, QVector2D speed, QSize hitBox, int mass, int playerId, int shootingRate);

    void setThrottle(int throttle); //!<setter for Acceleration
    int getThrottle() const ;//!< getter for acceleration

    void setShooting(bool on); //!<Activate/Desactivate the shooting
    bool getShooting() const;//!<gets the shooting state
    void setShootingRate(int shootingRate) ;//!<sets the shooting rate

    int getHP()const;//!< getter for the HP
    void setHP(int HPNubmer);//!< setter for the HP
    int getPlayerId() const;//!< getter for the ship's owner ID
    void takeDamage(int damage); //!< decrease HP
    void heal(int hp) ; //!< increase HP

    virtual GameObject* destruct(BoomFactory* theBoomFactory) ;//!< start the explosion
    virtual void accept(GameObjectCollision * visitor) ;//!< Receive a collision event to send it its real class
    virtual GameObjectCollision * getCollision() ;//!< Return a SpaceShipCollision for the CollisionSolver

  protected:
    int m_playerId ; //!< Player ID :  0 for ennemies, 1,2,... for players
    int m_HP ;//!< Health points of the ship
    int m_throttle; //!< acceleration
    int m_shootingRate;//!< number of frames between 2 shots
    bool m_readyToFire ;//!< flag to allow shooting
    int m_cooldownTimer ;//!< counter of frames between the shots
    bool m_shooting;//!< flag to tell if shooting is enabled or not

    virtual void updateBehaviour(float timeElapsed, GameEngine * theGameEngine)=0;//!< Implements the correct behavior for the bullets
    virtual void updatePosition(float timeElapsed);//!<update the position according to physics of the asteorid

};
#endif /* SPACESHIP_H_ */
