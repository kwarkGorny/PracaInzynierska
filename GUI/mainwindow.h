#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>

#include<vector>
#include<memory>
#include<chrono>
#include<string>
#include<unordered_map>

#include "ui_mainwindow.h"
#include "KHistogramWindow.h"
#include "PHistogramWindow.h"
#include"hypergraphdrawdialog.h"


/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Main window of application
*/



using namespace std::chrono;


enum  ALGORITHM{
    RANDOM_HYPERGRAPH,
    FULL_HYPERGRAPH,
    TEST,
};

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



    void SelectPDstribution();
    void SelectKDstribution();


    void ChooseAndRunAlgorithm();

    void AnalizeHyperGraph();

    void ShowTime(const std::string& nameOfFun,time_point<steady_clock> begin,time_point<steady_clock> end=steady_clock::now());

    void RandomHypergraphAlgorithm();

private slots:
    void on_StartBtn_clicked();

    void on_AlgorithmsCB_currentIndexChanged(int index);

    void on_VDistributionCB_currentIndexChanged(int index);

    void on_HDistributionCB_currentIndexChanged(int index);

    void on_pushButton_5_clicked();

    void on_PlotKHistogramBtn_clicked();

    void on_PlotPHistogramBtn_clicked();

private:
    Ui::MainWindow* ui;

    std::unique_ptr<KHistogramWindow> m_KHistogram;
    std::unique_ptr<PHistogramWindow> m_PHistogram;

    bool m_AlgorithmStarted=false;
};

#endif // MAINWINDOW_H
