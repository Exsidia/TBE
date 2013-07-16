#include <QtGui>
#include "cwidget.h"
#include "glwidget.h"

cWidget::cWidget()
{
    createRight();
    glWidget = new GLWidget;
    mainLayout = new QGridLayout;
    mainLayout->addWidget(glWidget,0,0);
    mainLayout->addWidget(rightGroup,0,1);
    mainLayout->setColumnStretch(0,40);
    mainLayout->setColumnStretch(1,10);
    setLayout(mainLayout);
}

void cWidget::createRight()
{
    rightGroup = new QGroupBox;
    lDistance = new QLabel(tr("Расстояние(метры):"));
    lVoltage = new QLabel(tr("Напряжение(вольты):"));
    lInduct = new QLabel(tr("Индукция(тесла):"));
    eDistance = new QLineEdit(tr("0"));
    eVoltage = new QLineEdit(tr("0"));
    eInduct = new QLineEdit(tr("0"));
    bStart = new QPushButton(tr("ПУСК"));
    bStop = new QPushButton(tr("СТОП"));
    rightLayout = new QGridLayout;
    rightLayout->addWidget(lDistance,0,0,1,2);
    rightLayout->addWidget(eDistance,1,0,1,2);
    rightLayout->addWidget(lVoltage,2,0,1,2);
    rightLayout->addWidget(eVoltage,3,0,1,2);
    rightLayout->addWidget(lInduct,4,0,1,2);
    rightLayout->addWidget(eInduct,5,0,1,2);
    rightLayout->addWidget(bStart,6,0,4,1);
    rightLayout->addWidget(bStop,6,1,4,1);
    rightGroup->setLayout(rightLayout);
}
