#include "BoomFactory.h"

GameObject * BoomFactory::create(QPoint pos_a)
{
    Boom* boomer = new Boom(pos_a);
    boomer->setAnimation(new AnimatedBoom(boomer));
    return boomer;
}


GameObject * BoomFactory::create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a)
{
    Boom* boomer = new Boom(pos_a);
    boomer->setAnimation(new AnimatedBoom(boomer));
    return boomer;
}

GameObject * BoomFactory::create(QPoint pos_a, QVector2D acceleration , QVector2D speed_a, QSize hitbox_a, int mass_a, int difficultyLevel_a, QString model_a)
{
    Boom* boomer = new Boom(pos_a);
    boomer->setAnimation(new AnimatedBoom(boomer));
    return boomer;
}
