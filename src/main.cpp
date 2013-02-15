#include <QApplication>
#include "MainWindow.h"
#include "GameEngine.h"
#include "SpaceShip.h" // test
#include "PlayerSpaceShipFactory.h"
#include "EnemySpaceShipFactory.h"
#include "ScenarioDemoLevel.h"

#include "PlayerSpaceShip.h"
#include <QPoint>
bool display_model ;

/*!
\mainpage Chmeup Documentation
<p>Chmeup is a 2D asteroids-like shoot-them up. You control a spaceship in space, and your
goal is to survive against attacks of ennemy ships and drifting asteroids. It is built with
the Qt toolkit, and therefore can be used on any platform supporting it.</p>
<h2>Getting chmeup</h2>
<p> You can get chmeup in several platforms
<ul>
<li> <a href="#">Windows version</a></li>
<li> <a href="#">Linux version</a> (You will need Qt4 libraries on your system)</li>
<li> <a href="#">Get the source</a> (You will need Qt4 developpement libraries and tools &mdash; qmake and the like &mdash; to compile)</li>
</ul>

<p>You can also get the latest snapshot of the code with subersion at URL
<a href="http://svn.palouf.org/chmeup/trunk">http://svn.palouf.org/chmeup/trunk</a></p>

<h2>Controls</h2>
<p>You control the ship's speed with keys Z (accelerate) and S (deccelerate / move back).
You can turn the ship left with Q or right with D and shoot with the space bar.
By pressing P, you toggle the pause on or off.
<h2>Health points</h2>
<p>Your ship has a health point (HP) counter which decreases each time you are hit. When it
reaches 0, your ship is destroyed and the game is over.</p>

*/

int screenWidthGlobal = 600 ;
int screenHeightGlobal = 600;

int main (int argc, char ** argv)
{
  QApplication myApp(argc,argv);
  myApp.setApplicationName("chmeup");

  GameEngine theGameEngine ;
  ScenarioDemoLevel theScenario(&theGameEngine);

  MainWindow theMainWindow(&theGameEngine);

  QLocale localConfig =  myApp.keyboardInputLocale() ;
  theMainWindow.setLocalConfig(&localConfig);

  theMainWindow.show();

  display_model = false ;

  return myApp.exec();
}
