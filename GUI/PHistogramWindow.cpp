#include "PHistogramWindow.h"

#include"HyperGraph/HyperGraphManager.h"
#include"Patterns/Statistics.h"
#include "Patterns/Data.h"
#include "Patterns/Utils.h"
#include "Patterns/fileoperation.h"

#include<iostream>
#include<chrono>

PHistogramWindow::PHistogramWindow(QWidget *parent) :   QMainWindow(parent), ui(new Ui::PHistogramWindow),m_PHistogram{},m_PTheoretical{}
{
    ui->setupUi(this);
    this->setWindowTitle("P Histogram Graph");
    menuBar()->setNativeMenuBar(false);

    PrepareHistogram();

}

PHistogramWindow::~PHistogramWindow()
{
    delete ui;
}

void PHistogramWindow::PrepareHistogram()
{
    QCPGraph * pPlot = ui->pPlotWidget->addGraph();
    pPlot->setPen(QPen(Qt::blue));
    pPlot->setLineStyle(QCPGraph::LineStyle::lsNone);
    pPlot->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));
    pPlot->setName("Hypergraph p Distribution");

    QCPGraph * TheopPlot =ui->pPlotWidget->addGraph();
    TheopPlot->setPen(QPen(Qt::red));
    TheopPlot->setLineStyle(QCPGraph::LineStyle::lsLine);
    TheopPlot->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3));
    TheopPlot->setName("Theoretical p Distribution");

    ui->pPlotWidget->xAxis->setLabel("p");
    ui->pPlotWidget->yAxis->setLabel("P(p)");
    ui->pPlotWidget->yAxis->setRange(0,1);
    CreateLegend(ui->pPlotWidget);
}
void PHistogramWindow::CreateLegend(QCustomPlot* grap)const
{
    grap->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(9);
    grap->legend->setFont(legendFont);
    grap->legend->setBrush(QBrush(QColor(255,255,255,230)));
}

void PHistogramWindow::Reset()
{
    m_PHistogram.clear();
    m_PTheoretical.clear();
}

void PHistogramWindow::AnalizeHyperEdges()
{
    Reset();
    DATA.SetPTable(HyperGraphManager::CalculatePTable(DATA.GetHyperGraph().GetHyperEdgeList()));
    m_PHistogram = Statistics::CalculateHistogram(DATA.GetPTable());

    //std::cout << "sum of all p :" <<Statistics::AccumulateHistogram(m_PHistogram);

    Statistics::NormalizeHistogram(m_PHistogram);

    m_PTheoretical = DATA.GetPDistribution()->GetTheoretical(DATA.GetHyperGraph().size());

    FileOperation::SaveToFile("PDistribution.txt",m_PHistogram);
    FileOperation::SaveToFile("PDistributionTheo.txt",m_PTheoretical);

   // const auto hyperEdgesDuplicates = HyperGraphManager::CalculateHyperedgeDuplicates(DATA.GetHyperGraph().GetHyperEdgeList());
   // HyperGraphManager::ShowHyperedgeDuplicates(hyperEdgesDuplicates);

    const double averageTeo = DATA.GetPDistribution()->GetAverage();
    const double medianTeo = DATA.GetPDistribution()->GetMedian();
    const double standDevTeo = DATA.GetPDistribution()->GetStandDev();
    ui->PMeanTheoL->setText(QString::number(averageTeo));
    ui->PMedianTheoL->setText(QString::number(medianTeo));
    ui->PStandDevTheoL->setText(QString::number(standDevTeo));

    const double d= m_PHistogram.size() - 2;
    const double averageP = Statistics::CalculateAverage(DATA.GetPTable());
    const double medianP = Statistics::CalculateMedian(DATA.GetPTable());
    const double standDevP = Statistics::CalculateStandardDeviations(DATA.GetPTable(),averageP);
    ui->PAveragePL->setText(QString::number(averageP));
    ui->PMedianPL->setText(QString::number(medianP));
    ui->PStandDevPL->setText(QString::number(standDevP));
    ui->PFredomDegreeL->setText(QString::number(d));

    const double chiSquare = Statistics::ChiSquareTest(m_PHistogram,m_PTheoretical ) * DATA.GetHyperGraph().size()/d;
    std::cout<<"p chi square :" << chiSquare <<" d = "<< d <<std::endl;

    const double studentTest = Statistics::TStudentTest(averageTeo,averageP,standDevP, m_PHistogram.size());
    ui->PChiSquareL->setText(QString::number(chiSquare));
    ui->PStudentTestL->setText(QString::number(studentTest));
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
void PHistogramWindow::SaveHistogram(QString const& filename)const
{
    QFile file(filename + ".png");
    if (!file.open(QIODevice::WriteOnly|QFile::WriteOnly))
    {
        QMessageBox::warning(0,"Could not create Project File",QObject::tr( "\n Could not create Project File on disk"));
    }
    else
    {
        ui->pPlotWidget->savePng( filename + ".png",  0, 0, 1.0, -1  );
    }
}
void PHistogramWindow::DrawToHistogram(QCustomPlot* grap,const std::unordered_map<int,double>& histogram)
{
    QVector<double> x;
    QVector<double> y;
    std::tie(x,y) =Utils::ToQVector(histogram);

    //auto maxp= *std::max_element(x.begin(),x.end());
    //auto max= *std::max_element(y.begin(),y.end());

    grap->graph(0)->setData(x, y);

    //grap->xAxis->setRange(0, 1.1 * maxp);
   // grap->yAxis->setRange(0, 1.1 * max);
    grap->xAxis->rescale();
    grap->yAxis->rescale();
    grap->replot();
}

void PHistogramWindow::DrawTheoreticalHistogram(QCustomPlot* grap,const std::vector<double>& values)
{
    QVector<double> x;
    QVector<double> y;
    std::tie(x,y) =Utils::ToQVector(values);

    grap->graph(1)->setData(x, y);
    grap->xAxis->rescale();
    grap->yAxis->rescale();
    grap->replot();
}

void PHistogramWindow::on_HAnalyzeBtn_clicked()
{
    ResetHistogram(ui->pPlotWidget);
    AnalizeHyperEdges();
    DrawPHistogram();
}
void PHistogramWindow::SetupAxis(QCPAxis * axis,bool isLog)const
{
    axis->setScaleType(isLog?QCPAxis::stLogarithmic:QCPAxis::stLinear);
}

void PHistogramWindow::on_XAxisLogScalChb_clicked()
{
    SetupAxis(ui->pPlotWidget->xAxis,ui->XAxisLogScalChb->isChecked());
    ui->pPlotWidget->xAxis->rescale();
}

void PHistogramWindow::on_YAxisLogScalChb_clicked()
{
    SetupAxis(ui->pPlotWidget->yAxis,ui->YAxisLogScalChb->isChecked());
    ui->pPlotWidget->yAxis->rescale();
}

void PHistogramWindow::on_actionSave_as_triggered()
{
    const QString fileName = QFileDialog::getSaveFileName(this,"Save p distribution as ...",QDir::homePath());
    SaveHistogram(fileName);
}
