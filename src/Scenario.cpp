#include "Scenario.h"

Scenario::Scenario(GameEngine* pGameEngine) : m_pGameEngine(pGameEngine)
{

}

Scenario::~Scenario()
{

}

void Scenario::registerGE(GameEngine* pGameEngine)
{
   pGameEngine->registerScenario(this);
}
