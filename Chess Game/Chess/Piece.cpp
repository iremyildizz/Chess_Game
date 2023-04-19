/**
* Chess Game.
* \file   Piece.cpp
* \author Irem Yildiz
* \date   14 avril 2023
* Créé le 10 avril 2023
*/

#include "Piece.h"
#include <cmath>

using namespace icons;

PieceAbs::PieceAbs(Team team, int x, int y) : team_(team), x_(x), y_(y){}

QString PieceAbs::getIcon() {
	return icon_;
}

int PieceAbs::getX() { return x_; }
int PieceAbs::getY() { return y_; }
void PieceAbs::setPos(int newX, int newY) { x_ = newX; y_ = newY; }
bool PieceAbs::isValidMove(int x, int y) { return true; }
bool PieceAbs::isSameTeam(std::shared_ptr<PieceAbs> piece) {
	if(piece != nullptr)
		return (team_ == piece->team_); 
	return false;
}

Team PieceAbs::getTeam() { return team_; }

King::King(Team team, int x, int y) : PieceAbs(team, x, y) {

	if (team == Team::Lilac) {
		name_ = "Lilac King";
		icon_ = lilacKingIcon;
	}
	else {
		name_ = "Pink King";
		icon_ = pinkKingIcon;
	}

}

bool King::isValidMove(int x, int y) { 
	return ((x <= x_ + 1 && x >= x_ - 1) && (y <= y_ + 1 && y >= y_ - 1)); 
}

Bishop::Bishop(Team team, int x, int y) : PieceAbs(team, x, y) {
	if (team == Team::Lilac) {
		name_ = "Lilac Bishop";
		icon_ = lilacBishopIcon;
	}
	else {
		name_ = "Pink Bishop";
		icon_ = pinkBishopIcon;
	}

}
bool Bishop::isValidMove(int x, int y) { 
	return (std::abs(x - x_) == std::abs(y - y_));
}

Rook::Rook(Team team, int x, int y) : PieceAbs(team, x, y) {
	if (team == Team::Lilac) {
		name_ = "Lilac Rook";
		icon_ = lilacRookIcon;
	}
	else {
		name_ = "Pink Rook";
		icon_ = pinkRookIcon;
	}

}

bool Rook::isValidMove(int x, int y) {
	return(x_ == x || y_ == y);
}

