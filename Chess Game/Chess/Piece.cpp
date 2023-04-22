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
std::string PieceAbs::getType() { return "Piece Abs"; }

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

std::string King::getType() { return "King"; }

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

std::string Bishop::getType() { return "Bishop"; }

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

std::string Rook::getType() { return "Rook"; }

Queen::Queen(Team team, int x, int y) : PieceAbs(team, x, y) {
	if (team == Team::Lilac) {
		name_ = "Lilac Queen";
		icon_ = lilacQueenIcon;
	}
	else {
		name_ = "Pink Queen";
		icon_ = pinkQueenIcon;
	}
}

bool Queen::isValidMove(int x, int y) {
	return((x_ == x || y_ == y) || (std::abs(x - x_) == std::abs(y - y_)) || ((x <= x_ + 1 && x >= x_ - 1) && (y <= y_ + 1 && y >= y_ - 1)));
}

std::string Queen::getType() { return "Queen"; }

Knight::Knight(Team team, int x, int y) : PieceAbs(team, x, y) {
	if (team == Team::Lilac) {
		name_ = "Lilac Knight";
		icon_ = lilacKnightIcon;
	}
	else {
		name_ = "Pink Knight";
		icon_ = pinkKnightIcon;
	}
}

bool Knight::isValidMove(int x, int y) {
	return((std::abs(x_ - x) == 2 || std::abs(y_ - y) == 2) && (std::abs(x_ - x) == 1 || std::abs(y_ - y) == 1));
}

std::string Knight::getType() { return "Knight"; }

Pawn::Pawn(Team team, int x, int y) : PieceAbs(team, x, y) {
	if (team == Team::Lilac) {
		name_ = "Lilac Pawn";
		icon_ = lilacPawnIcon;
	}
	else {
		name_ = "Pink Pawn";
		icon_ = pinkPawnIcon;
	}
}

bool Pawn::isValidMove(int x, int y) {
	if (didFirstMove_ == false) {
		if (team_ == Team::Lilac) {
			return ((x == x_ + 2) || (x == x_ + 1));
		}
		else {
			return  ((x == x_ - 2) || (x == x_ - 1));
		}
	}
	else {
	if (team_ == Team::Lilac) {
		return (x == x_ + 1);
	}
	else {
		return  (x == x_ - 1); 
	}
	}

	
}

std::string Pawn::getType() { return "Pawn"; }

void Pawn::setFirstMove(bool boolean) { didFirstMove_ = boolean; }

bool Pawn::getFirstMove() { return didFirstMove_; }
