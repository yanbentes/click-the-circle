#ifndef TEMPO_H
#define TEMPO_H

#include <QGraphicsTextItem>
#include <QFont>

class Tempo : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Tempo(QGraphicsItem *parent=NULL);
    int getTime();

signals:
    void stop();

public slots:
    void decrease();

private:
    int m_time;
};

#endif // TEMPO_H
