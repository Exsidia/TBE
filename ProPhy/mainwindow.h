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
    void about();
    void authors();
    void loading();
private:
    void createActions();
    void createMenus();
    void createLayout();

    GLWidget *glWidget;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *quitMenu;
    cWidget *ccWidget;
    QAction *aboutAct;
    QAction *authorsAct;
    QAction *quitAct;
};

#endif // MAINWINDOW_H
