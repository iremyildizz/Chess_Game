#include "Piece.h"

PieceAbs::PieceAbs(Team team, int x, int y) : team_(team), x_(x), y_(y){}

QString PieceAbs::getIcon() {
	return icon_;
}

int PieceAbs::getX() { return x_; }
int PieceAbs::getY() { return y_; }
void PieceAbs::setPos(int newX, int newY) { x_ = newX; y_ = newY; }

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