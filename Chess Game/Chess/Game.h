/**
* Chess Game.
* \file   Game.h
* \author Irem Yildiz
* \date   14 avril 2023
* Créé le 10 avril 2023
*/
#pragma once
#include "Piece.h"
#include <vector>
#include <memory>
class Game {
public:
	Game() = default;
	~Game() = default;
	std::vector<std::shared_ptr<PieceAbs>> test1();
private:
};