/**
* Chess Game.
* \file   Chess.cpp
* \author Irem Yildiz
* \date   5 mai 2023
* Créé le 10 avril 2023
*/

#include "Chess.h"

Chess::Chess(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void Chess::startGame() {
    Game game;
    controller_ = std::make_shared<Controller>();
    chessGrid_ = std::make_shared<ChessGrid>(controller_);
    chessGrid_->addPieces(game.test1());
    controller_->setGrid(chessGrid_);

    QBoxLayout* chessGameLayout = new QBoxLayout(QBoxLayout::LeftToRight);

    QWidget* chess = new QWidget();
    chess->setLayout(chessGrid_.get());
    chessGameLayout->addWidget(chess);

    QBoxLayout* buttonsLayout = new QBoxLayout((QBoxLayout::TopToBottom));

    QPushButton* newGameButton = new QPushButton("New Game");
    newGameButton->setFixedSize(QSize(100, 50));
    QPushButton* gameTest1Button = new QPushButton("Test 1 Game");
    gameTest1Button->setFixedSize(QSize(100, 50));
    QPushButton* gameTest2Button = new QPushButton("Test 2 Game");
    gameTest2Button->setFixedSize(QSize(100, 50));
   
    buttonsLayout->addWidget(newGameButton);
    buttonsLayout->addWidget(gameTest1Button);
    buttonsLayout->addWidget(gameTest2Button);
    buttonsLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(gameTest1Button, SIGNAL(clicked()), this, SLOT(test1Game()));
    connect(gameTest2Button, SIGNAL(clicked()), this, SLOT(test2Game()));

    QWidget* options = new QWidget();
    options->setLayout(buttonsLayout);
    chessGameLayout->addWidget(options);
    chessGameLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    window_ = std::make_shared<QWidget>();
    window_->setLayout(chessGameLayout);
    window_->setWindowTitle("Chess Game");
    window_->setStyleSheet("background-color:rgba(221, 195, 248, 0.5);");
}

std::shared_ptr<QWidget> Chess::getWindow() {
    return window_;
}

Chess::~Chess() {}

void Chess::newGame() {
    chessGrid_->recreateBoard(game_.test1());
    controller_->setTurn(true);
}

void Chess::test1Game() {
    chessGrid_->recreateBoard(game_.test2());
    controller_->setTurn(true);
}

void Chess::test2Game() {
    chessGrid_->recreateBoard(game_.test3());
    controller_->setTurn(true);
}
