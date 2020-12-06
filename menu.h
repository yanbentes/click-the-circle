#ifndef MENU_H
#define MENU_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>

class Menu : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Menu(QString name, QGraphicsItem *parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

private:
    QGraphicsTextItem *buttonText;
};

#endif // MENU_H
