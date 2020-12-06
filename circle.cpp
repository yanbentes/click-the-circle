#include "circle.h"

extern Game * game;

Circle::Circle(QGraphicsItem *parent)
{
    //circle size, position and color
    circleColor = QBrush(Qt::yellow);
    circleSize = 50;
    xPos = 375;
    yPos = 250;

    //setting circle color and position on the screen
    this->setPen(Qt::NoPen);
    this->setBrush(circleColor);
    this->setRect(QRect(xPos, yPos, circleSize, circleSize));
}

void Circle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     //generanting random sizes and positions for the circle
     quint32 circleSize = QRandomGenerator::global()->bounded(15, 60);
     quint32 xPos = QRandomGenerator::global()->bounded(100, 700);
     quint32 yPos = QRandomGenerator::global()->bounded(100, 500);

    this->setRect(QRect(xPos, yPos, circleSize, circleSize));

    game->score->increase();
}


