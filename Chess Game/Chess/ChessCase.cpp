#include "ChessCase.h"

ChessCase::ChessCase(QWidget* parent): QPushButton(parent) {
    const QSize BUTTON_SIZE = QSize(lenght_, height_);
    setMinimumSize(BUTTON_SIZE);
    setMaximumSize(BUTTON_SIZE);


}