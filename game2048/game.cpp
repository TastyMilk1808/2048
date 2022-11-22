#include <cstdlib>
#include "game.h"
#include "QtDebug"
#include "QRandomGenerator"

Game::Game()
{
    data = new int*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        data[i] = new int[SIZE];
    }
}

void Game::Reset()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            data[i][j] = 0;
        }
    }
    int randX = QRandomGenerator::global()->bounded(SIZE);
    int randY = QRandomGenerator::global()->bounded(SIZE);
    data[randX][randY] = 2;
    int randX2 = QRandomGenerator::global()->bounded(SIZE);
    int randY2 = QRandomGenerator::global()->bounded(SIZE);
    while (randX2 == randX && randY2 == randY) {
        randX2 = QRandomGenerator::global()->bounded(SIZE);
        randY2 = QRandomGenerator::global()->bounded(SIZE);
    }
    data[randX2][randY2] = 4;
    emit callReloadUi(data);
}

void Game::move(int direction)
{
    bool stop;
    int curPos;
    bool isMoved = false;
    switch (direction) {
        case RIGHT:
            for (int j = SIZE - 2; j > -1; j--) {
                for (int i = 0; i < SIZE; i++) {
                    if (data[i][j] == 0) {
                        continue;
                    }
                    stop = false;
                    curPos = j;
                    while (!stop) {
                        if (curPos == SIZE-1) {
                            stop = true;
                        }
                        else if (data[i][curPos+1] == 0) {
                            data[i][curPos+1] = data[i][curPos];
                            data[i][curPos] = 0;
                            curPos++;
                            isMoved = true;
                        }
                        else if (data[i][curPos] == data[i][curPos+1]) {
                            data[i][curPos+1] *= 2;
                            data[i][curPos] = 0;
                            stop = true;
                            isMoved = true;
                        }
                        else {
                            stop = true;
                        }
                    }
                }
            }
            break;

        case LEFT:
            for (int j = 1; j < SIZE; j++) {
                for (int i = 0; i < SIZE; i++) {
                    if (data[i][j] == 0) {
                        continue;
                    }
                    stop = false;
                    curPos = j;
                    while (!stop) {
                        if (curPos == 0) {
                            stop = true;
                        }
                        else if (data[i][curPos-1] == 0) {
                            data[i][curPos-1] = data[i][curPos];
                            data[i][curPos] = 0;
                            curPos--;
                            isMoved = true;
                        }
                        else if (data[i][curPos] == data[i][curPos-1]) {
                            data[i][curPos-1] *= 2;
                            data[i][curPos] = 0;
                            stop = true;
                            isMoved = true;
                        }
                        else {
                            stop = true;
                        }
                    }
                }
            }
            break;

        case DOWN:
            for (int i = SIZE - 2; i > -1; i--) {
                for (int j = 0; j < SIZE; j++) {
                    if (data[i][j] == 0) {
                        continue;
                    }
                    stop = false;
                    curPos = i;
                    while (!stop) {
                        if (curPos == SIZE-1) {
                            stop = true;
                        }
                        else if (data[curPos+1][j] == 0) {
                            data[curPos+1][j] = data[curPos][j];
                            data[curPos][j] = 0;
                            curPos++;
                            isMoved = true;
                        }
                        else if (data[curPos][j] == data[curPos+1][j]) {
                            data[curPos+1][j] *= 2;
                            data[curPos][j] = 0;
                            stop = true;
                            isMoved = true;
                        }
                        else {
                            stop = true;
                        }
                    }
                }
            }
            break;

        case UP:
            for (int i = 1; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (data[i][j] == 0) {
                        continue;
                    }
                    stop = false;
                    curPos = i;
                    while (!stop) {
                        if (curPos == 0) {
                            stop = true;
                        }
                        else if (data[curPos-1][j] == 0) {
                            data[curPos-1][j] = data[curPos][j];
                            data[curPos][j] = 0;
                            curPos--;
                            isMoved = true;
                        }
                        else if (data[curPos][j] == data[curPos-1][j]) {
                            data[curPos-1][j] *= 2;
                            data[curPos][j] = 0;
                            stop = true;
                            isMoved = true;
                        }
                        else {
                            stop = true;
                        }
                    }
                }
            }
            break;

    }
    if (isMoved) {
        int randX;
        int randY;
        do {
            randX = QRandomGenerator::global()->bounded(SIZE);
            randY = QRandomGenerator::global()->bounded(SIZE);
        } while (data[randX][randY] != 0);
        data[randX][randY] = QRandomGenerator::global()->bounded(1, 3)*2;
        emit callReloadUi(data);
        showData();
    }
}

void Game::showData()
{
    QDebug deb = qDebug().nospace();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            deb << data[i][j] << " ";
        }
        deb.nospace() << "\n";
    }
}
