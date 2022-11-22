#ifndef GAME_H
#define GAME_H
#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    enum Constants
    {
        RIGHT = 0,
        DOWN = 1,
        LEFT = 2,
        UP = 3,
        SIZE = 4,
    };
    Game();
    void Reset();
    void showData();
public slots:
    void move(int direction);
signals:
    void callReloadUi(int** data);
private:
    int** data;
};

#endif // GAME_H
