#include "ChessCase.h"
#include "Controller.h"

ChessCase::ChessCase(int newX, int newY, std::shared_ptr<Controller> controller, QWidget* parent): x_(newX), y_(newY), controller_(controller), QPushButton(parent) {
    const QSize BUTTON_SIZE = QSize(lenght_, height_);
    setIconSize(QSize(lenght_, height_));
    setMinimumSize(BUTTON_SIZE);
    setMaximumSize(BUTTON_SIZE);
    connect(this, SIGNAL(clicked()), this, SLOT(handleButton()));
    //setText(QString(QString::number(x_)) + "," + (QString::number(y_)));
}

void ChessCase::setPiece(std::shared_ptr<PieceAbs> piece) {
    piece_ = piece;
    setIcon(QIcon(piece_->getIcon()));
    /*piece->setPos(x_, y_);*/
}
int ChessCase::getX() { return x_; }
int ChessCase::getY() { return y_; }

void ChessCase::handleButton() {
    /*std::shared_ptr<ChessCase> selfPtr(this);
    controller_->click(selfPtr);*/
}

std::shared_ptr<PieceAbs> ChessCase::getPiece() {
    return piece_;
}

void ChessCase::deletePiece() {
    setIcon(QIcon(""));
    piece_ = nullptr;
}