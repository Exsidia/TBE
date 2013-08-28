#include <qapplication.h>
#include <QTextCodec>
#include <QTimer>
//#include "mainwindow.h"
#include "loadwindow.h"
#include "glwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
//    MainWindow MW;
    LoadWindow LW;
    LW.show();
//    MW.show();
    return app.exec();
}
