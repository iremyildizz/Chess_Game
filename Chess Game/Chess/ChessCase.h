#pragma once
#include <QPushButton>
#include <Qsize>
#include <memory>
#include "Piece.h"

class ChessCase : public QPushButton {
public:
	ChessCase(int newX, int newY, QWidget* parent = nullptr);
	~ChessCase() = default;
	void setPiece(std::unique_ptr<PieceAbs> piece);

private:
	int x_;
	int y_;
	const int lenght_ = 90;
	const int height_ = 90;
	std::unique_ptr<PieceAbs> piece_ = nullptr;
};