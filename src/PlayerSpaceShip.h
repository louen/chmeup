#ifndef PLAYER_SPACE_SHIP_H
#define PLAYER_SPACE_SHIP_H

#include "SpaceShip.h"
#include <QObject>

class GameEngine ;
//! PlayerSpaceShip : the ship controlled by the player
/*! This class specializes SpaceShip to be controlled by a human player. It is driven
    by the pressed keys relayed by the game engine.
 */
class PlayerSpaceShip :public QObject, public SpaceShip
{
  Q_OBJECT
  public:
    //! constructor
    PlayerSpaceShip(QPoint position, QVector2D acceleration, QVector2D speed, QSize hitBox, int mass,int playerId, int shootingRate);
    void updateBehaviour(float timeElapsed, GameEngine * theGameEngine);//!< updates position, shooting rate ,etc.

  public  :
    void keyDown(); //!< action to take when the down key is pressed
    void keyUp() ;//!< action to take when the up key is pressed
    void keyUpDownRelease() ;//!< action to take when the up or key is released
    void keyLeft() ;//!< action to take when the left key is pressed
    void keyRight() ;//!< action to take when the right key is pressed

    void incThrottle() ;  //!<Set the propelling force with a positive quanta
    void decThrottle() ;  //!<Set the propelling force with a negative quanta
    void rlsThrottle() ;  //!<Set the propelling force with a null quanta
    void incAngle() ;  //!<Increment the angle orientation with an angle quanta
    void decAngle() ;  //!<Decrement the angle orientation with an angle quanta

protected :
  void updateShooting(GameEngine * theGameEngine);//!< updates the shooting state of the ship
  virtual void updatePosition(float timeElapsed);//!< physics movement processing

};
#endif// PLAYER_SPACE_SHIP_H
