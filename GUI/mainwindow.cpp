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

    std::default_random_engine e((std::random_device())());

    std::poisson_distribution<int> poisson(3);
    kDistribution = std::bind(poisson,e);


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
  ui->kPlotWidget->addGraph();
  QPen pen(Qt::red);
  ui->kPlotWidget->graph(1)->setPen(pen);
  ui->kPlotWidget->graph(1)->setLineStyle((QCPGraph::LineStyle)0);
  ui->kPlotWidget->graph(1)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCross, 10));
  ui->kPlotWidget->xAxis->setLabel("k");
  ui->kPlotWidget->yAxis->setLabel("P(k)");
  ui->kPlotWidget->yAxis->setRange(0,1);


  ui->pPlotWidget->addGraph();
  ui->pPlotWidget->graph(0)->setPen(pen);
  ui->pPlotWidget->graph(0)->setLineStyle((QCPGraph::LineStyle)0);
  ui->pPlotWidget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCross, 10));
  // give the axes some labels:
  ui->pPlotWidget->xAxis->setLabel("p");
  ui->pPlotWidget->yAxis->setLabel("P(p)");
  ui->pPlotWidget->yAxis->setRange(0,1);
}

void MainWindow::drawHyperGraph(int sizeOfHyperedges) {
  clearScene();

  QBrush redBrush(QColor(255, 50, 50));
  QBrush blueBrush(QColor(100, 149, 237));
  QPen randomPen(Qt::black);
  randomPen.setWidth(5);

  std::default_random_engine e((std::random_device())());
  std::uniform_int_distribution<int> d(0, 255);

  int numberOfVertexes = hyperGraph->getNumberOfVertices();
  int numberOfHyperEdges = hyperGraph->getAdjacencyList().size();

  for (int i = 0; i < numberOfVertexes; ++i) {
    vertexes.emplace_back(
        new GUIVertex(QRectF(100, 150 * i, 50, 50), randomPen, blueBrush));
  }
  for (int i = 0; i < numberOfHyperEdges; ++i) {
    hyperEdges.emplace_back(
        new GUIHyperEdge(QRectF(300, 150 * i, 50, 50), randomPen, redBrush));
  }
  randomPen.setWidth(3);
  for (int j = 0; j < numberOfHyperEdges; ++j) {
    randomPen.setColor(QColor(d(e), d(e), d(e)));

    for (int i = 0; i < numberOfVertexes; ++i) {
      if (hyperGraph->getConnection(j, i)) {
        std::unique_ptr<QGraphicsLineItem> line{
            scene->addLine(QLineF(40, 40, 80, 80))};
        line->setPen(randomPen);
        vertexes[i]->addLine(line.get());
        hyperEdges[j]->addLine(line.get());
        lines.push_back(std::move(line));
      }
    }
  }

  for (const auto &vertex : vertexes) {
    scene->addItem(vertex.get());
  }
  for (const auto &hyperedge : hyperEdges) {
    scene->addItem(hyperedge.get());
  }

  QBrush yellowBrush(Qt::yellow);

  pTable.reset(HyperGraphManager::calculatePTable(*(hyperGraph.get())));
  for (int i = 0; i < numberOfHyperEdges; ++i) {
    if ((*pTable)[i] != sizeOfHyperedges) {
      hyperEdges[i]->setBrush(yellowBrush);
    }
  }

  // ui->graphicsView->repaint();
}
void MainWindow::drawKHistogram() {
  auto actualK = HyperGraphManager::calculateKTable(*hyperGraph);

  std::unordered_map<int, int> TheoreticalHist;
  std::unordered_map<int, int> RealHist;

  double n = ui->VAmountS->value();
  int maxk = 0;
  for (int i = 0; i < n; ++i) {
    TheoreticalHist[(*kTable)[i]]++;
    RealHist[(*actualK)[i]]++;
    if (maxk < (*kTable)[i])
      maxk = (*kTable)[i];
    if (maxk < (*actualK)[i])
      maxk = (*actualK)[i];
  }
  delete actualK;

  QVector<double> x;
  QVector<double> yTheoretic;
  QVector<double> yReal;

  x.reserve(maxk);
  yTheoretic.reserve(maxk);
  yReal.reserve(maxk);

  double max = 0;
  for (int i = 0; i <= maxk; ++i) {
    x.push_back(i);
    yTheoretic.push_back(TheoreticalHist[i]/n);
    yReal.push_back(RealHist[i]/n);
    if (max < yTheoretic[i])
      max = yTheoretic[i];
    if (max < yReal[i])
      max = yReal[i];
  }

  ui->kPlotWidget->graph(0)->setData(x, yTheoretic);
  ui->kPlotWidget->graph(1)->setData(x, yReal);

  ui->kPlotWidget->xAxis->setRange(0, 1.1 * maxk);
  ui->kPlotWidget->yAxis->setRange(0,1.1 * max);
  ui->kPlotWidget->replot();
}
void MainWindow::drawPHistogram() {
  auto actualP =HyperGraphManager::calculatePTable(*hyperGraph);


  std::unordered_map<int, int> TheoreticalHist;
  std::unordered_map<int, int> RealHist;

  double n = hyperGraph->size();
  int maxp = 0;
  for (int i = 0; i < n; ++i) {
    RealHist[(*actualP)[i]]++;
    if (maxp < (*actualP)[i])
      maxp = (*actualP)[i];
  }
  delete actualP;


  QVector<double> x;
  QVector<double> yTheoretic;
  QVector<double> yReal;
  x.reserve(maxp);
  yTheoretic.reserve(maxp);
  yReal.reserve(maxp);

  double max = 0;
  for (int i = 0; i <= maxp; ++i) {

    x.push_back(i);
    yReal.push_back(RealHist[i]/n);

    if (max < yReal[i])
      max = yReal[i];
  }

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
   // std::cout << " | "
      //       << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
      //       << "ns" ;
    std::cout<<std::endl;
}
void MainWindow::randomHypergraphAlgorithm()
{
    int numberOfVertices{ui->VAmountS->value()};
    int sizeOfHyperedges{ui->HAverageDegreeS->value()};

    kTable.reset(
        HyperGraphManager::generateKTable(kDistribution, numberOfVertices));

    std::sort(kTable->begin(),kTable->end(),std::greater<int>());

    hyperGraph.reset(HyperGraphFabric::createRandomAdjacencyList(
        numberOfVertices, sizeOfHyperedges, *kTable));
}

