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

private slots:
    void handleButton();

private:
    QPushButton* m_button;
    QPushButton* b_button;
    
    Ui::ChessClass ui;
};
