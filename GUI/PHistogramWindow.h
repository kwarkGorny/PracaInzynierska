#ifndef PHISTOGRAMWINDOW_H
#define PHISTOGRAMWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>

#include"AdjacencyList/AdjacencyList.h"
#include"AdjacencyList/AdjacencyListManager.h"
#include"Patterns/Statistics.h"

#include "ui_PHistogramWindow.h"

namespace Ui {
class PHistogramWindow;
}

class PHistogramWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PHistogramWindow(AdjacencyList* hyperGraph,Distribution* pDistribution,QWidget *parent = 0);
    ~PHistogramWindow();

    void DrawToHistogram(QCustomPlot* grap,const std::unordered_map<int,double>& histogram );
    void DrawTheoreticalHistogram(QCustomPlot* grap,const std::vector<double>& values);
    void ResetHistogram(QCustomPlot* grap);

    void PrepareHistogram();
    void DrawPHistogram();

    void AnalizeHyperEdges();

    void reset();


    void SetPDistribution(Distribution* pDistribution){m_PDistribution = pDistribution;}


private slots:
    void on_HAnalyzeBtn_clicked();

private:
    Ui::PHistogramWindow *ui;

    AdjacencyList* m_HyperGraph;
    Distribution* m_PDistribution;

    std::vector<int> m_PTable;
    std::unordered_map<int,double> m_PHistogram;
    std::vector<double> m_PTheoretical;
};

#endif // PHISTOGRAMWINDOW_H
