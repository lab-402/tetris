#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>

#include "screen.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QLabel *createLabel(const QString &text);
    
    Screen *screen;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *lineClearedLcd;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *quitButton;
public:
    MainWindow();

};

#endif // MAINWINDOW_H
