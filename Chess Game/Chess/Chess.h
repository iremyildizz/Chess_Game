/**
* Chess Game.
* \file   Chess.h
* \author Irem Yildiz
* \date   5 mai 2023
* Créé le 10 avril 2023
*/

#pragma once

#include <QPushButton>
#include <QtWidgets/QMainWindow>
#include "ui_Chess.h"
#include <QGridLayout>
#include "ChessGrid.h"
#include "Game.h"
#include "ChessCase.h"
#include "Controller.h"

class Chess : public QMainWindow
{
    Q_OBJECT

public:
    Chess(QWidget *parent = nullptr);
    void startGame();
    std::shared_ptr<QWidget> getWindow();
    ~Chess();

public slots:
    void newGame();
    void test1Game();
    void test2Game();

private:
    Ui::ChessClass ui;
    Game game_;
    std::shared_ptr<QWidget> window_;
    std::shared_ptr<ChessGrid> chessGrid_;
    std::shared_ptr<Controller> controller_;
};
