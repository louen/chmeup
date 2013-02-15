#include "PotatoesFactory.h"

GameObject * PotatoesFactory::create(QPoint pos_a, QVector2D speed_a, QSize hitbox_a){
  Potatoes * patate = new Potatoes(pos_a,speed_a,hitbox_a) ;
  patate->setAnimation(new AnimatedPotatoes(patate));
  patate->setFrictionCoef(POTATOES_FRICTION_COEF);
  patate->setMaxSpeed(POTATOES_SPEED_LIMIT);
  return patate;
}

GameObject * PotatoesFactory::create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a)
{
    //not to be called
    return this->create(pos_a, speed_a, hitbox_a);
}

GameObject * PotatoesFactory::create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a, QString model_a)
{
    //not to be called
    return this->create(pos_a, speed_a, hitbox_a);
}
