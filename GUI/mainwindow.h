#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include <QGraphicsScene>
#include<string>
#include<vector>
#include<memory>
#include<random>
#include<chrono>
#include<functional>
#include<iostream>
#include<unordered_map>
#include"Matrix/incidencymatrix.h"
#include"Matrix/adjacencylist.h"
#include"Patterns/hypergraphmanager.h"
#include"Patterns/hypergraphfabric.h"
#include"guivertex.h"
#include"guihyperedge.h"
#include "ui_mainwindow.h"
namespace Ui {
class MainWindow;
}
enum DISTRIBUTION{
    CONST=0,
    UNIFORM=1,
    POISSON=2,
};
enum ALGORITHM{
    RANDOM_HYPERGRAPH=0,
    FULL_HYPERGRAPH=1,
    TEST=3,
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void prepareHistograms();
    void drawHyperGraph(int sizeOfHyperedges);
    void drawKHistogram();
    void drawPHistogram();
    void clearScene();
    void saveGuiTofile(const std::string& nameOfFile)const;
    void showTime(const std::string& nameOfFun,std::chrono::time_point<std::chrono::steady_clock> begin,std::chrono::time_point<std::chrono::steady_clock> end);
    void randomHypergraphAlgorithm();

private slots:
    void on_StartBtn_clicked();

    void on_AlgorithmsCB_currentIndexChanged(int index);

    void on_VDistributionCB_currentIndexChanged(int index);

    void on_HDistributionCB_currentIndexChanged(int index);

private:
    Ui::MainWindow* ui;
    std::unique_ptr<QGraphicsScene> scene;
    std::unique_ptr<AdjacencyList> hyperGraph;

    std::unique_ptr<std::vector<int>> kTable;

    std::unique_ptr<std::vector<int>> pTable;



    std::vector<std::unique_ptr<GUIVertex>> vertexes;
    std::vector<std::unique_ptr<GUIHyperEdge>> hyperEdges;
    std::vector<std::unique_ptr<QGraphicsLineItem>> lines;

    std::function<int()> kDistribution;

};

#endif // MAINWINDOW_H
