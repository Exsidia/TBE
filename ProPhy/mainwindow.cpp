#include <QtGui>
#include "mainwindow.h"
#include "glwidget.h"
#include "cwidget.h"

MainWindow::MainWindow()
{
    createLayout();
    createActions();
    createMenus();
    resize(1000,700);
    setWindowTitle(tr("��������"));
}

void MainWindow::about()
{
    QMessageBox::about(this,tr("� ���������"),
                       tr("������������� �������� �������� � ������..."));
}

void MainWindow::loading()
{

}

void MainWindow::authors()
{

}

void MainWindow::createActions()
{
    aboutAct = new QAction(tr("&� ���������"), this);
    aboutAct->setStatusTip(tr("����������"));
    connect(aboutAct, SIGNAL(triggered()),this, SLOT(about()));
    authorsAct = new QAction(tr("&������"), this);
    authorsAct->setStatusTip(tr("������"));
    connect(authorsAct, SIGNAL(triggered()),this, SLOT(authors()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&����"));
    helpMenu = menuBar()->addMenu(tr("&������(?)"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(authorsAct);
    quitMenu = menuBar()->addMenu(tr("�����"));
}

void MainWindow::createLayout()
{
    ccWidget = new cWidget;
    setCentralWidget(ccWidget);
}
