#include "PHistogramWindow.h"

#include"HyperGraph/HyperGraphManager.h"
#include"Patterns/Statistics.h"
#include "Patterns/Data.h"
#include "Patterns/Utils.h"

#include<iostream>
#include<chrono>

PHistogramWindow::PHistogramWindow(QWidget *parent) :   QMainWindow(parent), ui(new Ui::PHistogramWindow),m_PHistogram{},m_PTheoretical{}
{
    ui->setupUi(this);
    this->setWindowTitle("P Histogram Graph");
    PrepareHistogram();
}

PHistogramWindow::~PHistogramWindow()
{
    delete ui;
}

void PHistogramWindow::PrepareHistogram()
{
  ui->pPlotWidget->addGraph();
  ui->pPlotWidget->graph(0)->setPen(QPen(Qt::blue));
  ui->pPlotWidget->graph(0)->setLineStyle(QCPGraph::LineStyle::lsNone);
  ui->pPlotWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));
  ui->pPlotWidget->addGraph();
  ui->pPlotWidget->graph(1)->setPen(QPen(Qt::red));
  ui->pPlotWidget->graph(1)->setLineStyle(QCPGraph::LineStyle::lsLine);
  ui->pPlotWidget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3));


  ui->pPlotWidget->xAxis->setLabel("p");
  ui->pPlotWidget->yAxis->setLabel("P(p)");
  ui->pPlotWidget->yAxis->setRange(0,1);
}
void PHistogramWindow::Reset()
{
    m_PHistogram.clear();
    m_PTheoretical.clear();
}

void PHistogramWindow::AnalizeHyperEdges()
{
    Reset();
    DATA.SetPTable(HyperGraphManager::CalculatePTable(DATA.GetHyperGraph().GetHyperGraph()));
    m_PHistogram = Statistics::CalculateHistogram(DATA.GetPTable());
    Statistics::NormalizeHistogram(m_PHistogram);

    m_PTheoretical = DATA.GetPDistribution()->GetTheoretical(DATA.GetHyperGraph().size());


    auto hyperEdgesDuplicates = HyperGraphManager::CalculateHyperedgeDuplicates(DATA.GetHyperGraph().GetHyperGraph());
    HyperGraphManager::ShowHyperedgeDuplicates(hyperEdgesDuplicates);

    double averageP = Statistics::CalculateAverage(DATA.GetPTable());
    double standDevP = Statistics::CalculateStandardDeviations(DATA.GetPTable(),averageP);
    double ChiSquare = Statistics::ChiSquareTest(m_PHistogram,m_PTheoretical );

    ui->PAveragePL->setText(QString::number(averageP));
    ui->PStandDevPL->setText(QString::number(standDevP));
    ui->PChiSquareL->setText(QString::number(ChiSquare));
}


void PHistogramWindow::DrawPHistogram()
{
    using namespace std::chrono;

    std::cout<<"Starting Making P Histogram "<<std::endl;
    //auto begin = steady_clock::now();


    DrawToHistogram(ui->pPlotWidget,m_PHistogram);
    DrawTheoreticalHistogram(ui->pPlotWidget,m_PTheoretical);

    //ShowTime("Drawing P Histogram took",begin);
}

void PHistogramWindow::ResetHistogram(QCustomPlot* grap)
{
    grap->graph(0)->setData({},{});
    grap->graph(1)->setData({},{});
    grap->replot();
}

void PHistogramWindow::DrawToHistogram(QCustomPlot* grap,const std::unordered_map<int,double>& histogram)
{
    QVector<double> x;
    QVector<double> y;
    std::tie(x,y) =Utils::ToQVector(histogram);

    auto maxp= *std::max_element(x.begin(),x.end());
    auto max= *std::max_element(y.begin(),y.end());

    grap->graph(0)->setData(x, y);
    grap->xAxis->setRange(0, 1.1 * maxp);
    grap->yAxis->setRange(0, 1.1 * max);
    grap->replot();
}

void PHistogramWindow::DrawTheoreticalHistogram(QCustomPlot* grap,const std::vector<double>& values)
{
    QVector<double> x;
    QVector<double> y;
    std::tie(x,y) =Utils::ToQVector(values);

    grap->graph(1)->setData(x, y);
    grap->replot();
}

void PHistogramWindow::on_HAnalyzeBtn_clicked()
{
    ResetHistogram(ui->pPlotWidget);
    AnalizeHyperEdges();
    DrawPHistogram();
}
