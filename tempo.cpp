#include "tempo.h"

Tempo::Tempo(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    m_time = 30;
    setPos(375, 0);
    setPlainText(QString::number(m_time) + QString(" s"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Tempo::decrease()
{
    m_time--;
    setPos(375, 0);
    setPlainText(QString::number(m_time) + QString(" s"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));

    if(m_time == 0){
        emit stop();
    }
}

int Tempo::getTime()
{
    return m_time;
}
