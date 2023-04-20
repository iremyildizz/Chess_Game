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

enum class Team {Lilac, Pink};

namespace icons {
	const QString lilacKingIcon = "./images/King_Lilac.png";			/*photo by Wikipedia, edited by Irem Yildiz*/
	const QString pinkKingIcon = "./images/King_Pink.png";				/*photo by Wikipedia, edited by Irem Yildiz*/
	const QString lilacRookIcon = "./images/Rook_Lilac.png";			/*photo by Wikipedia, edited by Irem Yildiz*/
	const QString pinkRookIcon = "./images/Rook_Pink.png";				/*photo by Wikipedia, edited by Irem Yildiz*/
	const QString lilacBishopIcon = "./images/Bishop_Lilac.png";		/*photo by Wikipedia, edited by Irem Yildiz*/
	const QString pinkBishopIcon = "./images/Bishop_Pink.png";			/*photo by Wikipedia, edited by Irem Yildiz*/
	const QString lilacQueenIcon = "./images/Queen_Lilac.png";			/*photo by Wikipedia, edited by Irem Yildiz*/
	const QString pinkQueenIcon = "./images/Queen_Pink.png";			/*photo by Wikipedia, edited by Irem Yildiz*/
	const QString lilacKnightIcon = "./images/Knight_Lilac.png";		/*photo by Wikipedia, edited by Irem Yildiz, idea by Berk Yurteri*/
	const QString pinkKnightIcon = "./images/Knight_Pink.png";			/*photo by Wikipedia, edited by Irem Yildiz, idea by Berk Yurteri*/
}

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
	Team getTeam();
	virtual std::string getType();

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
	std::string getType() override;
protected:
};

class Bishop : public PieceAbs {
public:
	Bishop(Team team, int x, int y);
	bool isValidMove(int x, int y);
	std::string getType() override;
};

class Rook : public PieceAbs {
public:
	Rook(Team team, int x, int y);
	bool isValidMove(int x, int y);
	std::string getType() override;
};

class Queen : public PieceAbs {
public:
	Queen(Team team, int x, int y);
	bool isValidMove(int x, int y);
	std::string getType() override;
};

class Knight : public PieceAbs {
public:
	Knight(Team team, int x, int y);
	bool isValidMove(int x, int y);
	std::string getType() override;
};
