#include <QtGui>
#include "cwidget.h"
#include "glwidget.h"
cWidget::cWidget()
{
    createRight(); //расположение элементов
    glWidget = new GLWidget(4.0f); //задание длины элт масштаб 1:40 в данном случае 4.0f = 10 см
    mainLayout = new QGridLayout;
    mainLayout->addWidget(glWidget,0,0); //окно OpenGL
    mainLayout->addWidget(rightGroup,0,1); //группа элементов для взаимодействия
    mainLayout->setColumnStretch(0,35);
    mainLayout->setColumnStretch(1,10);
    setLayout(mainLayout);
}

void cWidget::start()
{
    bStart->setText(tr("ПАУЗА"));
    bStop->setEnabled(true);
    glWidget->setL(eDistance->text().toFloat()*40);
    glWidget->StartAn();
    connect(bStart,SIGNAL(clicked()),this,SLOT(pause()));
}

void cWidget::stop()
{

}

void cWidget::pause()
{
    bStart->setText(tr("ПУСК"));
    glWidget->StopAn();
    connect(bStart,SIGNAL(clicked()),this,SLOT(start()));
}

void cWidget::createRight()
{
    rightGroup = new QGroupBox;
    lDistance = new QLabel(tr("Расстояние(метры):"));
    lVoltage = new QLabel(tr("Напряжение(вольты):"));
    lInduct = new QLabel(tr("Индукция(тесла):"));
    eDistance = new QLineEdit(tr("0.1"));
    eVoltage = new QLineEdit(tr("0"));
    eInduct = new QLineEdit(tr("0"));
    QRegExp rx("^[0-9]*[\\.|,]{1}[0-9]*$");//ввод только таких символов
    QValidator *validator = new QRegExpValidator(rx,this);
    eDistance->setValidator(validator);//применияем к полям
    eVoltage->setValidator(validator);
    eInduct->setValidator(validator);
    bStart = new QPushButton(tr("ПУСК"));
    connect(bStart,SIGNAL(clicked()),this,SLOT(start()));
    bStop = new QPushButton(tr("СТОП"));
    bStop->setDisabled(1);
    rightLayout = new QGridLayout;
    rightLayout->addWidget(lDistance,0,0,1,2);
    rightLayout->addWidget(eDistance,1,0,1,2);
    rightLayout->addWidget(lVoltage,2,0,1,2);
    rightLayout->addWidget(eVoltage,3,0,1,2);
    rightLayout->addWidget(lInduct,4,0,1,2);
    rightLayout->addWidget(eInduct,5,0,1,2);
    rightLayout->addWidget(bStart,6,0,1,1);
    rightLayout->addWidget(bStop,6,1,1,1);
    GLWidget *glw = new GLWidget(4.0f);
    rightLayout->addWidget(glw,7,0,2,2);
    rightGroup->setLayout(rightLayout);
}
