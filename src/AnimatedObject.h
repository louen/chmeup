#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

#include <QString>
#include <QBrush>
#include <QGraphicsItem>
#include "GameObject.h"

class GameObject;
//! AnimatedObject : class abstracting the sprite of a GameObject.
/*! This abstract class is used for animation and rendering of the GameObject sprites.
It returns a QGraphicsItem for the rendering engine (QGraphicsScene) to display it
It manages the centering of the coordinates of the sprite
*/
class AnimatedObject
{
  protected :
    QString spriteName;//!< Base file name of the sprite
    GameObject* parent;//!< GameObject represented by this sprite
    QGraphicsPixmapItem* centeredPixmap(QPixmap pixmap_a); //!< png sprite loaded in memory

  public:
    AnimatedObject(QString spriteName_a, GameObject* parent_a); //!<Basic constructor
    virtual QGraphicsItem* getCurrentSprite() = 0; //!< Returns the sprite in QGraphicsItem to be displayed in the QGraphicsScene
};

#endif // ANIMATEDOBJECT_H
