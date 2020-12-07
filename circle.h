#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QRandomGenerator>
#include <QBrush>

#include "game.h"

class Circle : public QGraphicsEllipseItem
{
public:
    Circle(QGraphicsItem *parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected:
    float circleSize;
    float xPos, yPos;
    QBrush circleColor;
    QMediaPlayer *clickSound;
};

#endif // CIRCLE_H
