#include "KHistogramWindow.h"

#include<iostream>
#include<chrono>
KHistogramWindow::KHistogramWindow(QWidget *parent) :   QMainWindow(parent),  ui(new Ui::KHistogramWindow) ,m_KHistogram{},m_KTheoretical{}

{
    ui->setupUi(this);
    PrepareHistogram();
}

KHistogramWindow::~KHistogramWindow()
{
    delete ui;
}


void KHistogramWindow::AnalizeVertices()
{
   Reset();
   DATA.SetKTable(AdjacencyListManager::CalculateKTable(DATA.GetHyperGraph()));
   m_KHistogram = Statistics::CalculateHistogram(DATA.GetKTable());
   Statistics::NormalizeHistogram(m_KHistogram);

   auto maxp= *std::max_element(DATA.GetKTable().begin(),DATA.GetKTable().end());

   m_KTheoretical = DATA.GetKDistribution()->GetTheoretical(DATA.GetHyperGraph().size());

   double averageK = Statistics::CalculateAverage(DATA.GetKTable());
   double standDevK = Statistics::CalculateStandardDeviations(DATA.GetKTable(),averageK);
   double ChiSquare = Statistics::ChiSquareTest( m_KHistogram , m_KTheoretical);

   ui->VAverageKL->setText(QString::number(averageK));
   ui->VStandDevKL->setText(QString::number(standDevK));
   ui->VChiSquareL->setText(QString::number(ChiSquare));
}
void KHistogramWindow::DrawKHistogram()
{
    using namespace std::chrono;
    std::cout<<"Starting Making K Histogram "<<std::endl;
    //auto begin = steady_clock::now();

    DrawToHistogram(ui->kPlotWidget,m_KHistogram);
    DrawTheoreticalHistogram(ui->kPlotWidget,m_KTheoretical);

    //ShowTime("Drawing K Histogram took",begin);
}
void KHistogramWindow::PrepareHistogram()
{
  ui->kPlotWidget->addGraph();
  ui->kPlotWidget->graph(0)->setPen(QPen(Qt::blue));
  ui->kPlotWidget->graph(0)->setLineStyle(QCPGraph::LineStyle::lsNone);
  ui->kPlotWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));

  ui->kPlotWidget->addGraph();
  ui->kPlotWidget->graph(1)->setPen(QPen(Qt::red));
  ui->kPlotWidget->graph(1)->setLineStyle(QCPGraph::LineStyle::lsLine);
  ui->kPlotWidget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3));

  ui->kPlotWidget->xAxis->setLabel("k");
  ui->kPlotWidget->yAxis->setLabel("P(k)");
  ui->kPlotWidget->yAxis->setRange(0,1);
}


void KHistogramWindow::ResetHistogram(QCustomPlot* grap)
{
    grap->graph(0)->setData({},{});
    grap->graph(1)->setData({},{});
    grap->replot();
}

void KHistogramWindow::DrawToHistogram(QCustomPlot* grap,const std::unordered_map<int,double>& histogram)
{
    QVector<double> x;
    QVector<double> y;
    x.reserve(histogram.size());
    y.reserve(histogram.size());

    for (const auto& value : histogram)
    {
      x.push_back(value.first);
      y.push_back(value.second);
    }
    auto maxp= *std::max_element(x.begin(),x.end());
    auto max= *std::max_element(y.begin(),y.end());

    grap->graph(0)->setData(x, y);
    grap->xAxis->setRange(0, 1.1 * maxp);
    grap->yAxis->setRange(0, 1.1 * max);
    grap->replot();
}
void KHistogramWindow::DrawTheoreticalHistogram(QCustomPlot* grap,const std::vector<double>& values)
{
    QVector<double> x;
    QVector<double> y;
    x.reserve(values.size());
    y.reserve(values.size());

    for (size_t i=0;i<values.size();++i)
    {
      if(values[i] != 0)
      {
        x.push_back(i);
        y.push_back(values[i]);
      }
    }

    grap->graph(1)->setData(x, y);
    grap->replot();
}

void KHistogramWindow::on_VAnalyzeBtn_clicked()
{
    ResetHistogram(ui->kPlotWidget);
    AnalizeVertices();
    DrawKHistogram();
}
void KHistogramWindow::Reset()
{
    m_KHistogram.clear();
    m_KTheoretical.clear();
}
