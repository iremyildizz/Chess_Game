#include "Piece.h"
#include <cmath>

PieceAbs::PieceAbs(Team team, int x, int y) : team_(team), x_(x), y_(y){}

QString PieceAbs::getIcon() {
	return icon_;
}

int PieceAbs::getX() { return x_; }
int PieceAbs::getY() { return y_; }
void PieceAbs::setPos(int newX, int newY) { x_ = newX; y_ = newY; }
bool PieceAbs::isValidMove(int x, int y) { return true; }

King::King(Team team, int x, int y): PieceAbs(team, x, y) {
	if (team == Team::Pink) {
		name_ = "Pink King";
		icon_ = "./images/King_Black.png";
	}
	else {
		name_ = "White King";
		icon_ = "./images/King_White.png";
	}
	
}

bool King::isValidMove(int x, int y) { 
	return ((x <= x_ + 1 && x >= x_ - 1) && (y <= y_ + 1 && y >= y_ - 1)); 
}

Bishop::Bishop(Team team, int x, int y) : PieceAbs(team, x, y) {
	if (team == Team::Pink) {
		name_ = "Pink Bishop";
		icon_ = "./images/Bishop_Black.png";
	}
	else {
		name_ = "White Bishop";
		icon_ = "./images/Bishop_White.png";
	}

}
bool Bishop::isValidMove(int x, int y) { 
	return (std::abs(x - x_) == std::abs(y - y_));
}

Rook::Rook(Team team, int x, int y) : PieceAbs(team, x, y) {
	if (team == Team::Pink) {
		name_ = "Pink Rook";
		icon_ = "./images/Rook_Black.png";
	}
	else {
		name_ = "White Rook";
		icon_ = "./images/Rook_White.png";
	}

}

bool Rook::isValidMove(int x, int y) {
	return(x_ == x || y_ == y);
}
