#include "score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //m_score = 0;
    //targets = 0;
    //setPos(375, 10);
    setPlainText(QString::number(m_score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",14));
}

void Score::increase()
{
    m_score += 1000;
    targets++;
    setPlainText(QString::number(m_score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",14));
}

int Score::getScore()
{
    return m_score;
}

int Score::getTargets()
{
    return targets;
}
