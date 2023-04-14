#pragma once

#include <QPushButton>
#include <QtWidgets/QMainWindow>
#include "ui_Chess.h"
#include <QGridLayout>

class Chess : public QMainWindow
{
    Q_OBJECT

public:
    Chess(QWidget *parent = nullptr);
    ~Chess();

private:
    Ui::ChessClass ui;
};
