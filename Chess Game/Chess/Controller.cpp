#include "Controller.h"

Colours colour;
Controller::Controller() {

}
Controller::~Controller() {
	delete chosenCase_;
}

void Controller::click(ChessCase* button) {
	if(chosenPiece_ == nullptr) {
		if (button->getPiece() != nullptr) {
			chosenPiece_ = button->getPiece();
			chosenCase_ = button;
			chosenCase_->changeColor(colour.selectedCase);
			for (std::shared_ptr<ChessCase> button : grid_->getListOfCases()) {
				if(button.get() != chosenCase_ && chosenPiece_->isValidMove(button->getX(), button->getY()))
					button->changeColor(colour.possibleCase);
			}
		}
	}
	else {
		if(chosenPiece_ != button->getPiece()){
			button->setPiece(chosenPiece_);
			chosenCase_->deletePiece();
			chosenCase_->changeToBaseColour();
			chosenPiece_ = nullptr;
			chosenCase_ = nullptr;
			for (std::shared_ptr<ChessCase> button : grid_->getListOfCases()) {
				button->changeToBaseColour();
			}
		}
	}
}
void Controller::setGrid(std::shared_ptr<ChessGrid> grid) { grid_ = grid; }