/**
* Chess Game.
* \file   Piece.h
* \author Irem Yildiz
* \date   14 avril 2023
* Créé le 10 avril 2023
*/

#pragma once
#include <string>
#include <functional>
#include <qstring.h>

enum class Team {Pink, White};

class PieceAbs {
public:
	PieceAbs(Team team, int x, int y);
	virtual ~PieceAbs() = default;
	QString getIcon();
	int getX();
	int getY();
	void setPos(int newX, int newY);
	virtual bool isValidMove(int x, int y);
	bool isSameTeam(std::shared_ptr<PieceAbs> piece);

protected:
	std::string name_;
	Team team_;
	QString icon_;
	int x_ = 0;
	int y_ = 0;
};

class King : public PieceAbs {
public:
	King(Team team, int x, int y);
	bool isValidMove(int x, int y);
protected:
};

class Bishop : public PieceAbs {
public:
	Bishop(Team team, int x, int y);
	bool isValidMove(int x, int y);
};

class Rook : public PieceAbs {
public:
	Rook(Team team, int x, int y);
	bool isValidMove(int x, int y);
};
