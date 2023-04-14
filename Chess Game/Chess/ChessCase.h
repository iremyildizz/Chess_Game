#pragma once
#include <QPushButton>
#include <Qsize>
#include <memory>
#include "Piece.h"

class Controller;
class ChessCase : public QPushButton {
	Q_OBJECT
public:
	ChessCase(int newX, int newY, std::shared_ptr<Controller> controller, QWidget* parent = nullptr);
	ChessCase() = default;
	~ChessCase() = default;
	void setPiece(std::shared_ptr<PieceAbs> piece);
	void deletePiece();
	int getX();
	int getY();
	std::shared_ptr<PieceAbs> getPiece();

public slots:
	void handleButton();

private:
	int x_;
	int y_;
	const int lenght_ = 90;
	const int height_ = 90;
	std::shared_ptr<PieceAbs> piece_ = nullptr;
	std::shared_ptr<Controller> controller_ = nullptr;
};