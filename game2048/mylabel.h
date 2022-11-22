#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    myLabel(int score);
};

#endif // MYLABEL_H
