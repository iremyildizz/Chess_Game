/**
* Chess Game.
* \file   Controller.cpp
* \author Irem Yildiz
* \date   5 mai 2023
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
	if (chosenPiece_ == nullptr) {
		if (hasPieceAndIsHisTurn_(button)) {
			firstClickEvent_(button);
		}
	}
	else {
		secondClickEvent_(button);
	}
}

bool Controller::hasPieceAndIsHisTurn_(ChessCase* button) {
	return button->getPiece() != nullptr && isTurnOfPiece_(button->getPiece()->getTeam());
}

void Controller::firstClickEvent_(ChessCase* button) {
	chosenPiece_ = button->getPiece();
	chosenCase_ = button;
	chosenCase_->changeColor(selectedCase);

	filter_(chosenPiece_, possibleCases_);
	selfCheckFilter_(chosenPiece_, chosenCase_, possibleCases_);
	possibleCasesColorChangeFirstClick_();
}
void Controller::possibleCasesColorChangeFirstClick_() {
	for (std::shared_ptr<ChessCase> button : possibleCases_) {
		button->changeColor(possibleCaseYellow);
		if (button->getColour() == casePink) 
			button->changeColor(possibleCasePink);

		if (button->getPiece() != nullptr) {
			button->changeColor(possiblePawnYellow);
			if (button->getColour() == casePink) 
				button->changeColor(possiblePawnPink);
		}
	}
}

void Controller::secondClickEvent_(ChessCase* button) {
	for (std::shared_ptr<ChessCase> bttn : possibleCases_) {
		if (isSameButtonAndPieceIsNotSameTeam_(button, bttn)) {
			button->setPiece(chosenPiece_);

			if (std::shared_ptr<Pawn> piece = std::dynamic_pointer_cast<Pawn>(chosenPiece_))
				piece->setFirstMove(true);

			chosenCase_->deletePiece();

			verifyCheckmate_();

			isPinkTurn_ = !isPinkTurn_;
			break;
		}
	}

	resetClickState_();
}

bool Controller::isSameButtonAndPieceIsNotSameTeam_(ChessCase* clickedButton, std::shared_ptr<ChessCase> possibleCaseButton) {
	return chosenPiece_ != clickedButton->getPiece() && clickedButton == possibleCaseButton.get() && !chosenPiece_->isSameTeam(clickedButton->getPiece());
}

void Controller::verifyCheckmate_() {
	bool isKingChecked = false;
	if (isPinkTurn_)
		isKingChecked = kingChecked_(Team::Lilac);
	else
		isKingChecked = kingChecked_(Team::Pink);

	if (isKingChecked) {
		if (isCheckMate_()) {
			QMessageBox msgBox;
			msgBox.setText("Checkmate!");
			msgBox.setStyleSheet("background-color:rgba(221, 195, 248, 0.3);");
			msgBox.exec();
		}
	}
}

bool Controller::isCheckMate_() {
	for (auto line : grid_->getListOfCases()) {
		for (std::shared_ptr<ChessCase> button : line) {
			if (hasPieceNotInTeam_(button, chosenPiece_->getTeam())) {
				std::vector<std::shared_ptr<ChessCase>> possibleCasesOfPiece;
				filter_(button->getPiece(), possibleCasesOfPiece);
				selfCheckFilter_(button->getPiece(), button.get(), possibleCasesOfPiece);
				if (!possibleCasesOfPiece.empty())
					return false;
			}
		}
	}
	return true;
}

bool Controller::hasPieceNotInTeam_(std::shared_ptr<ChessCase> button, Team team) {
	return button->getPiece() != nullptr && button->getPiece()->getTeam() != team;
}

void Controller::resetClickState_() {
	chosenCase_->changeToBaseColour();
	chosenPiece_ = nullptr;
	chosenCase_ = nullptr;
	for (std::shared_ptr<ChessCase> button : possibleCases_) {
		button->changeToBaseColour();
	}
	possibleCases_.clear();
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

void Controller::knightFilter_(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases) {
	for (auto line : grid_->getListOfCases()) {
		for (std::shared_ptr<ChessCase> button : line) {
			filterAdder_(button->getX(), button->getY(), piece, possibleCases);
		}
	}
}
void Controller::pawnFilter_(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases) {
	for (int i = 0; i < possibleCases.size(); i++) {
		if (dontRespectPawnRules_(possibleCases[i], piece)) {
			possibleCases.erase(possibleCases.begin() + i);
			i--;
		}		
	}
}

bool Controller::dontRespectPawnRules_(std::shared_ptr<ChessCase> button, std::shared_ptr<PieceAbs> piece) {
	return (button->getPiece() == nullptr && button->getY() != piece->getY()) || (button->getPiece() != nullptr && button->getY() == piece->getY());
}

void Controller::filter_(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases) {
	if (piece->getType() == "Knight")
		knightFilter_(piece, possibleCases);
	else
		obstacleFilter_(piece, possibleCases);
	if (piece->getType() == "Pawn")
		pawnFilter_(piece, possibleCases);
}

bool Controller::isTurnOfPiece_(Team team) {
	return (isPinkTurn_ && team == Team::Pink) || (!isPinkTurn_ && team == Team::Lilac);
}

void Controller::selfCheckFilter_(std::shared_ptr<PieceAbs> piece, ChessCase* button, std::vector<std::shared_ptr<ChessCase>>& possibleCases) {
	std::shared_ptr<PieceAbs> memoryPiece = nullptr;
	button->deletePiece();
	for (int i = 0; i < possibleCases.size(); i++) {
		memoryPiece = possibleCases[i]->deletePiece();
		possibleCases[i]->setPiece(piece);

		bool isKingChecked = kingChecked_(piece->getTeam());
		
		possibleCases[i]->deletePiece();
		possibleCases[i]->setPiece(memoryPiece);
		if (isKingChecked) {
			possibleCases.erase(possibleCases.begin() + i);
			i--;
		}
	}
	button->setPiece(piece);
}

bool Controller::kingChecked_(Team team) {
	for (auto line : grid_->getListOfCases()) {
		for (std::shared_ptr<ChessCase> button : line) {
			if (hasPieceNotInTeam_(button, team)) {
				std::vector<std::shared_ptr<ChessCase>> possibleCasesOfPiece;
				filter_(button->getPiece(), possibleCasesOfPiece);
				for (std::shared_ptr<ChessCase> possibleButton : possibleCasesOfPiece) {
					if (possibleButton->getPiece() != nullptr && possibleButton->getPiece()->getType() == "King") {
						return true;
					}
				}
			}
		}
	}
}

void Controller::setTurn(bool isPinkTurn) {
	isPinkTurn_ = isPinkTurn;
}
