#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent=NULL);
    void increase();
    int getScore();
    int getTargets();

private:
    int m_score=0;
    int targets=0;
};

#endif // SCORE_H
