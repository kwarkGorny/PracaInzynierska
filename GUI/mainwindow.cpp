#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Rysownik HiperGrafu");
    scene = std::make_unique<QGraphicsScene>(this);

    ui->HypergraphDrawView->setScene(scene.get());
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    prepareHistograms();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::prepareHistograms() {
  ui->kPlotWidget->addGraph();
  ui->kPlotWidget->graph(0)->setLineStyle((QCPGraph::LineStyle)0);
  ui->kPlotWidget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

  ui->kPlotWidget->xAxis->setLabel("k");
  ui->kPlotWidget->yAxis->setLabel("P(k)");
  ui->kPlotWidget->yAxis->setRange(0,1);



  ui->pPlotWidget->addGraph();
  ui->pPlotWidget->graph(0)->setPen(QPen(Qt::red));
  ui->pPlotWidget->graph(0)->setLineStyle((QCPGraph::LineStyle)0);
  ui->pPlotWidget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCross, 10));

  ui->pPlotWidget->xAxis->setLabel("p");
  ui->pPlotWidget->yAxis->setLabel("P(p)");
  ui->pPlotWidget->yAxis->setRange(0,1);
}

void MainWindow::drawHyperGraph() {
  clearScene();

  static std::default_random_engine e((std::random_device())());
  std::uniform_int_distribution<int> d(0, 255);

  static const QBrush redBrush(QColor(255, 50, 50));
  static const QBrush blueBrush(QColor(100, 149, 237));

  QPen randomPen(Qt::black);
  randomPen.setWidth(5);

  int numberOfVertexes = hyperGraph->getNumberOfVertices();
  int numberOfHyperEdges = hyperGraph->size();

  vertexes.reserve(numberOfVertexes);
  hyperEdges.reserve(numberOfHyperEdges);

  for (int i = 0; i < numberOfVertexes; ++i) {
    vertexes.emplace_back(
        std::make_unique<GUIVertex>(QRectF(100, 150 * i, 50, 50), randomPen, blueBrush));
  }
  for (int i = 0; i < numberOfHyperEdges; ++i) {
    hyperEdges.emplace_back(
        std::make_unique<GUIHyperEdge>(QRectF(300, 150 * i, 50, 50), randomPen, redBrush));
  }
  randomPen.setWidth(3);

  for (int i = 0; i < numberOfHyperEdges; ++i)
  {
    randomPen.setColor(QColor(d(e), d(e), d(e)));
    for(const auto vertex:hyperGraph->getHyperEdge(i))
    {
        lines.emplace_back(scene->addLine(QLineF(40, 40, 80, 80),randomPen));

        vertexes[vertex]->addLine(lines.back().get());
        hyperEdges[i]->addLine(lines.back().get());

    }
  }

  for (const auto &vertex : vertexes) {
    scene->addItem(vertex.get());
  }
  for (const auto &hyperedge : hyperEdges) {
    scene->addItem(hyperedge.get());
  }

}
void MainWindow::drawKHistogram() {

  auto RealHist = HyperGraphManager::calculateKHistogram(*hyperGraph);

  QVector<double> x;
  QVector<double> yReal;

  x.reserve(RealHist->size());
  yReal.reserve(RealHist->size());

  double n= ui->VAmountS->value();

  for (const auto& value:*RealHist) {
    x.push_back(value.first);
    yReal.push_back(value.second/n);
  }
  delete RealHist;

  auto maxk= *std::max_element(x.begin(),x.end());
  auto max= *std::max_element(yReal.begin(),yReal.end());

  ui->kPlotWidget->graph(0)->setData(x, yReal);

  ui->kPlotWidget->xAxis->setRange(0, 1.1 * maxk);
  ui->kPlotWidget->yAxis->setRange(0,1.1 * max);

  ui->kPlotWidget->replot();
}
void MainWindow::drawPHistogram() {
  auto RealHist = HyperGraphManager::calculatePHistogram(*hyperGraph);

  QVector<double> x;
  QVector<double> yReal;
  x.reserve(RealHist->size());
  yReal.reserve(RealHist->size());

  double n= hyperGraph->size();

  for (const auto& value:*RealHist) {
    x.push_back(value.first);
    yReal.push_back(value.second/n);
  }
  delete RealHist;

  auto maxp= *std::max_element(x.begin(),x.end());
  auto max= *std::max_element(yReal.begin(),yReal.end());

  ui->pPlotWidget->graph(0)->setData(x, yReal);

  ui->pPlotWidget->xAxis->setRange(0, 1.1 * maxp);
  ui->pPlotWidget->yAxis->setRange(0, 1.1 * max);

  ui->pPlotWidget->replot();
}

