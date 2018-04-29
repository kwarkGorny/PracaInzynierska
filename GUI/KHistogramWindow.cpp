#include "KHistogramWindow.h"
#include "Patterns/Utils.h"
#include "Patterns/fileoperation.h"
#include<iostream>
#include<chrono>
KHistogramWindow::KHistogramWindow(QWidget *parent) :   QMainWindow(parent),  ui(new Ui::KHistogramWindow) ,m_KHistogram{},m_KTheoretical{}
{
    ui->setupUi(this);
    this->setWindowTitle("K Histogram Graph");
    menuBar()->setNativeMenuBar(false);

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

   //std::cout << "sum of all k :" <<Statistics::AccumulateHistogram(m_KHistogram);
   Statistics::NormalizeHistogram(m_KHistogram);

   m_KTheoretical = DATA.GetKDistribution()->GetTheoretical(DATA.GetHyperGraph().size());


   FileOperation::SaveToFile("KDistribution.txt",m_KHistogram);
   FileOperation::SaveToFile("KDistributionTheo.txt",m_KTheoretical);

   const double averageTeo = DATA.GetKDistribution()->GetAverage();
   const double medianTeo = DATA.GetKDistribution()->GetMedian();
   const double standDevTeo = DATA.GetKDistribution()->GetStandDev();

   ui->VMeanTheoL->setText(QString::number(averageTeo));
   ui->VMedianTheoL->setText(QString::number(medianTeo));
   ui->VStandDevTheoL->setText(QString::number(standDevTeo));

   const double d =(m_KHistogram.size()-2);
   const double averageK = Statistics::CalculateAverage(DATA.GetKTable());
   const double medianK = Statistics::CalculateMedian(DATA.GetKTable());
   const double standDevK = Statistics::CalculateStandardDeviations(DATA.GetKTable(),averageK);
   ui->VAverageKL->setText(QString::number(averageK));
   ui->VMedianKL->setText(QString::number(medianK));
   ui->VStandDevKL->setText(QString::number(standDevK));
   ui->KFredomDegreeL->setText(QString::number(d));

   const double chiSquare = Statistics::ChiSquareTest( m_KHistogram , m_KTheoretical) * DATA.GetHyperGraph().GetNumberOfVertices()/d;
   std::cout<<"k chi square :" << chiSquare << " d = " << d <<std::endl ;
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
    QCPGraph * kPlot = ui->kPlotWidget->addGraph();
    kPlot->setPen(QPen(Qt::blue));
    kPlot->setLineStyle(QCPGraph::LineStyle::lsNone);
    kPlot->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));
    kPlot->setName("Hypergraph k Distribution");

    QCPGraph * TheokPlot = ui->kPlotWidget->addGraph();
    TheokPlot->setPen(QPen(Qt::red));
    TheokPlot->setLineStyle(QCPGraph::LineStyle::lsLine);
    TheokPlot->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3));
    TheokPlot->setName("Theoretical k Distribution");

    ui->kPlotWidget->xAxis->setLabel("k");
    ui->kPlotWidget->yAxis->setLabel("P(k)");
    ui->kPlotWidget->yAxis->setRange(0,1);

    CreateLegend(ui->kPlotWidget);
}


void KHistogramWindow::DrawToHistogram(QCustomPlot* grap,const std::unordered_map<int,double>& histogram)
{
    QVector<double> x,y;
    std::tie(x,y) =Utils::ToQVector(histogram);

    //auto maxp= *std::max_element(x.begin(),x.end());
   // auto max= *std::max_element(y.begin(),y.end());

    grap->graph(0)->setData(x, y);
    //grap->xAxis->setRange(0, 1.1 * maxp);
   // grap->yAxis->setRange(0, 1.1 * max);
    //grap->xAxis->rescale();
    grap->xAxis->rescale();
    grap->yAxis->rescale();
    grap->replot();
}

void KHistogramWindow::DrawTheoreticalHistogram(QCustomPlot* grap,const std::vector<double>& values)
{
    QVector<double> x,y;

    std::tie(x,y) =Utils::ToQVector(values);

    grap->graph(1)->setData(x, y);
    grap->xAxis->rescale();
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
void KHistogramWindow::ResetHistogram(QCustomPlot* grap)
{
    grap->graph(0)->setData({},{});
    grap->graph(1)->setData({},{});
    grap->replot();
}
void KHistogramWindow::CreateLegend(QCustomPlot* grap)const
{
    grap->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(9);
    grap->legend->setFont(legendFont);
    grap->legend->setBrush(QBrush(QColor(255,255,255,230)));
}
void KHistogramWindow::SaveHistogram(QString const& filename)const
{
    QFile file(filename + ".png");
    if (!file.open(QIODevice::WriteOnly|QFile::WriteOnly))
    {
        QMessageBox::warning(0,"Could not create Project File",QObject::tr( "\n Could not create Project File on disk"));
    }
    else
    {
        ui->kPlotWidget->savePng( filename + ".png",  0, 0, 1.0, -1  );
    }
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

void KHistogramWindow::on_actionSave_as_triggered()
{
    const QString fileName = QFileDialog::getSaveFileName(this,"Save p distribution as ...",QDir::homePath());
    SaveHistogram(fileName);
}
