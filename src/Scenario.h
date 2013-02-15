#ifndef SCENARIO_H_
#define SCENARIO_H_

#include "GameEngine.h"
#include "GameObject.h"

//!Scenario : This  abstract class contains the level design

/*! This class encapsulates the level design. It tells the GameEngine
    to add new ennemies to the level, and to manage events such as
    game overs */
class Scenario
{
public:
  Scenario(GameEngine* pGameEngine);
  virtual ~Scenario();

  virtual void initialize(int difficultyLevel) = 0; //!< sets the initial objects in the game
  virtual void update(float timeElapsed) = 0; //!< regularly adds ennemies
  virtual void destroyed(GameObject* pObject) = 0; //!< notifies destruction of objects
  virtual void gameOver() = 0;//!< manages the Game Over
  void registerGE(GameEngine* pGameEngine) ;//!< sets the reference to the game engine

protected:
  GameEngine* m_pGameEngine; //!< internal reference to the gameengine
  int m_difficultyLevel ;//!< difficulty level


private:

};

#endif /* SCENARIO_H_ */
