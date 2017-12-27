#ifndef PHISTOGRAMWINDOW_H
#define PHISTOGRAMWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include<unordered_map>

#include "ui_PHistogramWindow.h"

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Histogram window for Hyperedge degree analyze
*/

namespace Ui
{
    class PHistogramWindow;
}

class PHistogramWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PHistogramWindow(QWidget *parent = 0);
    ~PHistogramWindow();

    void DrawToHistogram(QCustomPlot* grap,const std::unordered_map<int,double>& histogram );
    void DrawTheoreticalHistogram(QCustomPlot* grap,const std::vector<double>& values);
    void ResetHistogram(QCustomPlot* grap);

    void PrepareHistogram();
    void DrawPHistogram();

    void AnalizeHyperEdges();

    void reset();




private slots:
    void on_HAnalyzeBtn_clicked();

private:
    Ui::PHistogramWindow *ui;

    std::unordered_map<int,double> m_PHistogram;
    std::vector<double> m_PTheoretical;
};

#endif // PHISTOGRAMWINDOW_H
