#ifndef CWIDGET_H
#define CWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QAction;
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
private slots:
    void start(); //анимация
    void stop();
    void pause();
private:
    void createRight(); //расположение элементов окна
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
    QAction *startAct;
    QAction *stopAct;
    QAction *pauseAct;
};

#endif // CWIDGET_H
