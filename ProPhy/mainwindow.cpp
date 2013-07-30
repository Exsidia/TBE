#include <QtGui>
#include "mainwindow.h"
#include "glwidget.h"
#include "cwidget.h"


MainWindow::MainWindow()
{
    createLayout();
    createActions();
    createMenus();
    resize(900,600);
    move(200,100);
    setWindowTitle(tr("Движение"));
}

void MainWindow::about()
{
    QMessageBox::about(this,tr("О программе"),
                       tr("Моделирование движения элетрона и прочее..."));
}

void MainWindow::loading()
{

}

void MainWindow::authors()
{

}

void MainWindow::createActions()
{
    aboutAct = new QAction(tr("&О программе"), this);
    aboutAct->setStatusTip(tr("Инструкция"));
    connect(aboutAct, SIGNAL(triggered()),this, SLOT(about()));
    authorsAct = new QAction(tr("&Авторы"), this);
    authorsAct->setStatusTip(tr("Авторы"));
    connect(authorsAct, SIGNAL(triggered()),this, SLOT(authors()));
    highAct = new QAction(tr("Высокое качество"),this);
    medAct = new QAction(tr("Среднее качество"), this);
    lowAct = new QAction(tr("Низкое качество"), this);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Файл"));
    fileMenu->addAction(highAct);
    fileMenu->addAction(medAct);
    fileMenu->addAction(lowAct);
    helpMenu = menuBar()->addMenu(tr("&Помощь(?)"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(authorsAct);
    quitMenu = menuBar()->addMenu(tr("Выход"));
}

void MainWindow::createLayout()
{
    ccWidget = new cWidget;
    setCentralWidget(ccWidget);
}
