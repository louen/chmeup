#include "BulletFactory.h"

// TODO : put the common code in a function (Don't Repeat Yourself -- Louen)


GameObject * BulletFactory::create(QPoint pos_a, QVector2D acceleration_a, QVector2D speed_a, QSize hitbox_a, int mass, int difficultyLevel_a){
  Bullet * bullet = new Bullet(pos_a,acceleration_a,speed_a,hitbox_a,mass) ;
  bullet->setAnimation(new AnimatedBullet("player",bullet));
  bullet->setFrictionCoef(BULLET_FRICTION_COEF);
  bullet->setMaxSpeed(BULLET_SPEED_LIMIT);
  bullet->setDamage(BULLET_DAMAGE) ;
  bullet->setPlayerId(1); // defaults to player id
  return bullet;
}

GameObject * BulletFactory::create(QPoint pos_a, QVector2D acceleration_a, QVector2D speed_a, QSize hitbox_a, int mass, int difficultyLevel_a, QString model_a){
  Bullet * bullet = new Bullet(pos_a,acceleration_a,speed_a,hitbox_a,mass) ;
  bullet->setAnimation(new AnimatedBullet(model_a,bullet));
  bullet->setFrictionCoef(BULLET_FRICTION_COEF);
  bullet->setMaxSpeed(BULLET_SPEED_LIMIT) ;
  bullet->setDamage(BULLET_DAMAGE);
  if (model_a == "enemy")
    bullet->setPlayerId(0);
  else if (model_a == "player")
    bullet->setPlayerId(1);
  return bullet;
}

