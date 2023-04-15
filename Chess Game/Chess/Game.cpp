/**
* Chess Game.
* \file   Game.cpp
* \author Irem Yildiz
* \date   14 avril 2023
* Créé le 10 avril 2023
*/
#include "Game.h"

std::vector<std::shared_ptr<PieceAbs>> Game::test1() {
	std::vector<std::shared_ptr<PieceAbs>> game;

	game.push_back(std::make_unique<King>(Team::Pink, 0, 4));
	game.push_back(std::make_unique<King>(Team::White, 7, 4));
	game.push_back(std::make_unique<Bishop>(Team::Pink, 0, 2));
	game.push_back(std::make_unique<Bishop>(Team::White, 7, 2));
	game.push_back(std::make_unique<Rook>(Team::Pink, 0, 0));
	game.push_back(std::make_unique<Rook>(Team::Pink, 0, 7));
	game.push_back(std::make_unique<Rook>(Team::White, 7, 0));
	game.push_back(std::make_unique<Rook>(Team::White, 7, 7));

	return game;
}