/**
* Chess Game.
* \file   ChessGrid.cpp
* \author Irem Yildiz
* \date   14 avril 2023
* Créé le 10 avril 2023
*/

#include "ChessGrid.h"
#include "Controller.h"

Colours c; 
ChessGrid::ChessGrid(std::shared_ptr<Controller> controller, QWidget* parent) :controller_(controller), QGridLayout(parent) {
    setSizeConstraint(QLayout::SetMinAndMaxSize);
    init();
    setHorizontalSpacing(0);
    setVerticalSpacing(0);
};

void ChessGrid::init() {
    for (int i = 0; i < lenght_; i++) {
        for (int j = 0; j < height_; j++) {
            std::shared_ptr<ChessCase> button = std::make_shared<ChessCase>(i, j, controller_);
            button->setBaseColour(c.casePink);

            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    button->setBaseColour(c.caseYellow);
                }
            }
            else {
                if (j % 2 != 0) {
                    button->setBaseColour(c.caseYellow);

                }
            }
            button->changeToBaseColour();
            addWidget(button.get(), i, j, 1, 1);
            listOfCases_.push_back(button);
        }
    }
}
void ChessGrid::addPieces(std::vector<std::shared_ptr<PieceAbs>> pieces) {
    for (std::shared_ptr<PieceAbs>& piece : pieces) {
        for (std::shared_ptr<ChessCase>& chessCase: listOfCases_) {
            if (piece->getX() == chessCase->getX() && piece->getY() == chessCase->getY()) {
                chessCase->setPiece(piece);
                listOfPieces_.push_back(piece);
                break;
            }
        }
    }
}
std::vector<std::shared_ptr<ChessCase>> ChessGrid::getListOfCases() { return listOfCases_; }