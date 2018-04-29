#ifndef KHISTOGRAMWINDOW_H
#define KHISTOGRAMWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include "ui_KHistogramWindow.h"

#include<memory>

#include"HyperGraph/HyperGraphManager.h"
#include"Patterns/Statistics.h"
#include "Patterns/Data.h"

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Histogram window for Vertex degree analyze
*/

namespace Ui
{
    class KHistogramWindow;
}

class KHistogramWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KHistogramWindow(QWidget *parent = 0);
    ~KHistogramWindow();

    void DrawTheoreticalHistogram(QCustomPlot* grap,const std::vector<double>& values);
    void DrawToHistogram(QCustomPlot* grap,const std::unordered_map<int,double>& histogram);

    void PrepareHistogram();
    void DrawKHistogram();


    void AnalizeVertices();

    void Reset();

private slots:
    void on_VAnalyzeBtn_clicked();

    void on_XAxisLogScalChb_clicked();

    void on_YAxisLogScalChb_clicked();
    void on_actionSave_as_triggered();

protected:
    void ResetHistogram(QCustomPlot* grap);
    void SetupAxis(QCPAxis * axis,bool isLog)const;
    void CreateLegend(QCustomPlot* grap)const;
    void SaveHistogram(QString const& filename)const;

private:
    Ui::KHistogramWindow *ui;

    std::unordered_map<int,double> m_KHistogram;
    std::vector<double> m_KTheoretical;
};

#endif // KHISTOGRAMWINDOW_H
