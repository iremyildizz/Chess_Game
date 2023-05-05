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
		if (button->getPiece() != nullptr && isTurnOfPiece(button->getPiece()->getTeam())) {
			chosenPiece_ = button->getPiece();
			chosenCase_ = button;
			chosenCase_->changeColor(selectedCase);
			filter();
			for (std::shared_ptr<ChessCase> button : possibleCases_) {
				button->changeColor(possibleCaseYellow);
				if (button->getColour() == casePink) {
					button->changeColor(possibleCasePink);
				}
				if (button->getPiece() != nullptr) {
					button->changeColor(possiblePawnYellow);
					if (button->getColour() == casePink) {
						button->changeColor(possiblePawnPink);
					}
				}		
			}
		}
	}
	else {
		for(std::shared_ptr<ChessCase> bttn : possibleCases_){
			if (chosenPiece_ != button->getPiece() && button == bttn.get() && !chosenPiece_->isSameTeam(button->getPiece())) {
				button->setPiece(chosenPiece_);
				if (std::shared_ptr<Pawn> piece = std::dynamic_pointer_cast<Pawn>(chosenPiece_)) {
					piece->setFirstMove(true);
				}
				chosenCase_->deletePiece();
				isPinkTurn = !isPinkTurn;
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
	for (int i = 0; i < possibleCases_.size(); i++) {
		if ((possibleCases_[i]->getPiece() == nullptr && possibleCases_[i]->getY() != chosenPiece_->getY()) || (possibleCases_[i]->getPiece() != nullptr && possibleCases_[i]->getY() == chosenPiece_->getY())) {
			possibleCases_.erase(possibleCases_.begin() + i);
			i--;
		}		
	}
}

void Controller::filter() {
	if (chosenPiece_->getType() == "Knight")
		knightFilter();
	else
		obstacleFilter_();
	if (chosenPiece_->getType() == "Pawn")
		pawnFilter();

	selfCheckFilter_();
}

bool Controller::isTurnOfPiece(Team team) {
	return (isPinkTurn && team == Team::Pink) || (!isPinkTurn && team == Team::Lilac);
}

void Controller::selfCheckFilter_() {
	std::shared_ptr<PieceAbs> memoryPiece = nullptr;
	chosenCase_->deletePiece();
	for (std::shared_ptr<ChessCase> button : possibleCases_) {
		memoryPiece = button->deletePiece();
		button->setPiece(chosenPiece_);
		//verification
		button->deletePiece();
	}
	chosenCase_->setPiece(chosenPiece_);
}
