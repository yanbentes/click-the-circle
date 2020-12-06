#include "game.h"

Game::Game(QWidget *parent)
{
    //set screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(800, 600);

    //set scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    scene->setBackgroundBrush(QBrush(Qt::black));
    setScene(scene);
}

void Game::displayMenu()
{
    scene->clear();

    //game title
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("Click Game"));
    QFont titleFont("times", 32);
    title->setFont(titleFont);
    title->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2 - title->boundingRect().width()/2;
    int tyPos = this->height()/8;
    title->setPos(txPos,tyPos);
    scene->addItem(title);

    //play button (jogar)
    Menu *playButton = new Menu(QString("Jogar"));
    int pxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 240;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //configurations button (configurações)
    Menu *configButton = new Menu(QString("Configurações"));
    int cxPos = this->width()/2 - configButton ->boundingRect().width()/2;
    int cyPos = 330;
    configButton->setPos(cxPos,cyPos);
    connect(configButton ,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(configButton);

    //quit button (sair)
    Menu *quitButton = new Menu(QString("Sair"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 420;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::start()
{
    //clearing menu scene
    scene->clear();

    //create score
    score = new Score();
    scene->addItem(score);

    //create game time
    time = new Tempo();
    scene->addItem(time);
    QTimer *t = new QTimer();
    connect(t,SIGNAL(timeout()), time,SLOT(decrease()));
    t->start(1000);

    //create circle
    Circle *circle = new Circle();
    scene->addItem(circle);

    //game end when time = 0s;
    connect(time,SIGNAL(stop()), this,SLOT(end()));
}

void Game::end()
{
    scene->clear();

    //score
    QGraphicsTextItem *gameScore = new QGraphicsTextItem(QString("Score: ") + QString::number(score->getScore()));
    QFont scoreFont("times", 24);
    gameScore->setFont(scoreFont);
    gameScore->setDefaultTextColor(Qt::white);
    int gxPos = this->width()/2 - gameScore->boundingRect().width()/2;
    int gyPos = this->height()/8;
    gameScore->setPos(gxPos,gyPos);
    scene->addItem(gameScore);

    //targets hit
    QGraphicsTextItem *targets = new QGraphicsTextItem(QString("Targets hit: ") + QString::number(score->getTargets()));
    QFont targetsFont("times", 24);
    targets->setFont(targetsFont);
    targets->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2 - targets->boundingRect().width()/2;
    int tyPos = this->height()/4;
    targets->setPos(txPos,tyPos);
    scene->addItem(targets);

    //restart button (reiniciar)
    Menu *restartButton = new Menu(QString("Reiniciar"));
    int rxPos = this->width()/2 - restartButton->boundingRect().width()/2;
    int ryPos = 240;
    restartButton->setPos(rxPos,ryPos);
    connect(restartButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(restartButton);

    //menu button
    Menu *menuButton = new Menu(QString("Menu"));
    int mxPos = this->width()/2 - menuButton->boundingRect().width()/2;
    int myPos = 330;
    menuButton->setPos(mxPos,myPos);
    connect(menuButton,SIGNAL(clicked()),this,SLOT(displayMenu()));
    scene->addItem(menuButton);
}


