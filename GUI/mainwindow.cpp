#include "mainwindow.h"


#include"AdjacencyList/AdjacencyListManager.h"
#include"AdjacencyList/AdjacencyListFabric.h"
#include"Patterns/Statistics.h"
#include"Patterns/Data.h"

#include"Distributions/geometric.h"
#include"Distributions/uniform.h"
#include"Distributions/poisson.h"
#include"Distributions/constant.h"
#include"Distributions/pareto.h"

#include<iostream>




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Hypergraph Drawer");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ShowTime(const std::string& nameOfFun,time_point<steady_clock> begin,time_point<steady_clock> end)
{
    std::cout << nameOfFun<<" = "<< duration_cast<milliseconds>(end - begin).count()<< "ms";
    std::cout << " | "<< duration_cast<microseconds>(end -begin).count()<< "us";
    std::cout<<std::endl;
}


void MainWindow::RandomHypergraphAlgorithm()
{
    int numberOfVertices{ui->VAmountS->value()};

    SelectKDstribution();
    SelectPDstribution();

    auto begin=steady_clock::now();

    DATA.SetHyperGraph(AdjacencyListFabric::CreateRandomAdjacencyList(numberOfVertices,*DATA.GetKDistribution(),*DATA.GetPDistribution()));

    ShowTime("Algorithm took ",begin);
}



void MainWindow::AnalizeHyperGraph()
{
   auto begin=steady_clock::now();
   ShowTime("Analyze took ",begin);
}
void MainWindow::on_pushButton_5_clicked()
{
    HyperGraphDrawDialog* drawer = new HyperGraphDrawDialog (this);
    drawer->show();
}

void MainWindow::on_PlotKHistogramBtn_clicked()
{
    if(DATA.GetKDistribution())
    {
        if(m_KHistogram)
        {
            if(m_KHistogram->isVisible())
            {
                return;
            }
        }
        m_KHistogram.reset(new KHistogramWindow (this));
        m_KHistogram->show();
    }
}

void MainWindow::on_PlotPHistogramBtn_clicked()
{
    if(DATA.GetPDistribution())
    {
        if(m_PHistogram)
        {
            if(m_PHistogram->isVisible())
            {
                return;
            }
        }
        m_PHistogram.reset(new PHistogramWindow (this));
        m_PHistogram->show();
    }
}
void MainWindow::on_StartBtn_clicked()
{
    if(m_AlgorithmStarted)
    {
        return;
    }
    else
    {
        m_AlgorithmStarted=true;
    }

    ChooseAndRunAlgorithm();

    std::cout<<"Number of Vertices : "<< DATA.GetHyperGraph().GetNumberOfVertices() <<" Number of Hyperedges : "<<DATA.GetHyperGraph().size()<<std::endl;
    std::cout<<"End of Simulation\n"<<std::endl;

    //AdjacencyListManager::AdjacenyListToFile(*m_HyperGraph,"hypergraph1.txt");
    //AnalizeHyperGraph();
    m_AlgorithmStarted=false;
}

void MainWindow::SelectKDstribution()
{
    switch(ui->VDistributionCB->currentIndex())
    {
        case DISTRIBUTION::CONST:
           DATA.SetKDistribution(new Constant(ui->VAverageDegreeS->value()));
        break;
        case DISTRIBUTION::UNIFORM:
        {
            int min = ui->VMaxDegreeS->value()>ui->VMinDegreeS->value()?ui->VMinDegreeS->value():ui->VMaxDegreeS->value();
            int max = ui->VMaxDegreeS->value()<=ui->VMinDegreeS->value()?ui->VMinDegreeS->value():ui->VMaxDegreeS->value();
             DATA.SetKDistribution(new Uniform (min,max));
        }
        break;
        case DISTRIBUTION::POISSON:
        {
             DATA.SetKDistribution(new Poisson(ui->VAverageDegreeS->value()));
        }
        break;
        case DISTRIBUTION::GEOMETRIC:
        {
             DATA.SetKDistribution(new Geometric(ui->VDistributionParamDSP->value()));
        }
        break;
        case DISTRIBUTION::PARETO:
        {
            //m_PDistribution.reset(new Pareto());
        }
        break;
    }
}
void MainWindow::SelectPDstribution()
{
    switch(ui->HDistributionCB->currentIndex())
    {
        case DISTRIBUTION::CONST:
             DATA.SetPDistribution(new Constant(ui->HAverageDegreeS->value()));
        break;
        case DISTRIBUTION::UNIFORM:
        {
            int min = ui->HMaxDegreeS->value()>ui->HMinDegreeS->value()?ui->HMinDegreeS->value():ui->HMaxDegreeS->value();
            int max = ui->HMaxDegreeS->value()<=ui->HMinDegreeS->value()?ui->HMinDegreeS->value():ui->HMaxDegreeS->value();
             DATA.SetPDistribution(new Uniform(min,max));
        }
        break;
        case DISTRIBUTION::POISSON:
        {
             DATA.SetPDistribution(new Poisson(ui->HAverageDegreeS->value()));
        }
        break;
        case DISTRIBUTION::GEOMETRIC:
        {
             DATA.SetPDistribution(new Geometric(ui->HDistributionParamDSB->value()));
        }
        break;
        case DISTRIBUTION::PARETO:
        {
            //m_PDistribution.reset(new Pareto());
        }
        break;
    }
}
void MainWindow::ChooseAndRunAlgorithm()
{
    switch(ui->AlgorithmsCB->currentIndex())
    {
        case ALGORITHM::RANDOM_HYPERGRAPH:
            std::cout<<"Random Hypergraph Algorithm"<<std::endl;
            RandomHypergraphAlgorithm();

        break;
        case ALGORITHM::FULL_HYPERGRAPH:
            std::cout<<"Full Hypergraph Algorithm"<<std::endl;
        break;
        case ALGORITHM::TEST:
            std::cout<<"Test Algorithm"<<std::endl;
        break;
        default:
            std::cout<<"Error non such algorithm"<<std::endl;
        break;
    }
}
void MainWindow::on_AlgorithmsCB_currentIndexChanged(int index)
{
    std::cout<< "Algorithm ComboBox :";
    switch(index)
    {
        case ALGORITHM::RANDOM_HYPERGRAPH:
            std::cout<<" Random Hypergraph "<<std::endl;
            ui->VDistributionCB->setEnabled(true);
            ui->VAverageDegreeS->setEnabled(true);
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->HDistributionCB->setEnabled(true);
            ui->HDistributionCB->setCurrentIndex(DISTRIBUTION::CONST);
            ui->VDistributionCB->setCurrentIndex(DISTRIBUTION::CONST);
        break;
        case ALGORITHM::FULL_HYPERGRAPH:
            std::cout<<" Full Hypergraph "<<std::endl;
            ui->VDistributionCB->setEnabled(false);
            ui->VAverageDegreeS->setEnabled(false);
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->HDistributionCB->setEnabled(false);
            ui->HDistributionCB->setCurrentIndex(DISTRIBUTION::CONST);
            ui->VDistributionCB->setCurrentIndex(DISTRIBUTION::CONST);
        break;
        case ALGORITHM::TEST:
            std::cout<<" Test Hypergraph "<<std::endl;
        break;
        default:
            std::cerr<<" Error out of bound "<<std::endl;
        break;
    }
}

