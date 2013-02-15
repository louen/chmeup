#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <vector>

#include <QObject>
#include <QTimer>

#include "GameObject.h"
#include "KeyPressedFrame.h"
#include "BulletFactory.h"
#include "Scenario.h"
#include "BoomFactory.h"

//forward declarations
class CollisionDetector ;
class CollisionSolver ;
class PlayerSpaceShip ;
class Scenario ;
//! GameEngine : a class holding and processing the game state

/*! This class represents the game engine as a whole. It maintains a reference to all the GameObjects,
    activates their functions on schedule. It holds a timer trigerring the process() function at a
    frequency determined by the FRAME_RATE constant. This function subsequently goes through each
    step of the game rules. It also holds a reference to a scenario generating items into
    the game engine according to the level design
*/
class GameEngine : public QObject
{
  Q_OBJECT

  protected:
    BoomFactory* theBoomFactory;
    int framesPlayed ;//!< not yet implemented
    int level; //!< not yet implemented
    int difficultyLevel; //!< not yet implemented
    std::vector<GameObject * > gameObjects; //!< the list of all current GameObjects in the game space
    PlayerSpaceShip * playerSpaceShip ; //!< shortcut to the player's ship  one day we will allow several players...
    CollisionDetector * collisionDetector ;//!< collision detector
    CollisionSolver * collisionSolver ; //!< collision solver
    QTimer * timer ; //!< Timer sending a signal at each new frame
    BulletFactory * theBulletFactory ; //!< Creating bullet, useful when ships are shooting.
    Scenario * scenario ; //!< Scenario telling the game engine to add new ennemies...

  public:
    GameEngine() ;
    ~GameEngine() ;

    const std::vector<GameObject * >& getGameObjects() const; //!< getter for the GameObjects list
    PlayerSpaceShip * getPlayerSpaceShip() const ; //!< getter for the player's ship
    void addGameObject(GameObject* object);//!< add a gameObject to the list
    void addPlayerSpaceShip(PlayerSpaceShip * PSS) ;//!< add the player's space ship
    int getPlayerSpaceShipHP() const; //!< returns the player's space ship HP

    BulletFactory * getBulletFactory() const; //!< return the bullet factory (used the ships to create new Bullets)

    void deleteGameObjects(); //!< deletes all the pointers
    void setDifficultyLevel(int level) ; //!< Accessor for difficulty level
    int getDifficultyLevel() const; //!< Accessor for difficulty level
    void start() ;//!< Starts the game engine
    void process() ; //!< main processing of the game state
    void endGame(bool victory) ; //!< end the current game
    void registerScenario(Scenario * currentScenario); // registerthe currrent scenario

  signals:
    void updateUI(); //!< tells the UI to update its display
    void requestKeyUI() ;//!<request keyFrame from UI
    void displayGameOverScreen(); //// Display the Game Over Screen
    void displayGameWonScreen(); //// Display the Game Won Screen

  protected slots :
    void getKeyFrame(KeyPressedFrame * kf);//!< accepts a KeyPressedFrame with the keys pressed by the player
    void nextFrame(); //!< listens to the timer's
    void stop();//!< Stops the game engine
  public slots:
    void pause() ;//!< pauses the game

};
#endif// GAME_ENGINE_H
