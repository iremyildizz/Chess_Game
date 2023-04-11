#include "ChessGrid.h"

ChessGrid::ChessGrid(QWidget* parent) : QGridLayout(parent) {
    init();
};

void ChessGrid::init() {
    for (int i = 0; i < lenght_; i++) {
        for (int j = 0; j < height_; j++) {
            std::shared_ptr<ChessCase> button = std::make_shared<ChessCase>();
            button->setStyleSheet("background-color: rgba(255,182,193,100)");
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    button->setStyleSheet("background-color: rgba(255,250,240,100)");
                }
            }
            else {
                if (j % 2 != 0) {
                    button->setStyleSheet("background-color: rgba(255,250,240,100)");
                }
            }

            addWidget(button.get(), i, j, 1, 1);
            listOfCases_.push_back(button);
        }
    }
}