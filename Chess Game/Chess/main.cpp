/**
* Chess Game.
* \file   main.cpp
* \author Irem Yildiz
* \date   5 mai 2023
* Créé le 10 avril 2023
*/

#include "Chess.h"
#include <QtWidgets/QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chess w;
    w.startGame();
    w.getWindow()->show();
    return a.exec();
}
