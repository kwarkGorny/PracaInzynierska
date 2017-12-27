#include "GUI/mainwindow.h"
#include"AdjacencyList/AdjacencyList.h"
#include"AdjacencyList/AdjacencyListFabric.h"
#include"Distributions/constant.h"
#include <QApplication>
#include<iostream>
#include<string>


void AdjecncyListTest()
{

    Constant constKDistribution (5);
    Constant constPDistribution (3);

    auto hyperGraph = AdjacencyListFabric::CreateRandomAdjacencyList(1000,constKDistribution,constPDistribution);

    std::cout<< hyperGraph.size()<<'\n';




}




int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


 //   AdjecncyListTest();
   // return 1;
}
