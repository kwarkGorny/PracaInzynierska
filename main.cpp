#include "GUI/mainwindow.h"
#include <QApplication>
#include<iostream>


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
