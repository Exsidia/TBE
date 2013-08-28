#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
QT_END_NAMESPACE

class GLWidget;
class cWidget;

class MainWindow:public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
private slots:
    void about(); //окно "о программе"
    void authors();//авторы
    void loading();//изображение
private:
    void createActions(); //создание действий
    void createMenus(); //создание меню
    void createLayout();//дизайн

    GLWidget *glWidget;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *quitMenu;
    cWidget *ccWidget;
    QAction *highAct;
    QAction *medAct;
    QAction *lowAct;
    QAction *aboutAct;
    QAction *authorsAct;
    QAction *quitAct;
};

#endif // MAINWINDOW_H