void MainWindow::on_VDistributionCB_currentIndexChanged(int index)
{
    std::cout<<"Vertex Distribution ComboBox : ";
    switch(index)
    {
        case DISTRIBUTION::CONST:
            std::cout<<"Constant"<<std::endl;
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->VAverageDegreeS->setEnabled(true);
            ui->VDistributionParamDSP->setEnabled(false);
            ui->VAvarageDegreeL->setText("Average Degree :");
        break;
        case DISTRIBUTION::UNIFORM:
            std::cout<<"Uniform"<<std::endl;
            ui->VMaxDegreeS->setEnabled(true);
            ui->VMinDegreeS->setEnabled(true);
            ui->VAverageDegreeS->setEnabled(false);
            ui->VDistributionParamDSP->setEnabled(false);
            ui->VAvarageDegreeL->setText("Average Degree :");
        break;
        case DISTRIBUTION::POISSON:
            std::cout<<"Poisson"<<std::endl;
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->VDistributionParamDSP->setEnabled(false);
            ui->VAverageDegreeS->setEnabled(true);
            ui->VAvarageDegreeL->setText("Average Degree :");
        break;
        case DISTRIBUTION::GEOMETRIC:
            std::cout<<"GEOMETRIC"<<std::endl;
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->VAverageDegreeS->setEnabled(false);
            ui->VDistributionParamDSP->setEnabled(true);
            ui->VAvarageDegreeL->setText("Lambda :");
        break;
        case DISTRIBUTION::PARETO:
            std::cout<<"PARETO"<<std::endl;
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->VAverageDegreeS->setEnabled(true);
            ui->VDistributionParamDSP->setEnabled(true);
            ui->VAvarageDegreeL->setText("Lambda :");
        break;
        default:
            std::cerr<<"Error out of bound"<<std::endl;
        break;
    }
}

void MainWindow::on_HDistributionCB_currentIndexChanged(int index)
{
    std::cout<<"Hyperedge Distribution ComboBox : ";

    switch(index)
    {
        case DISTRIBUTION::CONST:
            std::cout<<"Constant"<<std::endl;
            ui->HMaxDegreeS->setEnabled(false);
            ui->HMinDegreeS->setEnabled(false);
            ui->HDistributionParamDSB->setEnabled(false);
            ui->HAverageDegreeS->setEnabled(true);
            ui->HAverageDegreeL->setText("Average Degree :");
        break;
        case DISTRIBUTION::UNIFORM:
            std::cout<<"Uniform"<<std::endl;
            ui->HMaxDegreeS->setEnabled(true);
            ui->HMinDegreeS->setEnabled(true);
            ui->HDistributionParamDSB->setEnabled(false);
            ui->HAverageDegreeS->setEnabled(false);
            ui->HAverageDegreeL->setText("Average Degree :");
        break;
        case DISTRIBUTION::POISSON:
            std::cout<<"Poisson"<<std::endl;
            ui->HMaxDegreeS->setEnabled(false);
            ui->HMinDegreeS->setEnabled(false);
            ui->HDistributionParamDSB->setEnabled(false);
            ui->HAverageDegreeS->setEnabled(true);
            ui->HAverageDegreeL->setText("Average Degree :");
        break;
        case DISTRIBUTION::GEOMETRIC:
            std::cout<<"GEOMETRIC"<<std::endl;
            ui->HMaxDegreeS->setEnabled(false);
            ui->HMinDegreeS->setEnabled(false);
            ui->HAverageDegreeS->setEnabled(false);
            ui->HDistributionParamDSB->setEnabled(true);
            ui->HAverageDegreeL->setText("Lambda :");
        break;
        case DISTRIBUTION::PARETO:
            std::cout<<"PARETO"<<std::endl;
            ui->HMaxDegreeS->setEnabled(false);
            ui->HMinDegreeS->setEnabled(false);
            ui->HAverageDegreeS->setEnabled(true);
            ui->HDistributionParamDSB->setEnabled(true);
            ui->HAverageDegreeL->setText("Lambda :");
            ui->HDistributionParamL->setText("Scale :");

        break;
        default:
            std::cerr<<"Error out of bound"<<std::endl;
        break;
    }
}


