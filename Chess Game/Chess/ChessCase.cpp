#include "ChessCase.h"

ChessCase::ChessCase(int newX, int newY, QWidget* parent): x_(newX), y_(newY), QPushButton(parent) {
    const QSize BUTTON_SIZE = QSize(lenght_, height_);
    setIconSize(QSize(lenght_, height_));
    setMinimumSize(BUTTON_SIZE);
    setMaximumSize(BUTTON_SIZE);
    //setText(QString(QString::number(x_)) + "," + (QString::number(y_)));
    //setIcon(QIcon("./images/King_White.png"));
}

void ChessCase::setPiece(std::unique_ptr<PieceAbs> piece) {
    piece_ = std::move(piece);
    setIcon(QIcon(piece_->getIcon()));
}
int ChessCase::getX() { return x_; }
int ChessCase::getY() { return y_; }