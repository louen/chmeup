#ifndef ANIMATEDPOTATOES_H
#define ANIMATEDPOTATOES_H
#include "AnimatedObject.h"
//! AnimatedPotatoes : class representing a sprite for Potatoes.
/*!
* This class specialises AnimatedObject to represent the sprite for an asteroid.
*/
class AnimatedPotatoes : public AnimatedObject
{

  public:
    AnimatedPotatoes(GameObject* parent_a);//!< Constructor
    virtual QGraphicsItem* getCurrentSprite();//!< Returns the sprite in QGraphicsItem to display
};

#endif // ANIMATEDPOTATOES_H
