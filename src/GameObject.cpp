#include "GameObject.h"
#include "AnimatedObject.h"
#include "displaymodel.h"

extern int screenWidthGlobal;
extern int screenHeightGlobal;

GameObject::GameObject(QPoint pos_a, QVector2D acceleration_a , QVector2D speed_a, QSize hitbox_a, int mass_a) :
position(pos_a), speed(speed_a), acceleration(acceleration_a) , mass(mass_a),angle(0), hitBox(hitbox_a), m_hasToBeDeleted(false)
{
    animation = NULL;
}

GameObject::~GameObject()
{
  delete animation;
}

// getters & setters ----------------------------------------------------------

QGraphicsItem * GameObject::getAnimation() const
{
  if(animation && !display_model)
    return animation->getCurrentSprite();
  else
  {
    QGraphicsRectItem * rect = new QGraphicsRectItem(this->getModelRect()) ;
    rect->setBrush(objBrush);
    return rect;
  }
}

float GameObject::getFrictionCoef() const
{
   return frictionCoef ;
}

QRectF GameObject::getHitRect() const
{
  QRectF result = QRectF(QPointF(position.x() - hitBox.width()/2, position.y() - hitBox.height()/2), hitBox) ;
  return result ;
}

int GameObject::getMass() const
{
  return mass;
}

int GameObject::getMaxSpeed() const
{
    return m_maxSpeed ;
}

QRectF GameObject::getModelRect() const
{
  return QRectF(QPointF(-hitBox.width()/2,-hitBox.height()/2),hitBox) ;
}

int GameObject::getOrientation() const
{
  return angle ;
}

QPoint GameObject::getPosition() const
{
    return position.toPoint() ;
}

QVector2D GameObject::getSpeed() const
{
   return speed ;
}

void GameObject::setAnimation(AnimatedObject * animation_a)
{
  animation = animation_a ;
}

void GameObject::setFrictionCoef(float coeff)
{
   frictionCoef = coeff ;
}

void GameObject::setMaxSpeed(int maxSpeed)
{
    m_maxSpeed = maxSpeed ;
}

void GameObject::setOrientation(int angle_a)
{
  angle = angle_a ;
}

// game-related methods -------------------------------------------------------

//Default implementation
void GameObject::updatePosition(float timeElapsed)
{
  //For each frame, compute the new speed and position regarding the acceleration value
  //and the time elapsed since the last computation

  //Compute new position, with speed threshold, to avoid shaking effect of the sprite on low speeds

    QVector2D tempSpeed = speed ;
    if(abs(tempSpeed.x())<=4)
        tempSpeed.setX(0);
    if(abs(tempSpeed.y())<=4)
        tempSpeed.setY(0);
    position += (tempSpeed*timeElapsed + (1/2)*acceleration*timeElapsed*timeElapsed).toPointF();

  //Compute new speed, with frictional resistance (typically 0.995)  FIXME : the game seems laggy with a coeff friction...
  speed = frictionCoef*speed + acceleration*timeElapsed;
  if(speed.length()>=m_maxSpeed)
      speed = m_maxSpeed*speed.normalized();


  //Adjust position with the window borders
  //WARN: Modulus operator does not work for floats
  position.setX( position.x() - (float)((int)(position.x()/screenWidthGlobal))*screenWidthGlobal );
  if(position.x()<0)
    position.setX(position.x() + (float)screenWidthGlobal) ;

  position.setY( position.y() - (float)((int)(position.y()/screenHeightGlobal))*screenHeightGlobal );
  if(position.y()<0)
    position.setY(position.y() + (float)screenHeightGlobal);

  //Donatien: Is there a nicer way to saturate speed and acceleration?
  //Same values for every objects or a configurable one?
}

bool GameObject::hasToBeDeleted() const
{
    return m_hasToBeDeleted ;
}

void GameObject::needToBeDeleted(bool on)
{
    m_hasToBeDeleted = on ;
}

GameObject* GameObject::destruct(BoomFactory* theBoomFactory)
{
  return NULL;
  // notify GUI to launch the destruction animation"
  // notify the game engine that it has been destroyed, so it is removed from the list
}

