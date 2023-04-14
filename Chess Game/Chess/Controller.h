#pragma once
#include "Piece.h"
#include "ChessGrid.h"
#include <memory>

class Controller {
public:
	Controller();
	~Controller() = default;
	void click(std::shared_ptr<ChessCase> button);

private:
	std::shared_ptr<PieceAbs> chosenPiece_ = nullptr;
	std::shared_ptr<ChessCase> chosenCase_ = nullptr;
};