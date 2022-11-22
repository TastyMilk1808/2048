#include "mylabel.h"
#include <QFont>

myLabel::myLabel(int score)
{
    if (score != 0) {
        this->setText(QString::number(score));
    }
    this->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(30);
    font.setBold(true);
    this->setFont(font);
    QString color;
    switch (score) {
    case 0:
        color = "QLabel {background-color: #beb4aa;}";
        break;
    case 2:
        color = "QLabel {background-color: #eee4da; color : #776e65; }";
        break;
    case 4:
        color = "QLabel {background-color: #ede0c8; color : #776e65; }";
        break;
    case 8:
        color = "QLabel {background-color: #f2b179; color : #f9f6f2; }";
        break;
    case 16:
        color = "QLabel {background-color: #f59563; color : #f9f6f2; }";
        break;
    case 32:
        color = "QLabel {background-color: #f67c5f; color : #f9f6f2; }";
        break;
    case 64:
        color = "QLabel {background-color: #f65e3b; color : #f9f6f2; }";
        break;
    case 128:
        color = "QLabel {background-color: #edcf72; color : #f9f6f2; }";
        break;
    case 256:
        color = "QLabel {background-color: #edcc61; color : #f9f6f2; }";
        break;
    case 512:
        color = "QLabel {background-color: #edc850; color : #f9f6f2; }";
        break;
    case 1024:
        color = "QLabel {background-color: #edc53f; color : #f9f6f2; }";
        break;
    case 2048:
        color = "QLabel {background-color: #edc22e; color : #f9f6f2; }";
        break;
    }

    this->setStyleSheet(color);
}
