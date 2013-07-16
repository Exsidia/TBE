#include <qapplication.h>
#include <QTextCodec>
#include "mainwindow.h"
#include "glwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    MainWindow MW;
    MW.show();
    return app.exec();
}
