#ifndef KHISTOGRAMWINDOW_H
#define KHISTOGRAMWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include "ui_KHistogramWindow.h"

#include<memory>

#include"AdjacencyList/AdjacencyList.h"
#include"AdjacencyList/AdjacencyListManager.h"
#include"Patterns/Statistics.h"
namespace Ui {
class KHistogramWindow;
}

class KHistogramWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KHistogramWindow(AdjacencyList* hyperGraph,Distribution* kDistribution,QWidget *parent = 0);
    ~KHistogramWindow();

    void DrawTheoreticalHistogram(QCustomPlot* grap,const std::vector<double>& values);
    void DrawToHistogram(QCustomPlot* grap,const std::unordered_map<int,double>& histogram);
    void ResetHistogram(QCustomPlot* grap);

    void PrepareHistogram();
    void DrawKHistogram();


    void AnalizeVertices();

    void SetKDistribution(Distribution* kDistribution){m_KDistribution = kDistribution;}


private slots:
    void on_VAnalyzeBtn_clicked();

private:
    Ui::KHistogramWindow *ui;

    AdjacencyList* m_HyperGraph;
    Distribution* m_KDistribution;

    std::vector<int> m_KTable;
    std::unordered_map<int,double> m_KHistogram;
    std::vector<double> m_KTheoretical;
};

#endif // KHISTOGRAMWINDOW_H
