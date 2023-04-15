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
				if(button.get() != chosenCase_ && chosenPiece_->isValidMove(button->getX(), button->getY())) {
					button->changeColor(colour.possibleCase);
					possibleCases_.push_back(button);
				}
			}
			//add filters
		}
	}
	else {
		for(std::shared_ptr<ChessCase> bttn : possibleCases_){
			if (chosenPiece_ != button->getPiece() && button == bttn.get() && !chosenPiece_->isSameTeam(button->getPiece())) {
				button->setPiece(chosenPiece_);
				chosenCase_->deletePiece();
				break;
			}
		}
		
		chosenCase_->changeToBaseColour();
		chosenPiece_ = nullptr;
		chosenCase_ = nullptr;
		for (std::shared_ptr<ChessCase> button : possibleCases_) {
			button->changeToBaseColour();
		}
		possibleCases_.clear();
	}
}
void Controller::setGrid(std::shared_ptr<ChessGrid> grid) { grid_ = grid; }