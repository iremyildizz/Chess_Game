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
			filter(chosenPiece_,possibleCases_);
			selfCheckFilter_();
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

void Controller::obstacleFilter_(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases) {
	for (int x = piece->getX() - 1; x >= 0; x--)
		if (filterAdder_(x, piece->getY(), piece, possibleCases))
			break;

	for (int x = piece->getX() + 1; x < grid_->getHeight(); x++)
		if (filterAdder_(x, piece->getY(), piece, possibleCases))
			break;

	for (int y = piece->getY() + 1; y < grid_->getLenght(); y++)
		if (filterAdder_(piece->getX(), y, piece, possibleCases))
			break;

	for (int y = piece->getY() - 1; y >= 0; y--)
		if (filterAdder_(piece->getX(), y, piece, possibleCases))
			break;

	int count = 1;
	while ((piece->getX() + count != grid_->getLenght()) && (piece->getY() + count != grid_->getLenght())) {
		if (filterAdder_(piece->getX() + count, piece->getY() + count, piece, possibleCases))
			break;
		count += 1;
	}

	count = 1;
	while ((piece->getX() + count != grid_->getLenght()) && (piece->getY() - count >= 0)) {
		if (filterAdder_(piece->getX() + count, piece->getY() - count, piece, possibleCases))
			break;
		count += 1;
	}
	count = 1;
	while ((piece->getX() - count >= 0) && (piece->getY() - count >= 0)) {
		if (filterAdder_(piece->getX() - count, piece->getY() - count, piece, possibleCases))
			break;
		count += 1;
	}
	count = 1;
	while ((piece->getX() - count >= 0) && (piece->getY() + count != grid_->getLenght())) {
		if (filterAdder_(piece->getX() - count, piece->getY() + count, piece, possibleCases))
			break;
		count += 1;
	}
}

bool Controller::filterAdder_(int x, int y, std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases) {
	if (piece->isValidMove(x, y)) {
		if (grid_->findCase(x, y)->getPiece() != nullptr) {
			if ((grid_->findCase(x, y)->getPiece()->getTeam() == piece->getTeam()))
				return true;
			possibleCases.push_back(grid_->findCase(x, y));
			return true;
		}
		possibleCases.push_back(grid_->findCase(x, y));
		return false;
	}
}

void Controller::knightFilter(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases) {
	for (auto line : grid_->getListOfCases()) {
		for (std::shared_ptr<ChessCase> button : line) {
			filterAdder_(button->getX(), button->getY(), piece, possibleCases);
		}
	}
}
void Controller::pawnFilter(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases) {
	for (int i = 0; i < possibleCases.size(); i++) {
		if ((possibleCases[i]->getPiece() == nullptr && possibleCases[i]->getY() != piece->getY()) || (possibleCases[i]->getPiece() != nullptr && possibleCases[i]->getY() == piece->getY())) {
			possibleCases.erase(possibleCases.begin() + i);
			i--;
		}		
	}
}

void Controller::filter(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases) {
	if (piece->getType() == "Knight")
		knightFilter(piece, possibleCases);
	else
		obstacleFilter_(piece, possibleCases);
	if (piece->getType() == "Pawn")
		pawnFilter(piece, possibleCases);
}

bool Controller::isTurnOfPiece(Team team) {
	return (isPinkTurn && team == Team::Pink) || (!isPinkTurn && team == Team::Lilac);
}

void Controller::selfCheckFilter_() {
	std::shared_ptr<PieceAbs> memoryPiece = nullptr;
	chosenCase_->deletePiece();
	for (int i = 0; i < possibleCases_.size(); i++) {
		memoryPiece = possibleCases_[i]->deletePiece();
		possibleCases_[i]->setPiece(chosenPiece_);

		bool isKingChecked = false;
		for (auto line : grid_->getListOfCases()) {
			for (std::shared_ptr<ChessCase> button : line) {
				if (button->getPiece() != nullptr && button->getPiece()->getTeam() != chosenPiece_->getTeam()) {
					std::vector<std::shared_ptr<ChessCase>> possibleCasesOfPiece;
					filter(button->getPiece(), possibleCasesOfPiece);
					for (std::shared_ptr<ChessCase> possibleButton : possibleCasesOfPiece) {
						if (possibleButton->getPiece() != nullptr && possibleButton->getPiece()->getType() == "King") {
							isKingChecked = true;
							break;
						}
					}
				}
				if (isKingChecked)
					break;
			}
			if (isKingChecked)
				break;
		}



		possibleCases_[i]->deletePiece();
		possibleCases_[i]->setPiece(memoryPiece);
		if (isKingChecked) {
			possibleCases_.erase(possibleCases_.begin() + i);
			i--;
		}
	}
	chosenCase_->setPiece(chosenPiece_);
}
