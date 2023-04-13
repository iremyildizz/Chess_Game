#pragma once
#include "Piece.h"
#include <vector>
#include <memory>
class Game {
public:
	Game() = default;
	~Game() = default;
	std::vector<std::unique_ptr<PieceAbs>> test1();
private:
};