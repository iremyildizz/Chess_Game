#include "Controller.h"

Controller::Controller() {

}
Controller::~Controller() {
	delete chosenCase_;
}

void Controller::click(ChessCase* button) {
	if (button->getPiece() != nullptr) {
		chosenPiece_ = button->getPiece();
		chosenCase_ = button;
	}
	else {
		button->setPiece(chosenPiece_);
		chosenCase_->deletePiece();
	}
}