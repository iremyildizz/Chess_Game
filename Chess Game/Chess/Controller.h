#pragma once
#include "Piece.h"
#include "ChessGrid.h"
#include <memory>

struct Colours {
	const QString casePink = "rgba(255, 182, 193, 1)";
	const QString caseYellow = "rgba(255, 250, 240, 1)";
	const QString selectedCase = "rgba(218, 112, 214, 1)";
};

class Controller {
public:
	Controller();
	~Controller();
	void click(ChessCase* button);

private:
	std::shared_ptr<PieceAbs> chosenPiece_ = nullptr;
	ChessCase* chosenCase_ = nullptr;
};