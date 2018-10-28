#include <QtWidgets/QApplication>
#include "mainwindow.h"
#include "screen.h"

MainWindow::MainWindow()
{
    screen = new Screen;
    scoreLcd = new QLCDNumber(5);
    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);       /* setFocusPolicy */
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);
    
    /* connect(sender, signal, functor) */

    connect(startButton, &QPushButton::clicked, screen, &Screen::start);
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(pauseButton, &QPushButton::clicked, screen, &Screen::pause);
    connect(screen, &Screen::scoreChanged,
            scoreLcd, QOverload<int>::of(&QLCDNumber::display));
    connect(screen, &Screen::levelChanged,
            levelLcd, QOverload<int>::of(&QLCDNumber::display));
    connect(screen, &Screen::linesRemovedChanged,
            lineClearedLcd, QOverload<int>::of(&QLCDNumber::display));
    
    /* layout setup */
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
    layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 4, 0);
    layout->addWidget(screen, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("SCORE")), 0, 2);
    layout->addWidget(scoreLcd, 1, 2);
    layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    layout->addWidget(lineClearedLcd, 3, 2);
    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);
}

QLabel *MainWindow::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return label;
}
