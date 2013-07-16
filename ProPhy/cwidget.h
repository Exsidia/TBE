#ifndef CWIDGET_H
#define CWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;
class QGroupBox;
QT_END_NAMESPACE

class GLWidget;
class GLScreen;
class cWidget:public QWidget
{
    Q_OBJECT
public:
    cWidget();
private:
    void createRight();
    void createHRight();

    GLWidget *glWidget;
    GLScreen *glScreen;
    QPushButton *bStart;
    QPushButton *bStop;
    QLabel *lDistance;
    QLabel *lVoltage;
    QLabel *lInduct;
    QLineEdit *eDistance;
    QLineEdit *eVoltage;
    QLineEdit *eInduct;
    QGridLayout *mainLayout;
    QHBoxLayout *rightHLayout;
    QVBoxLayout *rightVLayout;
    QGroupBox *rightGroup;
    QGridLayout *rightLayout;
};

#endif // CWIDGET_H
