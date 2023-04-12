#include "ChessCase.h"

ChessCase::ChessCase(int newX, int newY, QWidget* parent): x_(newX), y_(newY), QPushButton(parent) {
    const QSize BUTTON_SIZE = QSize(lenght_, height_);
    setMinimumSize(BUTTON_SIZE);
    setMaximumSize(BUTTON_SIZE);
}