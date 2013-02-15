#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include "GameObjectCollision.h"
//! Bullet : A bullet emitted by a SpaceShip.

/*! This class represents a Bullet emitted by a SpaceShip's weapon. Bullets do not
cross borders of the screen, unlike other GameObjects. They are destroyed on any
collision, causing damage to other ships than their emitter
*/
class Bullet: public GameObject
{
  protected :
    int m_damage ;//!< Damage inflicted by the bullet
    int m_playerId ;//!< ID of the owner of the ship which fired the bullet

  public :

    Bullet(QPoint position, QVector2D acceleration, QVector2D speed, QSize hitbox, int mass) ;//!< constructor
    virtual ~Bullet() {};
    void setDamage(int d) ;//!< setter for the damage
    int getDamage() const ; //!< getter for the damage
    void setPlayerId(int id); //!< setter for the owner's Id
    int getPlayerId() const ; //!< getter for the owner's Id

    virtual void updateBehaviour(float timeElapsed, GameEngine * theGameEngine);//!< Implements the correct behavior for the bullets
    virtual void accept(GameObjectCollision * visitor) ; //!< Receive a collision event to send it its real class
    virtual GameObjectCollision * getCollision()  ; //!< Return a BulletCollision for the CollisionSolver
};
#endif// BULLET_H
