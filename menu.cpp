#include "menu.h"

Menu::Menu(QString name, QGraphicsItem *parent) : QGraphicsRectItem(parent)
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

    setAcceptHoverEvents(true);
}

void Menu::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Menu::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBrush(brush);
}

void Menu::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);
}
