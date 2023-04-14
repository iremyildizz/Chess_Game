#pragma once
#include "Piece.h"
#include "ChessGrid.h"
#include <memory>

class Controller {
public:
	Controller();
	~Controller();
	void click(ChessCase* button);

private:
	std::shared_ptr<PieceAbs> chosenPiece_ = nullptr;
	ChessCase* chosenCase_ = nullptr;
};