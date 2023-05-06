#pragma once
#include <QPushButton>
#include <Qsize>
/**
* Chess Game.
* \file   ChessCase.h
* \author Irem Yildiz
* \date   5 mai 2023
* Créé le 10 avril 2023
*/

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
	std::shared_ptr<PieceAbs> deletePiece();
	int getX();
	int getY();
	std::shared_ptr<PieceAbs> getPiece();
	void changeColor(QString colour);
	void setBaseColour(QString colour);
	void changeToBaseColour();
	QString getColour();

public slots:
	void handleButton();

private:
	int x_;
	int y_;
	const int lenght_ = 90;
	const int height_ = 90;
	const int iconLenght_ = lenght_ - 15;
	const int iconHeight_ = height_ - 15;
	std::shared_ptr<PieceAbs> piece_ = nullptr;
	std::shared_ptr<Controller> controller_ = nullptr;
	QString colour_;
};