void MainWindow::on_StartBtn_clicked()
{
    std::cout<<"Starting ";
    auto beginAll=std::chrono::steady_clock::now();
    auto begin = beginAll;
    switch(ui->AlgorithmsCB->currentIndex())
    {
        case 0:
            std::cout<<"Random Hypergraph Algorithm"<<std::endl;
            randomHypergraphAlgorithm();
        break;
        case 1:
            std::cout<<"Full Hypergraph Algorithm"<<std::endl;
        break;
        case 2:
            std::cout<<"Test Algorithm"<<std::endl;
        break;
        default:
            std::cout<<"Error non such algorithm"<<std::endl;
        break;
    }
    auto end= std::chrono::steady_clock::now();
    showTime("Algorithm took ",begin,end);

    if(ui->DrawHypergraphChB->isChecked())
    {
        std::cout<<"Starting Drawing Hypergraph"<<std::endl;
        begin = std::chrono::steady_clock::now();

        drawHyperGraph(ui->HAverageDegreeS->value());

        end = std::chrono::steady_clock::now();
        showTime("Drawing HyperGraph took",begin,end);
    }
    else
    {
        std::cout<<"Dont Draw Hypergraph option"<<std::endl;
        clearScene();
    }

    if(ui->kHistogramChB->isChecked())
    {
        std::cout<<"Starting Making K Histogram "<<std::endl;
        begin = std::chrono::steady_clock::now();
        drawKHistogram();
        end = std::chrono::steady_clock::now();
        showTime("Drawing K Histogram took",begin,end);
    }
    else
    {
        ui->kPlotWidget->graph(0)->setData({}, {});
        ui->kPlotWidget->graph(1)->setData({}, {});
        ui->kPlotWidget->replot();
    }


    if(ui->pHistogramChB->isChecked())
    {
        std::cout<<"Starting Making P Histogram "<<std::endl;
        begin = std::chrono::steady_clock::now();
        drawPHistogram();
        end = std::chrono::steady_clock::now();
        showTime("Drawing P Histogram took",begin,end);
    }
    else
    {
        ui->pPlotWidget->graph(0)->setData({}, {});
        ui->pPlotWidget->replot();
    }
    std::cout<<"End of Simulation"<<std::endl;
    end = std::chrono::steady_clock::now();

    showTime("Simulation took : ",beginAll,end);
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
        break;
        case DISTRIBUTION::UNIFORM:
            std::cout<<"Uniform"<<std::endl;
            ui->VMaxDegreeS->setEnabled(true);
            ui->VMinDegreeS->setEnabled(true);
            ui->VAverageDegreeS->setEnabled(false);
        break;
        case DISTRIBUTION::POISSON:
            std::cout<<"Poisson"<<std::endl;
            ui->VMaxDegreeS->setEnabled(false);
            ui->VMinDegreeS->setEnabled(false);
            ui->VAverageDegreeS->setEnabled(true);
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
            ui->HAverageDegreeS->setEnabled(true);
        break;
        case DISTRIBUTION::UNIFORM:
            std::cout<<"Uniform"<<std::endl;
            ui->HMaxDegreeS->setEnabled(true);
            ui->HMinDegreeS->setEnabled(true);
            ui->HAverageDegreeS->setEnabled(false);
        break;
        case DISTRIBUTION::POISSON:
            std::cout<<"Poisson"<<std::endl;
            ui->HMaxDegreeS->setEnabled(false);
            ui->HMinDegreeS->setEnabled(false);
            ui->HAverageDegreeS->setEnabled(true);
        break;
        default:
            std::cerr<<"Error out of bound"<<std::endl;
        break;
    }
}
