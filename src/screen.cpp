#include <QtWidgets>

#include "screen.h"

Screen::Screen(QWidget *parent) : QFrame(parent)
{
    /* setFrameStyle : sets the frame style to style
    *  frame shape and a frame shadow style
    */
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    /*
    *  setFocusPolicy: sets the way of accepting keyboard focus 
    *  strong -> accepting tab and click
    */
    setFocusPolicy(Qt::StrongFocus);
    //isStarted = false;
    //isPaused = false;
    //clearBoard();
    //nextPiece.setRandomShape();
}

// QSize sizeHint() const override; /* */
//     QSize minimumSizeHint() const override;
// public slots:
//     void start();
//     void pause();
// signals:
//     void scoreChanged(int score);
//     void levelChanged(int level);
//     void linesRemovedChanged(int numLines);

void Screen::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    QRect rect = contentsRect();

//    if (isPaused) {
//        painter.drawText(rect, Qt::AlignCenter, tr("Pause"));
//        return;
//    }

//    int boardTop = rect.bottom() - BoardHeight*squareHeight();

//    for (int i = 0; i < BoardHeight; ++i) {
//        for (int j = 0; j < BoardWidth; ++j) {
//            TetrixShape shape = shapeAt(j, BoardHeight - i - 1);
//            if (shape != NoShape)
//                drawSquare(painter, rect.left() + j * squareWidth(),
//                           boardTop + i * squareHeight(), shape);
//        }
//    }

//    if (curPiece.shape() != NoShape) {
//        for (int i = 0; i < 4; ++i) {
//            int x = curX + curPiece.x(i);
//            int y = curY - curPiece.y(i);
//            drawSquare(painter, rect.left() + x * squareWidth(),
//                       boardTop + (BoardHeight - y - 1) * squareHeight(),
//                       curPiece.shape());
//        }
//    }
}

void Screen::keyPressEvent(QKeyEvent *event)
{
//    if(!isStarted || isPaused || curPiece.shape() == NoShape)
//    {
//        QFrame::keyPressEvent(event);
//        return;
//    }

    switch(event->key()){
        case Qt::Key_Left:
            //tryMove(curPiece, curX-1, curY);
            break;
        case Qt::Key_Right:
            //right move
            break;
        case Qt::Key_Down:
            //tryMove
            break;
        case Qt::Key_Up:
            //tryMove
            break;
        case Qt::Key_Space:
            //dropdown()
            break;
        case Qt::Key_D:
            //oneLineDown();
            break;
        default:
            QFrame::keyPressEvent(event);                    
    }
}

//void Screen::timerEvent(QTimerEvent *event)
//{
//    if (event->timerId() == timer.timerId()) {
//        if (isWaitingAfterLine) {
//            isWaitingAfterLine = false;
//            //newPiece();
//            timer.start(timeoutTime(), this);
//        } else {
//            //oneLineDown();
//        }
//    } else {
//        QFrame::timerEvent(event);
//    }
//}

