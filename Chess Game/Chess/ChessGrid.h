/**
* Chess Game.
* \file   ChessGrid.h
* \author Irem Yildiz
* \date   14 avril 2023
* Créé le 10 avril 2023
*/

#pragma once
#include <QGridLayout>
#include <vector>
#include "ChessCase.h"
#include <memory>

class Controller;
class ChessGrid : public QGridLayout {
public:
	ChessGrid(std::shared_ptr<Controller> controller, QWidget* parent = nullptr);
	~ChessGrid() = default;
	void init();
	void addPieces(std::vector<std::shared_ptr<PieceAbs>>);
	std::shared_ptr<ChessCase> findCase(int x, int y);
	std::vector<std::vector<std::shared_ptr<ChessCase>>> getListOfCases();
	int getLenght();
	int getHeight();
private:
	std::vector<std::vector<std::shared_ptr<ChessCase>>> listOfCases_;
	std::vector<std::shared_ptr<PieceAbs>> listOfPieces_;
	int lenght_ = 8;
	int height_ = 8;
	std::shared_ptr<Controller> controller_ = nullptr;
};