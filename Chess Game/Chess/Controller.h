/**
* Chess Game.
* \file   Controller.h
* \author Irem Yildiz
* \date   5 mai 2023
* Créé le 10 avril 2023
*/

#pragma once
#include "Piece.h"
#include "ChessGrid.h"
#include <memory>

namespace colors {
	const QString casePink = "rgba(247, 202, 201, 1)";
	const QString caseYellow = "rgba(255, 255, 240, 1)";
	const QString selectedCase = "rgba(83, 66, 92, 1)";
	const QString possibleCase = "rgba(192, 165, 209, 1)";
	const QString possibleCasePink = "rgba(192, 165, 209, 1)";
	const QString possibleCaseYellow = "rgba(222, 190, 240, 1)";
	const QString possiblePawnPink = "rgba(73, 187, 193, 1)";
	const QString possiblePawnYellow = "rgba(73, 187, 193, 0.5)";
}

class Controller {
public:
	Controller();
	~Controller();
	void click(ChessCase* button);
	void setGrid(std::shared_ptr<ChessGrid> grid);
	void setTurn(bool);
	
private:
	bool hasPieceAndIsHisTurn_(ChessCase* button);
	void firstClickEvent_(ChessCase* button);
	void possibleCasesColorChangeFirstClick_();
	void secondClickEvent_(ChessCase* button);
	bool isSameButtonAndPieceIsNotSameTeam_(ChessCase* clickedButton, std::shared_ptr<ChessCase> possibleCaseButton);
	void verifyCheckmate_();
	bool isCheckMate_();
	bool hasPieceNotInTeam_(std::shared_ptr<ChessCase> button, Team team);
	void resetClickState_();
	void knightFilter_(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases);
	void pawnFilter_(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases);
	bool dontRespectPawnRules_(std::shared_ptr<ChessCase> button, std::shared_ptr<PieceAbs> piece);
	void filter_(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases);
	void obstacleFilter_(std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases);
	void selfCheckFilter_(std::shared_ptr<PieceAbs> piece, ChessCase* button, std::vector<std::shared_ptr<ChessCase>>& possibleCases);
	bool filterAdder_(int x, int y, std::shared_ptr<PieceAbs> piece, std::vector<std::shared_ptr<ChessCase>>& possibleCases);
	bool isTurnOfPiece_(Team team);
	bool kingChecked_(Team team);

	std::shared_ptr<PieceAbs> chosenPiece_ = nullptr;
	ChessCase* chosenCase_ = nullptr;
	std::shared_ptr<ChessGrid> grid_ = nullptr;
	std::vector<std::shared_ptr<ChessCase>> possibleCases_;
	bool isPinkTurn_ = true;
};