void MainWindow::saveGuiTofile(const std::string &nameOfFile) const {
  QImage img(scene->width(), scene->height(),
             QImage::Format_ARGB32_Premultiplied);
  QPainter p(&img);
  scene->render(&p);
  p.end();
  img.save(QString::fromStdString(nameOfFile));
}
void MainWindow::clearScene() {
  vertexes.clear();
  hyperEdges.clear();
  lines.clear();
  scene.reset(new QGraphicsScene(this));
  ui->HypergraphDrawView->setScene(scene.get());
}
void MainWindow::showTime(const std::string& nameOfFun,std::chrono::time_point<std::chrono::steady_clock> begin,std::chrono::time_point<std::chrono::steady_clock> end)
{
    std::cout << nameOfFun<<" = "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()
              << "ms";
    std::cout << " |  "
              << std::chrono::duration_cast<std::chrono::microseconds>(end -begin).count()
              << "us";
    std::cout<<std::endl;
}
void MainWindow::randomHypergraphAlgorithm()
{
    int numberOfVertices{ui->VAmountS->value()};
    std::default_random_engine e((std::random_device())());
    std::function<int()> kDistribution=[](){return 1;};
    std::function<int()> pDistribution=[](){return 1;};
    switch(ui->VDistributionCB->currentIndex())
    {
        case DISTRIBUTION::CONST:
            kDistribution=[&](){return ui->VAverageDegreeS->value();};
        break;
        case DISTRIBUTION::UNIFORM:
        {
            int min = ui->VMaxDegreeS->value()>ui->VMinDegreeS->value()?ui->VMinDegreeS->value():ui->VMaxDegreeS->value();
            int max = ui->VMaxDegreeS->value()<=ui->VMinDegreeS->value()?ui->VMinDegreeS->value():ui->VMaxDegreeS->value();
            std::uniform_int_distribution<int> uniform(min,max);
            kDistribution=[&](){return uniform(e);};
        }
        break;
        case DISTRIBUTION::POISSON:
        {
            std::poisson_distribution<int> poisson(ui->VAverageDegreeS->value());
            kDistribution=[&](){return poisson(e);};
        }
        break;
        case DISTRIBUTION::BINOMIAL:
        {
            std::binomial_distribution<int> binomal(ui->VAverageDegreeS->value(),ui->VDistributionParamDSP->value());
            pDistribution=[&](){return binomal(e);};;
        }
        break;
        case DISTRIBUTION::GEOMETRIC:
        {
            std::geometric_distribution<int> geometric(ui->VDistributionParamDSP->value());
            kDistribution=[&](){return geometric(e);};

        }
        break;

    }
    switch(ui->HDistributionCB->currentIndex())
    {
        case DISTRIBUTION::CONST:
            pDistribution=[&](){return ui->HAverageDegreeS->value();};
        break;
        case DISTRIBUTION::UNIFORM:
        {
            int min = ui->HMaxDegreeS->value()>ui->HMinDegreeS->value()?ui->HMinDegreeS->value():ui->HMaxDegreeS->value();
            int max = ui->HMaxDegreeS->value()<=ui->HMinDegreeS->value()?ui->HMinDegreeS->value():ui->HMaxDegreeS->value();
            std::uniform_int_distribution<int> uniform(min,max);
            pDistribution=[&](){return uniform(e);};
        }
        break;
        case DISTRIBUTION::POISSON:
        {
            std::poisson_distribution<int> poisson(ui->HAverageDegreeS->value());
            pDistribution=[&](){return poisson(e);};
        }
        break;
        case DISTRIBUTION::BINOMIAL:
        {
            std::binomial_distribution<int> binomal(ui->HAverageDegreeS->value(),ui->HDistributionParamDSB->value());
            pDistribution=[&](){return binomal(e);};
        }
        break;
        case DISTRIBUTION::GEOMETRIC:
        {
            std::geometric_distribution<int> geometric(ui->HDistributionParamDSB->value());
            pDistribution=[&](){return geometric(e);};
        }
        break;

    }
    hyperGraph.reset(AdjacencyListFabric::createRandomAdjacencyList(numberOfVertices, pDistribution, kDistribution));
}

