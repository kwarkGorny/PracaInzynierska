#include "mainwindow.h"

#include"AdjacencyList/AdjacencyListManager.h"
#include"AdjacencyList/AdjacencyListFabric.h"
#include"Patterns/Statistics.h"

#include"Distributions/geometric.h"
#include"Distributions/uniform.h"
#include"Distributions/poisson.h"
#include"Distributions/constant.h"

#include<iostream>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Rysownik HiperGrafu");
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

    m_HyperGraph = AdjacencyListFabric::CreateRandomAdjacencyList(numberOfVertices, *m_PDistribution, *m_KDistribution);

    ShowTime("Algorithm took ",begin);
}



void MainWindow::AnalizeHyperGraph()
{
   auto begin=steady_clock::now();
   ShowTime("Analyze took ",begin);
}
void MainWindow::on_pushButton_5_clicked()
{
    AnalizeHyperGraph();
}

void MainWindow::on_PlotKHistogramBtn_clicked()
{
    if(m_KDistribution)
    {
        m_KHistogram.reset(new KHistogramWindow (&m_HyperGraph,m_KDistribution.get(),this));
        m_KHistogram->show();
    }
}

void MainWindow::on_PlotPHistogramBtn_clicked()
{
    if(m_PDistribution)
    {
        m_PHistogram.reset(new PHistogramWindow (&m_HyperGraph,m_PDistribution.get(),this));
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

    std::cout<<"Number of Vertices : "<< m_HyperGraph.GetNumberOfVertices() <<" Number of Hyperedges : "<<m_HyperGraph.size()<<std::endl;
    std::cout<<"End of Simulation\n"<<std::endl;

    //AdjacencyListManager::AdjacenyListToFile(*m_HyperGraph,"papiez1.txt");
    //AnalizeHyperGraph();
    m_AlgorithmStarted=false;
}

void MainWindow::SelectKDstribution()
{
    switch(ui->VDistributionCB->currentIndex())
    {
        case DISTRIBUTION::CONST:
            m_KDistribution.reset(new Constant(ui->VAverageDegreeS->value()));
        break;
        case DISTRIBUTION::UNIFORM:
        {
            int min = ui->VMaxDegreeS->value()>ui->VMinDegreeS->value()?ui->VMinDegreeS->value():ui->VMaxDegreeS->value();
            int max = ui->VMaxDegreeS->value()<=ui->VMinDegreeS->value()?ui->VMinDegreeS->value():ui->VMaxDegreeS->value();
            m_KDistribution.reset(new Uniform (min,max));
        }
        break;
        case DISTRIBUTION::POISSON:
        {
            m_KDistribution.reset(new Poisson(ui->VAverageDegreeS->value()));
        }
        break;
        case DISTRIBUTION::GEOMETRIC:
        {
            m_KDistribution.reset(new Geometric(ui->VDistributionParamDSP->value()));
        }
        break;
    }
    if(m_KHistogram)
    {
        m_KHistogram->SetKDistribution(m_KDistribution.get());
    }
}
void MainWindow::SelectPDstribution()
{
    switch(ui->HDistributionCB->currentIndex())
    {
        case DISTRIBUTION::CONST:
            m_PDistribution.reset(new Constant(ui->HAverageDegreeS->value()));
        break;
        case DISTRIBUTION::UNIFORM:
        {
            int min = ui->HMaxDegreeS->value()>ui->HMinDegreeS->value()?ui->HMinDegreeS->value():ui->HMaxDegreeS->value();
            int max = ui->HMaxDegreeS->value()<=ui->HMinDegreeS->value()?ui->HMinDegreeS->value():ui->HMaxDegreeS->value();
             m_PDistribution.reset(new Uniform(min,max));
        }
        break;
        case DISTRIBUTION::POISSON:
        {
             m_PDistribution.reset(new Poisson(ui->HAverageDegreeS->value()));
        }
        break;
        case DISTRIBUTION::GEOMETRIC:
        {
             m_PDistribution.reset(new Geometric(ui->HDistributionParamDSB->value()));
        }
        break;
    }
    if(m_PHistogram)
    {
        m_PHistogram->SetPDistribution(m_PDistribution.get());
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
        case DISTRIBUTION::BINOMIAL:
            std::cout<<"BINOMIAL"<<std::endl;
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
        case DISTRIBUTION::BINOMIAL:
            std::cout<<"BINOMIAL"<<std::endl;
            ui->HMaxDegreeS->setEnabled(false);
            ui->HMinDegreeS->setEnabled(false);
            ui->HAverageDegreeS->setEnabled(true);
            ui->HDistributionParamDSB->setEnabled(true);
            ui->HAverageDegreeL->setText("Average Degree :");
        break;
        default:
            std::cerr<<"Error out of bound"<<std::endl;
        break;
    }
}


