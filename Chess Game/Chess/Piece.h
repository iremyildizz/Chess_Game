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

protected:
	std::string name_;
	Team team_;
	QString icon_;
	std::function<bool(int x,int y)> movementRule_;
	int x_;
	int y_;
};

class King : public PieceAbs {
public:
	King(Team team, int x, int y);
protected:
};

class Bishop : public PieceAbs {
public:
	Bishop(Team team, int x, int y);
};

class Rook : public PieceAbs {
public:
	Rook(Team team, int x, int y);
};
