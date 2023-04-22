/**
* Chess Game.
* \file   Controller.cpp
* \author Irem Yildiz
* \date   14 avril 2023
* Créé le 10 avril 2023
*/

#include "Controller.h"
#include <qmessagebox.h>
using namespace colors;

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
			chosenCase_->changeColor(selectedCase);
			filter();
			for (std::shared_ptr<ChessCase> button : possibleCases_) {
				button->changeColor(possibleCaseYellow);
				if (button->getColour() == casePink) {
					button->changeColor(possibleCasePink);
				}	
			}
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

void Controller::obstacleFilter_() {
	for (int x = chosenPiece_->getX() - 1; x >= 0; x--)
		if (filterAdder_(x, chosenPiece_->getY())) 
			break;

	for (int x = chosenPiece_->getX() + 1; x < grid_->getHeight(); x++)
		if (filterAdder_(x, chosenPiece_->getY())) 
			break;

	for (int y = chosenPiece_->getY() + 1; y < grid_->getLenght(); y++)
		if (filterAdder_(chosenPiece_->getX(), y))
			break;

	for (int y = chosenPiece_->getY() - 1; y >= 0; y--)
		if (filterAdder_(chosenPiece_->getX(), y))
			break;

	int count = 1;
	while ((chosenPiece_->getX() + count != grid_->getLenght()) && (chosenPiece_->getY() + count != grid_->getLenght())) {
		if (filterAdder_(chosenPiece_->getX() + count, chosenPiece_->getY() + count))
			break;
		count += 1;
	}

	count = 1;
	while ((chosenPiece_->getX() + count != grid_->getLenght()) && (chosenPiece_->getY() - count >= 0)) {
		if (filterAdder_(chosenPiece_->getX() + count, chosenPiece_->getY() - count))
			break;
		count += 1;
	}
	count = 1;
	while ((chosenPiece_->getX() - count >= 0) && (chosenPiece_->getY() - count >= 0)) {
		if (filterAdder_(chosenPiece_->getX() - count, chosenPiece_->getY() - count))
			break;
		count += 1;
	}
	count = 1;
	while ((chosenPiece_->getX() - count >= 0) && (chosenPiece_->getY() + count != grid_->getLenght())) {
		if (filterAdder_(chosenPiece_->getX() - count, chosenPiece_->getY() + count))
			break;
		count += 1;
	}
}

bool Controller::filterAdder_(int x, int y) {
	if (chosenPiece_->isValidMove(x, y)) {
		if (grid_->findCase(x, y)->getPiece() != nullptr) {
			if ((grid_->findCase(x, y)->getPiece()->getTeam() == chosenPiece_->getTeam()))
				return true;
			possibleCases_.push_back(grid_->findCase(x, y));
			return true;
		}
		possibleCases_.push_back(grid_->findCase(x, y));
		return false;
	}
}

void Controller::knightFilter() {
	for (auto line : grid_->getListOfCases()) {
		for (std::shared_ptr<ChessCase> button : line) {
			filterAdder_(button->getX(), button->getY());
		}
	}
}
void Controller::pawnFilter() {
	for (auto line : grid_->getListOfCases()) {
		for (std::shared_ptr<ChessCase> button : line) {

		}
	}
}

void Controller::filter() {
	if (chosenPiece_->getType() == "Knight") {
		knightFilter();
	}
	else if (chosenPiece_->getType() == "Pawn") {
		obstacleFilter_();

	}
	else {
		obstacleFilter_();
	}
}
