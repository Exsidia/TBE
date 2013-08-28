#include <QtGui>
#include "mainwindow.h"
#include "glwidget.h"
#include "cwidget.h"


MainWindow::MainWindow()
{
    createLayout(); //инициализация функций для работы
    createActions();
    createMenus();
    resize(900,600);
    move(200,100);
    setWindowTitle(tr("Моделирование движения электрона методом магнитой фокусировки"));
}

void MainWindow::about() //окно "о программе"
{
    QMessageBox::about(this,tr("О программе"),
                       tr("Моделирование движения элетрона и прочее..."));
}

void MainWindow::loading() //для загрузки изначальной картинки
{

}

void MainWindow::authors()//окно "авторы"
{

}

void MainWindow::createActions() //создание действий
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
    quitAct = new QAction(tr("Выход"),this);
    connect(quitAct,SIGNAL(triggered()),this,SLOT(close()));
}

void MainWindow::createMenus() //меню
{
    fileMenu = menuBar()->addMenu(tr("&Файл"));
    fileMenu->addAction(highAct);
    fileMenu->addAction(medAct);
    fileMenu->addAction(lowAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);
    helpMenu = menuBar()->addMenu(tr("&Помощь(?)"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(authorsAct);
}

void MainWindow::createLayout() //дизайн мейна
{
    ccWidget = new cWidget; //описан в cwidget.h
    setCentralWidget(ccWidget);
}
