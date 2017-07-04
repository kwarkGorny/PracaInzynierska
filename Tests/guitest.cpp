#include "GUI/mainwindow.h"
#include <QApplication>

int guiTest1(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
