#include "mainwindow.h"


#include"HyperGraph/HyperGraphManager.h"
#include"HyperGraph/HyperGraphFabric.h"
#include"Patterns/Statistics.h"
#include"Patterns/Data.h"

#include"Distributions/geometric.h"
#include"Distributions/uniform.h"
#include"Distributions/poisson.h"
#include"Distributions/constant.h"
#include"Distributions/powerlaw.h"

#include<iostream>

#include<QFileDialog>
#include<QDir>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) , m_ActualState(APPLICATION_STATE_NONE)
{
    ui->setupUi(this);
    this->setWindowTitle("Random Hypergraph Builder");
    menuBar()->setNativeMenuBar(false);

    ui->ChooseAlgorithmFrame->setEnabled(false);
    ui->VertexFrame->setEnabled(false);
    ui->HyperEdgeFrame->setEnabled(false);
    ui->CreateHypergraphFrame->setEnabled(false);
    ui->AdditionalOptionFrame->setEnabled(false);
    ChangeApplicationState(APPLICATION_STATE_CHOOSE_ALGORITHM);
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
    if(DATA.GetPDistribution()->IsValid() && DATA.GetKDistribution()->IsValid())
    {
        const int numberOfVertices = ui->VAmountS->value();
        auto begin=steady_clock::now();

        if(ui->VUseLoadedChB->isEnabled() && ui->VUseLoadedChB->isCheckable() && ui->VUseLoadedChB->isChecked())
        {
            DATA.SetHyperGraph(HyperGraphFabric::CreateRandomHyperGraph(m_LoadedKTable,*DATA.GetPDistribution()));
        }
        else
        {
            DATA.SetHyperGraph(HyperGraphFabric::CreateRandomHyperGraph(numberOfVertices,*DATA.GetKDistribution(),*DATA.GetPDistribution()));
        }
        ShowTime("Algorithm took ",begin);
    }
    else
    {
        std::cerr<<"P Distribution is " << (DATA.GetPDistribution()->IsValid()? "valid" : "not valid") << std::endl;
        std::cerr<<"K Distribution is " << (DATA.GetKDistribution()->IsValid()? "valid" : "not valid") << std::endl;
    }
}

void MainWindow::AnalizeHyperGraph()
{
   auto begin=steady_clock::now();
   ShowTime("Analyze took ",begin);
}

void MainWindow::ChangeApplicationState(APPLICATION_STATE newState)
{
    OnStateLeave(m_ActualState);
    m_ActualState = newState;
    OnStateEnter(m_ActualState);
}

void MainWindow::OnStateEnter(APPLICATION_STATE newState)
{
    switch(newState)
    {
    case APPLICATION_STATE::APPLICATION_STATE_CHOOSE_ALGORITHM:
        ui->ChooseAlgorithmFrame->setEnabled(true);
        ui->VertexFrame->setEnabled(false);
        ui->HyperEdgeFrame->setEnabled(false);
        ui->CreateHypergraphFrame->setEnabled(false);
        ui->AdditionalOptionFrame->setEnabled(false);

    break;
    case APPLICATION_STATE::APPLICATION_STATE_CHOOSE_VERTEX_DISTRIBUTION:
        ui->ChooseAlgorithmFrame->setEnabled(true);
        ui->VertexFrame->setEnabled(true);
        ui->HyperEdgeFrame->setEnabled(false);
        ui->CreateHypergraphFrame->setEnabled(false);
        ui->AdditionalOptionFrame->setEnabled(false);
    break;
    case APPLICATION_STATE::APPLICATION_STATE_CHOOSE_HYPEREDGE_DISTRIBUTION:
        ui->ChooseAlgorithmFrame->setEnabled(true);
        ui->VertexFrame->setEnabled(true);
        ui->HyperEdgeFrame->setEnabled(true);
        ui->CreateHypergraphFrame->setEnabled(false);
        ui->AdditionalOptionFrame->setEnabled(false);
    break;
    case APPLICATION_STATE::APPLICATION_STATE_CREATE_HYPERGRAPH:
        ui->ChooseAlgorithmFrame->setEnabled(true);
        ui->VertexFrame->setEnabled(true);
        ui->HyperEdgeFrame->setEnabled(true);
        ui->CreateHypergraphFrame->setEnabled(true);
        ui->AdditionalOptionFrame->setEnabled(false);
    break;
    case APPLICATION_STATE::APPLICATION_STATE_ADDITIONAL_OPTION:
        ui->ChooseAlgorithmFrame->setEnabled(true);
        ui->VertexFrame->setEnabled(true);
        ui->HyperEdgeFrame->setEnabled(true);
        ui->CreateHypergraphFrame->setEnabled(true);
        ui->AdditionalOptionFrame->setEnabled(true);
    break;
    default:

    break;
    }
}

