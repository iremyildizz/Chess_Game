#include "Piece.h"

PieceAbs::PieceAbs(Team team, int x, int y) : team_(team), x_(x), y_(y){}

QString PieceAbs::getIcon() {
	return icon_;
}

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