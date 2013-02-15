#ifndef SCENARIODEMOLEVEL_H_
#define SCENARIODEMOLEVEL_H_

#include <list>

#include "Scenario.h"

#include "GameObject.h"
#include "PlayerSpaceShip.h"
#include "EnemySpaceShip.h"
#include "Potatoes.h"

#include "PlayerSpaceShipFactory.h"
#include "EnemySpaceShipFactory.h"
#include "PotatoesFactory.h"

class ScenarioDemoLevel : public Scenario
{
public:
  ScenarioDemoLevel(GameEngine* pGameEngine);
  virtual ~ScenarioDemoLevel();

  virtual void initialize(int difficultyLevel);
  virtual void update(float timeElapsed);
  virtual void destroyed(GameObject* pObject);
  virtual void gameOver();

private:
  void cleanup();
  void getRandomPosition(QPoint* pPos, QVector2D* pSpeed, unsigned int speedMagnitude, const QSize& size);

  PlayerSpaceShip* m_pPlayerSpaceShip;

  //A few lists of Game Objects
  std::list<GameObject*> m_lpKamikazesEnemySpaceShips;
  std::list<GameObject*> m_lpAttaquersEnemySpaceShips;
  std::list<GameObject*> m_lpPotatoes;

  //Factories
  PlayerSpaceShipFactory m_PSSFactory;
  EnemySpaceShipFactory m_ESSFactory;
  PotatoesFactory m_PFactory;

  int m_kamikasesNumber ;
  int m_kamikasesLeft;
  int m_attaquerNumber ;
  int m_attaquersLeft;

  int m_playerSpaceShipShootingRate ;
  int m_playerSpaceShipHP ;
  int m_ennemySpaceShipShootingRate ;
  int m_ennemySpaceShipHP ;


  float m_nextPotato;
  float m_kamikasesCoolDown ;
  float m_attaquersCoolDown ;
};

#endif /* SCENARIODEMOLEVEL_H_ */