void MainWindow::OnStateLeave(APPLICATION_STATE preState)
{
    switch(preState)
    {
    case APPLICATION_STATE::APPLICATION_STATE_CHOOSE_ALGORITHM:
        break;
    case APPLICATION_STATE::APPLICATION_STATE_CHOOSE_VERTEX_DISTRIBUTION:
        break;
    case APPLICATION_STATE::APPLICATION_STATE_CHOOSE_HYPEREDGE_DISTRIBUTION:
        break;
    case APPLICATION_STATE::APPLICATION_STATE_CREATE_HYPERGRAPH:
        break;
    case APPLICATION_STATE::APPLICATION_STATE_ADDITIONAL_OPTION:
        break;
    default:

    break;
    }
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

void MainWindow::on_VCheckBtn_clicked()
{
    SelectKDstribution();
    if(DATA.GetKDistribution()->IsValid())
    {
        ChangeApplicationState(APPLICATION_STATE_CHOOSE_HYPEREDGE_DISTRIBUTION);
    }
    else
    {
        std::cerr<<"K Distribution in not valid"<<std::endl;
    }
}

void MainWindow::on_HCheckBtn_clicked()
{
    SelectPDstribution();
    if(DATA.GetPDistribution()->IsValid())
    {
        ChangeApplicationState(APPLICATION_STATE_CREATE_HYPERGRAPH);
    }
    else
    {
        std::cerr<<"P Distribution in not valid"<<std::endl;
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

    //AnalizeHyperGraph();
    ChangeApplicationState(APPLICATION_STATE_ADDITIONAL_OPTION);

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
            const int min = ui->VMaxDegreeS->value()>ui->VMinDegreeS->value()?ui->VMinDegreeS->value():ui->VMaxDegreeS->value();
            const int max = ui->VMaxDegreeS->value()<=ui->VMinDegreeS->value()?ui->VMinDegreeS->value():ui->VMaxDegreeS->value();
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
        case DISTRIBUTION::POWERLAW:
        {
            DATA.SetKDistribution(new PowerLaw(ui->VAverageDegreeS->value(),ui->VDistributionParamDSP->value()));
        }
        break;
        default:
            std::cout<<"Error non such Distribution"<<std::endl;
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
            const int min = ui->HMaxDegreeS->value()>ui->HMinDegreeS->value()?ui->HMinDegreeS->value():ui->HMaxDegreeS->value();
            const int max = ui->HMaxDegreeS->value()<=ui->HMinDegreeS->value()?ui->HMinDegreeS->value():ui->HMaxDegreeS->value();
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
        case DISTRIBUTION::POWERLAW:
        {
            DATA.SetPDistribution(new PowerLaw(ui->HAverageDegreeS->value(),ui->HDistributionParamDSB->value()));
        }
        break;
        default:
            std::cout<<"Error non such Distribution"<<std::endl;
        break;
    }
}

void MainWindow::ChooseAndRunAlgorithm()
{
    switch(ui->AlgorithmsCB->currentIndex())
    {
        case ALGORITHM::ALGORITHM_RANDOM_HYPERGRAPH:
            std::cout<<"Random Hypergraph Algorithm"<<std::endl;
            RandomHypergraphAlgorithm();

        break;
        case ALGORITHM::ALGORITHM_FULL_HYPERGRAPH:
            std::cout<<"Full Hypergraph Algorithm"<<std::endl;
        break;
        case ALGORITHM::ALGORITHM_TEST:
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
        case ALGORITHM::ALGORITHM_RANDOM_HYPERGRAPH:
            std::cout<<" Random Hypergraph "<<std::endl;
            ui->VDistributionCB->setEnabled(true);
            ui->VAverageDegreeS->setEnabled(true);
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->HDistributionCB->setEnabled(true);
            ui->HDistributionCB->setCurrentIndex(DISTRIBUTION::CONST);
            ui->VDistributionCB->setCurrentIndex(DISTRIBUTION::CONST);
            ChangeApplicationState(APPLICATION_STATE_CHOOSE_VERTEX_DISTRIBUTION);
        break;
        case ALGORITHM::ALGORITHM_FULL_HYPERGRAPH:
            std::cout<<" Full Hypergraph "<<std::endl;
            ui->VDistributionCB->setEnabled(false);
            ui->VAverageDegreeS->setEnabled(false);
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->HDistributionCB->setEnabled(false);
            ui->HDistributionCB->setCurrentIndex(DISTRIBUTION::CONST);
            ui->VDistributionCB->setCurrentIndex(DISTRIBUTION::CONST);
            ChangeApplicationState(APPLICATION_STATE_CHOOSE_ALGORITHM);

        break;
        case ALGORITHM::ALGORITHM_TEST:
            std::cout<<" Test Hypergraph "<<std::endl;
            ChangeApplicationState(APPLICATION_STATE_CHOOSE_ALGORITHM);

        break;
        case ALGORITHM::ALGORITHM_CHOOSE_ALGORITHM:
            std::cout<<" Test Hypergraph "<<std::endl;
            ChangeApplicationState(APPLICATION_STATE_CHOOSE_ALGORITHM);

        break;
        default:
            std::cerr<<" Error out of bound "<<std::endl;
            ChangeApplicationState(APPLICATION_STATE_CHOOSE_ALGORITHM);

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
            ui->VDistributionParamDSP->setRange(0,1);
            ui->VDistributionParamL->setText("Parameter :");

            ui->VAvarageDegreeL->setText("Lambda :");
        break;
        case DISTRIBUTION::POWERLAW:
            std::cout<<"Power law"<<std::endl;
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->VAverageDegreeS->setEnabled(true);
            ui->VDistributionParamDSP->setEnabled(true);
            ui->VDistributionParamDSP->setRange(2,9999999);
            ui->VDistributionParamL->setText("Power :");
            ui->VAvarageDegreeL->setText("Min :");
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
            ui->HDistributionParamDSB->setRange(0,1);
            ui->HDistributionParamL->setText("Parameter :");
            ui->HAverageDegreeL->setText("Lambda :");
        break;
        case DISTRIBUTION::POWERLAW:
            std::cout<<"Power law"<<std::endl;
            ui->HMaxDegreeS->setEnabled(false);
            ui->HMinDegreeS->setEnabled(false);
            ui->HAverageDegreeS->setEnabled(true);
            ui->HDistributionParamDSB->setEnabled(true);
            ui->HDistributionParamDSB->setRange(2,9999999);
            ui->HDistributionParamL->setText("Power :");
            ui->HAverageDegreeL->setText("Min :");
        break;
        default:
            std::cerr<<"Error out of bound"<<std::endl;
        break;
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    std::cout<<"Save as action ..."<<std::endl;
    const QString fileName = QFileDialog::getSaveFileName(this,"Save Hypergraph",QDir::homePath());
    std::cout<<"Saving to "<< fileName.toStdString() << std::endl;
    HyperGraphManager::HyperGraphToFile(DATA.GetHyperGraph(),fileName.toStdString());

    std::cout<<"Save as action Done."<<std::endl;

}

void MainWindow::on_actionLoad_triggered()
{
    std::cout<<"Load action ..."<<std::endl;
    const QString fileName = QFileDialog::getOpenFileName(this,"Load Hypergraph",QDir::homePath());
    std::cout<<"Loading from "<< fileName.toStdString() << std::endl;

    DATA.SetHyperGraph(HyperGraphManager::HyperGraphFromFile(fileName.toStdString()));
    std::cout<<"Load action Done."<<std::endl;
}

void MainWindow::on_actionLoad_kTable_triggered()
{
    std::cout<<"Load kTable action"<<std::endl;
    const QString fileName = QFileDialog::getOpenFileName(this,"Load vertex degree distribution",QDir::homePath());
    std::cout<<"Loading from "<< fileName.toStdString() << std::endl;
    m_LoadedKTable = HyperGraphManager::KTableFromFile(fileName.toStdString());
    std::cout<<"Load action Done."<<std::endl;

    ui->VUseLoadedChB->setEnabled(true);
    ui->VUseLoadedChB->setCheckable(true);
    ui->VUseLoadedChB->setChecked(true);
}
