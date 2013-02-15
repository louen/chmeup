#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <QPoint>
#include <QVector2D>
#include <QSize>
#include <QRect>
#include <QGraphicsItem>
#include <math.h>
#include "constants.h"

class AnimatedObject;
class GameEngine ;
class GameObjectCollision ;
class BoomFactory;
//! GameObject : generic class managed by the GameEngine
/*! This abstract class is the main class of the game engine. All objects floating
into the game space are GameObjects, and seen as such by the GameEngine.
It stores mass, coordinates and speed (but subclasses usually implement their
own physics rules (like maximum speed) depending on their type).
The interface also specifies methods for the Visitor pattern implemented by
GameObjectCollision. GameObject owns an AnimatedObject to represent its sprite.
*/

class GameObject
{

  protected :
    // members ----------------------------------------------------------------
    QPointF position ; //!< coordinates in floating point accuracy
    QVector2D speed ; //!< speed vector
    QVector2D acceleration ; //! < acceleration vector
    int mass ; //!< mass of the object, used in inertia computations
    int angle;//!< orientation of the object, in degrees
    QSize hitBox ; //!< the hit box is the rectangled checked agains other object's hitboxes for collisions
    AnimatedObject * animation ;//!< pointer to the sprite object
    float frictionCoef ;//!< slowing process is governed by this parameter
    bool m_hasToBeDeleted ;//!< flag indicating to the game engine that it should be removed
    int m_maxSpeed ; //!< maximum speed


  public:
    // constuctors & destructors ----------------------------------------------
    GameObject(QPoint pos_a, QVector2D acceleration_a , QVector2D speed_a, QSize hitbox_a, int mass_a);
    virtual ~GameObject();

    // getters & setters ------------------------------------------------------
    QGraphicsItem *getAnimation() const; //!< getter for the sprite. Return a default rectangle if no sprite is defined.
    float getFrictionCoef() const ;//!< getter for the friction parameter
    QRectF getHitRect() const ;//!< getter for the hitbox with coordinates offset
    int getMass() const ; //!< getter for the mass
    int getMaxSpeed() const ;//!< getter for the maximum speed
    QRectF getModelRect() const;//!< getter for the hitbowx with no offset
    int getOrientation() const ;//!< getter for the angle
    QPoint getPosition() const; //!< getter for the position (conversion from floating-point to integer coordinates)
    QVector2D getSpeed() const ;//!< getter for the speed
    bool hasToBeDeleted() const ;//!<getter for the deletion flag

    void setAnimation(AnimatedObject * animation_a); //!<setter for the sprite object
    void setFrictionCoef(float coeff); //!< setter for the friction parameter
    void setMaxSpeed(int maxSpeed) ;//!< setter for the maximum speed
    void setOrientation(int angle); //!< setter for the angle in degrees

    // game related methods ---------------------------------------------------
    virtual void updatePosition(float timeElapsed);
    void needToBeDeleted(bool on); //!< toggles flag to be sweeped by the game engine
    virtual GameObject* destruct(BoomFactory* theBoomFactory) ; //!< called when the object is destroyed
    // pure virtual
    virtual void updateBehaviour(float timeElapsed, GameEngine * theGameEngine) = 0 ; //!< genric processing of behavior. includes position, shooting, etc.
    virtual void accept(GameObjectCollision * visitor) = 0 ;//!< Receive a collision event to send it its real class
    virtual GameObjectCollision * getCollision() = 0 ;//!< return a specialised GameObjectCollision version for the CollisionSolver
};

#endif// GAME_OBJECT_H