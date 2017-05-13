#include "GUI/mainwindow.h"
#include <QApplication>
#include<Patterns/hypergraphfabric.h>
#include<Matrix/incidencymatrix.h>
int main(int argc, char *argv[])
{
    IncidencyMatrix* hyperGraph=HyperGraphFabric::createTestIncidencyMatrix(6);
    hyperGraph->print();

    QApplication a(argc, argv);
    MainWindow w;
    w.drawHyperGraph(hyperGraph);
    w.show();

    return a.exec();
}
