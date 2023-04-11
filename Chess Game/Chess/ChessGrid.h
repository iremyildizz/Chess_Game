#pragma once
#include <QGridLayout>
#include <vector>
#include "ChessCase.h"
#include <memory>
class ChessGrid : public QGridLayout {
public:
	ChessGrid(QWidget* parent = nullptr);
	~ChessGrid() = default;
	void init();
private:
	std::vector<std::shared_ptr<ChessCase>> listOfCases_;
	int lenght_ = 8;
	int height_ = 8;
};