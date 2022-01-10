#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QMediaPlayer>

#include "circle.h"
#include "buttons.h"
#include "score.h"
#include "tempo.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent=NULL);

    QGraphicsScene *scene;
    Score *score;
    Tempo *time;

public slots:
    void displayMenu();
    void start();
    void end();
};

#endif // GAME_H
