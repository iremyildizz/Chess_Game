#include "Chess.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "ChessGrid.h"
#include "Game.h"
#include "ChessCase.h"
#include "Controller.h"
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chess w;
    Game game;
    std::shared_ptr<Controller> controller = std::make_shared<Controller>();
    std::shared_ptr<ChessGrid> chessGrid = std::make_shared<ChessGrid>(controller);
    chessGrid->addPieces(game.test1());


    // Create a widget
    QWidget* widget = new QWidget();
    // Set the grid layout as a main layout
    widget->setLayout(chessGrid.get());
    // Window title
    widget->setWindowTitle("Chess Game");

    widget->show();
    return a.exec();
}
