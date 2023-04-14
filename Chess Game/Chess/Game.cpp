#include "Game.h"

std::vector<std::shared_ptr<PieceAbs>> Game::test1() {
	std::vector<std::shared_ptr<PieceAbs>> game;

	game.push_back(std::make_unique<King>(Team::White, 7, 4));
	game.push_back(std::make_unique<King>(Team::Pink, 0, 4));

	return game;
}