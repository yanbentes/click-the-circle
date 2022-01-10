#ifndef BUTTONS_H
#define BUTTONS_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QBrush>
#include <QFont>

class Buttons : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Buttons(QString name, QGraphicsItem *parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

private:
    QGraphicsTextItem *buttonText;
    //QMediaPlayer *buttonSound;

};

#endif // BUTTONS_H
