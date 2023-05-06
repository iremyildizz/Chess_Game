/**
* Chess Game.
* \file   Game.cpp
* \author Irem Yildiz
* \date   5 mai 2023
* Créé le 10 avril 2023
*/
#include "Game.h"

std::vector<std::shared_ptr<PieceAbs>> Game::test1() {
	std::vector<std::shared_ptr<PieceAbs>> game;

	game.push_back(std::make_unique<King>(Team::Lilac, 0, 4));
	game.push_back(std::make_unique<King>(Team::Pink, 7, 4));
	game.push_back(std::make_unique<Bishop>(Team::Lilac, 0, 2));
	game.push_back(std::make_unique<Bishop>(Team::Lilac, 0, 5));
	game.push_back(std::make_unique<Bishop>(Team::Pink, 7, 2));
	game.push_back(std::make_unique<Bishop>(Team::Pink, 7, 5));
	game.push_back(std::make_unique<Rook>(Team::Lilac, 0, 0));
	game.push_back(std::make_unique<Rook>(Team::Lilac, 0, 7));
	game.push_back(std::make_unique<Rook>(Team::Pink, 7, 0));
	game.push_back(std::make_unique<Rook>(Team::Pink, 7, 7));
	game.push_back(std::make_unique<Queen>(Team::Lilac, 0, 3));
	game.push_back(std::make_unique<Queen>(Team::Pink, 7, 3));
	game.push_back(std::make_unique<Knight>(Team::Pink, 7, 1));
	game.push_back(std::make_unique<Knight>(Team::Pink, 7, 6));
	game.push_back(std::make_unique<Knight>(Team::Lilac, 0, 1));
	game.push_back(std::make_unique<Knight>(Team::Lilac, 0, 6));

	for (int i = 0; i < 8; i++) {
		game.push_back(std::make_unique<Pawn>(Team::Lilac, 1, i));
	}

	for (int i = 0; i < 8; i++) {
		game.push_back(std::make_unique<Pawn>(Team::Pink, 6, i));
	}

	return game;
}

std::vector<std::shared_ptr<PieceAbs>> Game::test2() {
	std::vector<std::shared_ptr<PieceAbs>> game;

	game.push_back(std::make_unique<King>(Team::Lilac, 0, 1));
	game.push_back(std::make_unique<King>(Team::Pink, 5, 4));
	game.push_back(std::make_unique<Bishop>(Team::Pink, 2, 5));
	game.push_back(std::make_unique<Queen>(Team::Lilac, 1, 5));
	game.push_back(std::make_unique<Queen>(Team::Pink, 7, 5));

	return game;
}

std::vector<std::shared_ptr<PieceAbs>> Game::test3() {
	std::vector<std::shared_ptr<PieceAbs>> game;

	game.push_back(std::make_unique<King>(Team::Lilac, 2, 3));
	game.push_back(std::make_unique<King>(Team::Pink, 4, 3));
	game.push_back(std::make_unique<Rook>(Team::Lilac, 1, 0));
	game.push_back(std::make_unique<Rook>(Team::Pink, 6, 1));
	game.push_back(std::make_unique<Knight>(Team::Lilac, 1, 3));

	return game;
}

