#pragma once
#include <string>

enum class Team {Pink, White};

class PieceAbs {
public:
	PieceAbs();
	virtual ~PieceAbs() = default;
	virtual void test() = 0;
protected:
	std::string name_;
	Team team_;
	std::string icon_;
};