#ifndef SCREEN_H
#define SCREEN_H

#include <QtCore/QBasicTimer>
#include <QtWidgets/QFrame>
#include <QtCore/QPointer>
#include <QLabel>

#include "tetromino.h"

class Screen : public QFrame
{
    Q_OBJECT    
private:    

public:
    // Screen();
    // void Show();
    // void onPressPauseButton();
    // void onPressExitButton();
    
    Screen(QWidget *parent = 0);
    void setNextPieceLabel(QLabel *label); /* QLabel: for text and image display*/
    QSize sizeHint() const override; /* */
    QSize minimumSizeHint() const override;
public slots:
    void start();
    void pause();
signals: /* need to go toe gamemanager */
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemovedChanged(int numLines);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    QBasicTimer timer;
    QPointer<QLabel> nextPieceLabel;
    
};

#endif // SCREEN_H
