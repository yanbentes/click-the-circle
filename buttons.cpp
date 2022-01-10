#include "buttons.h"

Buttons::Buttons(QString name, QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    //menu buttons layout
    setRect(0, 0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    buttonText = new QGraphicsTextItem(name, this);
    buttonText->setDefaultTextColor(Qt::white);
    buttonText->setFont(QFont("times", 14));

    int xPos = rect().width()/2 - buttonText->boundingRect().width()/2;
    int yPos = rect().height()/2 - buttonText->boundingRect().height()/2;
    buttonText->setPos(xPos,yPos);

    //button sound
    //buttonSound = new QMediaPlayer();
    //buttonSound->setMedia(QUrl("qrc:/sounds/button2.mp3"));

    setAcceptHoverEvents(true);
}

void Buttons::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Buttons::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBrush(brush);
}

void Buttons::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);
}
