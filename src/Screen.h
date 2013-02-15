#include "GameEngine.h"

#include <QGraphicsView>
#include <QBrush>
//! Screen : the game's screen
/*! Screen implements the QGraphicsView. At each frame, it redraws the sprites
of all GameObjects (using their getAnimation() method) at their current position
*/
class Screen : public QGraphicsView
{
  public :
    Screen(QWidget * parent = NULL);
    virtual ~Screen() ;

    void gameOverScreen(); //!< display the Game Over Screen
    void gameWonScreen(); //!< display the Game Won Screen
    void update(GameEngine *  const game);//!< Takes the game engine state and displays the positions of objects
  protected:
    QGraphicsScene * scene; //!< The scene where objects are displayed
    QGraphicsTextItem * HPCounter ; //!< The HP counter displayed
};
