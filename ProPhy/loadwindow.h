#ifndef LOADWINDOW_H
#define LOADWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QImage;
QT_END_NAMESPACE
class MainWindow;
class LoadWindow:public QMainWindow
{
    Q_OBJECT
public:
    LoadWindow();
private slots:
    void load();
    void startT();
    void stopT();
signals:
    void keyPressEvent(QKeyEvent *key);
    void timeout();
private:
    MainWindow *MW;
    QTimer *timer;
};

#endif // LOADWINDOW_H
