#include <QtGui>
#include "cwidget.h"
#include "glwidget.h"
cWidget::cWidget()
{
    createRight();
    glWidget = new GLWidget(4.0f);
    mainLayout = new QGridLayout;
    mainLayout->addWidget(glWidget,0,0);
    mainLayout->addWidget(rightGroup,0,1);
    mainLayout->setColumnStretch(0,40);
    mainLayout->setColumnStretch(1,10);
    setLayout(mainLayout);
}

void cWidget::start()
{
    bStart->setText(tr("ÏÀÓÇÀ"));
    bStop->setEnabled(true);
    glWidget->setL(eDistance->text().toFloat());
    glWidget->StartAn();
    connect(bStart,SIGNAL(clicked()),this,SLOT(pause()));
}

void cWidget::stop()
{

}

void cWidget::pause()
{
    bStart->setText(tr("ÏÓÑÊ"));
    glWidget->StopAn();
    connect(bStart,SIGNAL(clicked()),this,SLOT(start()));
}

void cWidget::createRight()
{
    rightGroup = new QGroupBox;
    lDistance = new QLabel(tr("Ðàññòîÿíèå(ìåòðû):"));
    lVoltage = new QLabel(tr("Íàïðÿæåíèå(âîëüòû):"));
    lInduct = new QLabel(tr("Èíäóêöèÿ(òåñëà):"));
    eDistance = new QLineEdit(tr("4"));
    eVoltage = new QLineEdit(tr("0"));
    eInduct = new QLineEdit(tr("0"));
    QRegExp rx("^[0-9]*[\\.|,]{1}[0-9]*$");
    QValidator *validator = new QRegExpValidator(rx,this);
    eDistance->setValidator(validator);
    eVoltage->setValidator(validator);
    eInduct->setValidator(validator);
    bStart = new QPushButton(tr("ÏÓÑÊ"));
    connect(bStart,SIGNAL(clicked()),this,SLOT(start()));
    bStop = new QPushButton(tr("ÑÒÎÏ"));
    bStop->setDisabled(1);
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