void MainWindow::on_StartBtn_clicked()
{
    if(algorithmStarted) return;
    algorithmStarted=true;
    std::cout<<"\nStarting ";
    auto beginAll=std::chrono::steady_clock::now();
    auto begin = beginAll;
    switch(ui->AlgorithmsCB->currentIndex())
    {
        case ALGORITHM::RANDOM_HYPERGRAPH:
            std::cout<<"Random Hypergraph Algorithm"<<std::endl;
            randomHypergraphAlgorithm();
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
    showTime("Algorithm took ",begin);

    if(ui->kHistogramChB->isChecked())
    {
        std::cout<<"Starting Making K Histogram "<<std::endl;
        begin = std::chrono::steady_clock::now();

        drawKHistogram();

        showTime("Drawing K Histogram took",begin);
    }
    else
    {
        ui->kPlotWidget->graph(0)->setData({}, {});
        ui->kPlotWidget->replot();
    }


    if(ui->pHistogramChB->isChecked())
    {
        std::cout<<"Starting Making P Histogram "<<std::endl;
        begin = std::chrono::steady_clock::now();

        drawPHistogram();

        showTime("Drawing P Histogram took",begin);
    }
    else
    {
        ui->pPlotWidget->graph(0)->setData({}, {});
        ui->pPlotWidget->replot();
    }

    if(ui->DrawHypergraphChB->isChecked()&&hyperGraph->getNumberOfVertices()<6000&&hyperGraph->size()<10000)
    {
        std::cout<<"Starting Drawing Hypergraph"<<std::endl;
        begin = std::chrono::steady_clock::now();

        drawHyperGraph();

        showTime("Drawing HyperGraph took",begin);
    }
    else
    {
        std::cout<<"Dont Draw Hypergraph option"<<std::endl;
        clearScene();
    }

    showTime("Everything took : ",beginAll);
    std::cout<<"Number of Vertices : "<<hyperGraph->getNumberOfVertices()<<" Number of Hyperedges : "<<hyperGraph->size()<<std::endl;
    std::cout<<"End of Simulation\n"<<std::endl;
    HyperGraphManager::adjacenyListToFile(*hyperGraph,"hyperGraph");
    std::cout<<"Hypergraph Duplicates:"<<std::endl;
    auto histogram = HyperGraphManager::getHyperEdgeHistogram(*hyperGraph);
    bool isthere=false;
    for(auto const& hyperedge:*histogram)
    {
        if(hyperedge.second>1){
        for(auto const&vertex : hyperedge.first)
        {
            std::cout<<vertex<<" ";
        }
        isthere=true;
        std::cout<<" :" << hyperedge.second<<std::endl;
        }
    }
    if(!isthere){
        std::cout<<"no Duplicates"<<std::endl;
    }
    algorithmStarted=false;
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
