#include "Chess.h"
#include <QtWidgets/QApplication>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include "ChessGrid.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chess w;

    std::unique_ptr<ChessGrid> chessGrid = std::make_unique<ChessGrid>();
    

    // Create a widget
    QWidget* widget = new QWidget();

    // Set the grid layout as a main layout
    widget->setLayout(chessGrid.get());

    // Window title
    widget->setWindowTitle("Chess Game");

    widget->show();
    return a.exec();
}
