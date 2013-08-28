#include <QtGui>
#include "mainwindow.h"
#include "glwidget.h"
#include "cwidget.h"


MainWindow::MainWindow()
{
    createLayout(); //������������� ������� ��� ������
    createActions();
    createMenus();
    resize(900,600);
    move(200,100);
    setWindowTitle(tr("������������� �������� ��������� ������� �������� �����������"));
}

void MainWindow::about() //���� "� ���������"
{
    QMessageBox::about(this,tr("� ���������"),
                       tr("������������� �������� �������� � ������..."));
}

void MainWindow::loading() //��� �������� ����������� ��������
{

}

void MainWindow::authors()//���� "������"
{

}

void MainWindow::createActions() //�������� ��������
{
    aboutAct = new QAction(tr("&� ���������"), this);
    aboutAct->setStatusTip(tr("����������"));
    connect(aboutAct, SIGNAL(triggered()),this, SLOT(about()));
    authorsAct = new QAction(tr("&������"), this);
    authorsAct->setStatusTip(tr("������"));
    connect(authorsAct, SIGNAL(triggered()),this, SLOT(authors()));
    highAct = new QAction(tr("������� ��������"),this);
    medAct = new QAction(tr("������� ��������"), this);
    lowAct = new QAction(tr("������ ��������"), this);
    quitAct = new QAction(tr("�����"),this);
    connect(quitAct,SIGNAL(triggered()),this,SLOT(close()));
}

void MainWindow::createMenus() //����
{
    fileMenu = menuBar()->addMenu(tr("&����"));
    fileMenu->addAction(highAct);
    fileMenu->addAction(medAct);
    fileMenu->addAction(lowAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);
    helpMenu = menuBar()->addMenu(tr("&������(?)"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(authorsAct);
}

void MainWindow::createLayout() //������ �����
{
    ccWidget = new cWidget; //������ � cwidget.h
    setCentralWidget(ccWidget);
}
