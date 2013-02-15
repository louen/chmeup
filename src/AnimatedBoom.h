#ifndef ANIMATEDBOOM_H
#define ANIMATEDBOOM_H

#include "AnimatedObject.h"
#include "Boom.h"
//! AnimatedBoom : class representing a sprite for Boom.
/*!
This class specialises AnimatedObject to represent the sprite for an explosion.
*/
class AnimatedBoom : public AnimatedObject
{

protected:
    int timer;//!< number of frames left to the explosion

public:
    AnimatedBoom(GameObject* parent_a);//!< constructor
    bool decreaseTimer();//!< decreases the lifespan of the explosion
    virtual QGraphicsItem* getCurrentSprite(); //!< returns the sprite
};

#endif // ANIMATEDBOOM_H
