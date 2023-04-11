#pragma once
#include <QPushButton>
#include <Qsize>

class ChessCase : public QPushButton {
public:
	ChessCase(QWidget* parent = nullptr);
	~ChessCase() = default;

private:
	int lenght_ = 90;
	int height_ = 90;
};