/**
* Chess Game.
* \file   Controller.h
* \author Irem Yildiz
* \date   14 avril 2023
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
	void knightFilter();
	void pawnFilter();
	void filter();

private:
	void obstacleFilter_();
	bool filterAdder_(int x, int y);
	std::shared_ptr<PieceAbs> chosenPiece_ = nullptr;
	ChessCase* chosenCase_ = nullptr;
	std::shared_ptr<ChessGrid> grid_ = nullptr;
	std::vector<std::shared_ptr<ChessCase>> possibleCases_;
};