#include "AnimatedObject.h"
#include <QGraphicsPixmapItem>

AnimatedObject::AnimatedObject(QString spriteName_a, GameObject* parent_a) : spriteName(spriteName_a), parent(parent_a)
{
}

QGraphicsPixmapItem* AnimatedObject::centeredPixmap(QPixmap pixmap_a)
{
    QGraphicsPixmapItem* sprite =  new QGraphicsPixmapItem;
    sprite->setPixmap(pixmap_a);
    sprite->setOffset(-0.5*QPointF(pixmap_a.size().width(), pixmap_a.size().height()));
    return sprite;
}
