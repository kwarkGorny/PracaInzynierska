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


enum  ALGORITHM
{
    ALGORITHM_RANDOM_HYPERGRAPH,
    ALGORITHM_FULL_HYPERGRAPH,
    ALGORITHM_TEST,
    ALGORITHM_CHOOSE_ALGORITHM,
};

enum APPLICATION_STATE
{
    APPLICATION_STATE_NONE,
    APPLICATION_STATE_CHOOSE_ALGORITHM,
    APPLICATION_STATE_CHOOSE_VERTEX_DISTRIBUTION,
    APPLICATION_STATE_CHOOSE_HYPEREDGE_DISTRIBUTION,
    APPLICATION_STATE_CREATE_HYPERGRAPH,
    APPLICATION_STATE_ADDITIONAL_OPTION,
    APPLICATION_STATE_COUNT,
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

    void ChangeApplicationState(APPLICATION_STATE newState);
protected:
    void OnStateEnter(APPLICATION_STATE newState);
    void OnStateLeave(APPLICATION_STATE preState);
private slots:
    void on_StartBtn_clicked();

    void on_AlgorithmsCB_currentIndexChanged(int index);

    void on_VDistributionCB_currentIndexChanged(int index);

    void on_HDistributionCB_currentIndexChanged(int index);

    void on_pushButton_5_clicked();

    void on_PlotKHistogramBtn_clicked();

    void on_PlotPHistogramBtn_clicked();

    void on_actionSave_as_triggered();

    void on_actionLoad_triggered();

    void on_actionLoad_kTable_triggered();

    void on_VCheckBtn_clicked();

    void on_HCheckBtn_clicked();

private:
    Ui::MainWindow* ui;

    std::unique_ptr<KHistogramWindow> m_KHistogram;
    std::unique_ptr<PHistogramWindow> m_PHistogram;

    bool m_AlgorithmStarted=false;

    APPLICATION_STATE m_ActualState;

    std::vector<int> m_LoadedKTable;

};

#endif // MAINWINDOW_H
