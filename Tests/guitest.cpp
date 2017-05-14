#include <QApplication>
#include"GUI/mainwindow.h"


int guiTest1(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
