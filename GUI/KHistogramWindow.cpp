#include "KHistogramWindow.h"
#include "Patterns/Utils.h"

#include<iostream>
#include<chrono>
KHistogramWindow::KHistogramWindow(QWidget *parent) :   QMainWindow(parent),  ui(new Ui::KHistogramWindow) ,m_KHistogram{},m_KTheoretical{}
{
    ui->setupUi(this);
    this->setWindowTitle("K Histogram Graph");
    PrepareHistogram();
}

KHistogramWindow::~KHistogramWindow()
{
    delete ui;
}

void KHistogramWindow::AnalizeVertices()
{
   Reset();
   DATA.SetKTable(HyperGraphManager::CalculateKTable(DATA.GetHyperGraph()));

   m_KHistogram = Statistics::CalculateHistogram(DATA.GetKTable());

   Statistics::NormalizeHistogram(m_KHistogram);

   m_KTheoretical = DATA.GetKDistribution()->GetTheoretical(DATA.GetHyperGraph().size());

   const double averageTeo = DATA.GetKDistribution()->GetAverage();
   const double medianTeo = DATA.GetKDistribution()->GetMedian();
   //const double standDevTeo = DATA.GetKDistribution()->GetStdev();
   ui->VMeanTheoL->setText(QString::number(averageTeo));
   ui->VMedianTheoL->setText(QString::number(medianTeo));
   //ui->VStandDevKL->setText(QString::number(standDevTeo));

   const double averageK = Statistics::CalculateAverage(DATA.GetKTable());
   const double medianK = Statistics::CalculateMedian(DATA.GetKTable());
   const double standDevK = Statistics::CalculateStandardDeviations(DATA.GetKTable(),averageK);
   ui->VAverageKL->setText(QString::number(averageK));
   ui->VMedianKL->setText(QString::number(medianK));
   ui->VStandDevKL->setText(QString::number(standDevK));

   const double chiSquare = Statistics::ChiSquareTest( m_KHistogram , m_KTheoretical);
   const double studentTest = Statistics::TStudentTest(averageTeo,averageK,standDevK, m_KTheoretical.size());
   ui->VChiSquareL->setText(QString::number(chiSquare));
   ui->VStudentTestL->setText(QString::number(studentTest));
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
    std::tie(x,y) =Utils::ToQVector(histogram);

   // auto maxp= *std::max_element(x.begin(),x.end());
    //auto max= *std::max_element(y.begin(),y.end());

    grap->graph(0)->setData(x, y);
    //grap->xAxis->setRange(0, 1.1 * maxp);
   // grap->yAxis->setRange(0, 1.1 * max);
    grap->xAxis->rescale();

    grap->replot();
}

void KHistogramWindow::DrawTheoreticalHistogram(QCustomPlot* grap,const std::vector<double>& values)
{
    QVector<double> x;
    QVector<double> y;
    std::tie(x,y) =Utils::ToQVector(values);

    grap->graph(1)->setData(x, y);
    grap->yAxis->rescale();
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
void KHistogramWindow::SetupAxis(QCPAxis * axis,bool isLog)const
{
    axis->setScaleType(isLog?QCPAxis::stLogarithmic:QCPAxis::stLinear);
}
void KHistogramWindow::on_XAxisLogScalChb_clicked()
{
    SetupAxis(ui->kPlotWidget->xAxis,ui->XAxisLogScalChb->isChecked());
    ui->kPlotWidget->xAxis->rescale();
}

void KHistogramWindow::on_YAxisLogScalChb_clicked()
{
    SetupAxis(ui->kPlotWidget->yAxis,ui->YAxisLogScalChb->isChecked());
    ui->kPlotWidget->yAxis->rescale();
}
