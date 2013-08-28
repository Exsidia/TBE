#include <QtGui>
#include "cwidget.h"
#include "glwidget.h"
cWidget::cWidget()
{
    createRight(); //������������ ���������
    glWidget = new GLWidget(4.0f); //������� ����� ��� ������� 1:40 � ������ ������ 4.0f = 10 ��
    mainLayout = new QGridLayout;
    mainLayout->addWidget(glWidget,0,0); //���� OpenGL
    mainLayout->addWidget(rightGroup,0,1); //������ ��������� ��� ��������������
    mainLayout->setColumnStretch(0,35);
    mainLayout->setColumnStretch(1,10);
    setLayout(mainLayout);
}

void cWidget::start()
{
    bStart->setText(tr("�����"));
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
    bStart->setText(tr("����"));
    glWidget->StopAn();
    connect(bStart,SIGNAL(clicked()),this,SLOT(start()));
}

void cWidget::createRight()
{
    rightGroup = new QGroupBox;
    lDistance = new QLabel(tr("����������(�����):"));
    lVoltage = new QLabel(tr("����������(������):"));
    lInduct = new QLabel(tr("��������(�����):"));
    eDistance = new QLineEdit(tr("0.1"));
    eVoltage = new QLineEdit(tr("0"));
    eInduct = new QLineEdit(tr("0"));
    QRegExp rx("^[0-9]*[\\.|,]{1}[0-9]*$");//���� ������ ����� ��������
    QValidator *validator = new QRegExpValidator(rx,this);
    eDistance->setValidator(validator);//���������� � �����
    eVoltage->setValidator(validator);
    eInduct->setValidator(validator);
    bStart = new QPushButton(tr("����"));
    connect(bStart,SIGNAL(clicked()),this,SLOT(start()));
    bStop = new QPushButton(tr("����"));
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
