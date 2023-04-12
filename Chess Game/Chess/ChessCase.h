#pragma once
#include <QPushButton>
#include <Qsize>

class ChessCase : public QPushButton {
public:
	ChessCase(int newX, int newY, QWidget* parent = nullptr);
	~ChessCase() = default;


private:
	int x_;
	int y_;
	int lenght_ = 90;
	int height_ = 90;
};