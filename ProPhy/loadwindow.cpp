#include <QtGui>
#include "loadwindow.h"
#include "mainwindow.h"

LoadWindow::LoadWindow()
{
    setWindowFlags(Qt::FramelessWindowHint);
    resize(525,700);
    timer = new QTimer;
    MW = new MainWindow;
    QPixmap *pix = new QPixmap();
    pix->load(":/LOAD.bmp");
    QLabel *l = new QLabel();
    l->setPixmap(*pix);
    setCentralWidget(l);
    startT();
    load();
}

void LoadWindow::load()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(stopT()));
    connect(this,SIGNAL(keyPressEvent(QKeyEvent*)),this,SLOT(stopT()));
}

void LoadWindow::startT()
{
    timer->start(10000);
}

void LoadWindow::stopT()
{
    timer->stop();
    close();
    MW->show();
}
