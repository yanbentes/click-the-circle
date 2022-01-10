#include "game.h"

#include <QApplication>

Game *game; //game global variable

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //change cursor style
    QApplication::setOverrideCursor(Qt::CrossCursor);

    game = new Game();
    game->displayMenu();
    game->show();

    return a.exec();
}
