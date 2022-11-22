#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <array>
#include "mylabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Game();
    int width = this->geometry().width() / game->SIZE;
    int height = this->geometry().height() / game->SIZE;
    for (int i = 0; i < game->SIZE; i++) {
        ui->tableWidget->insertColumn(i);
        ui->tableWidget->setColumnWidth(i, width);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setRowHeight(i, height);
    }
    connect(game, SIGNAL(callReloadUi(int**)), this, SLOT(reloadUi(int**)));
    connect(this, SIGNAL(callMove(int)), game, SLOT(move(int)));
    game->Reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Up:
            callMove(game->UP);
            break;
        case Qt::Key_Down:
            callMove(game->DOWN);
            break;
        case Qt::Key_Left:
            callMove(game->LEFT);
            break;
        case Qt::Key_Right:
            callMove(game->RIGHT);
            break;
    }
}

void MainWindow::reloadUi(int **data)
{
    int size = game->SIZE;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ui->tableWidget->setCellWidget(i, j, new myLabel(data[i][j]));
        }
    }
}

