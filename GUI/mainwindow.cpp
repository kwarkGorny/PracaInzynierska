#include "mainwindow.h"
#include "Patterns/hypergraphfabric.h"
#include "Patterns/hypergraphmanager.h"
#include "ui_mainwindow.h"
#include <chrono>
#include <iostream>
#include <map>
#include <random>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Rysownik HiperGrafu");
  scene = std::make_unique<QGraphicsScene>(this);
  ui->graphicsView->setScene(scene.get());
  hyperGraph = std::make_unique<IncidencyMatrix>();
  scene->setItemIndexMethod(QGraphicsScene::NoIndex);

  std::default_random_engine e((std::random_device())());

  std::poisson_distribution<int> poisson(6);
  kDistribution = std::bind(poisson, e);

  prepareHistograms();
}

MainWindow::~MainWindow() { clearScene(); }
void MainWindow::prepareHistograms() {
  ui->WykresK->addGraph();
  ui->WykresK->graph(0)->setLineStyle((QCPGraph::LineStyle)0);
  ui->WykresK->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
  ui->WykresK->addGraph();
  QPen pen(Qt::red);
  ui->WykresK->graph(1)->setPen(pen);
  ui->WykresK->graph(1)->setLineStyle((QCPGraph::LineStyle)0);
  ui->WykresK->graph(1)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCross, 10));
  ui->WykresK->xAxis->setLabel("k");
  ui->WykresK->yAxis->setLabel("P(k)");

  ui->WykresP->addGraph();
  ui->WykresP->graph(0)->setPen(pen);
  ui->WykresP->graph(0)->setLineStyle((QCPGraph::LineStyle)0);
  ui->WykresP->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCross, 10));
  // give the axes some labels:
  ui->WykresP->xAxis->setLabel("p");
  ui->WykresP->yAxis->setLabel("P(p)");
}

void MainWindow::drawHyperGraph(int sizeOfHyperedges) {
  clearScene();

  QBrush redBrush(QColor(255, 50, 50));
  QBrush blueBrush(QColor(100, 149, 237));
  QPen randomPen(Qt::black);
  randomPen.setWidth(5);

  std::default_random_engine e((std::random_device())());
  std::uniform_int_distribution<int> d(0, 255);

  int numberOfVertexes = hyperGraph->getNumberOfVertexes();
  int numberOfHyperEdges = hyperGraph->getIncidencyMatrix().size();

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
  QVector<double> x;
  QVector<double> yTheoretic;
  QVector<double> yReal;

  std::map<int, int> TheoreticalHist;
  std::map<int, int> RealHist;

  int n = ui->boxNumberOfVertices->value();
  double max = 0;
  int maxk = 0;
  for (int i = 0; i < n; ++i) {
    TheoreticalHist[(*kTable)[i]]++;
    RealHist[(*actualK)[i]]++;
    if (maxk < (*kTable)[i])
      maxk = (*kTable)[i];
    if (maxk < (*actualK)[i])
      maxk = (*actualK)[i];
  }
  for (int i = 0; i <= maxk; ++i) {
    x.push_back(i);
    yTheoretic.push_back(TheoreticalHist[i]);
    yReal.push_back(RealHist[i]);
    if (max < yTheoretic[i])
      max = yTheoretic[i];
    if (max < yReal[i])
      max = yReal[i];
  }
  for (int i = 0; i <= maxk; ++i) {
    yTheoretic[i] /= n;
    yReal[i] /= n;
  }

  ui->WykresK->graph(0)->setData(x, yTheoretic);

  ui->WykresK->graph(1)->setData(x, yReal);

  // set axes ranges, so we see all data:
  ui->WykresK->xAxis->setRange(0, 1.1 * maxk);
  ui->WykresK->yAxis->setRange(0, 1);
  ui->WykresK->replot();
  delete actualK;
}
void MainWindow::drawPHistogram() {
  std::vector<int> *actualP{HyperGraphManager::calculatePTable(*hyperGraph)};
  QVector<double> x;
  QVector<double> yTheoretic;
  QVector<double> yReal;

  std::map<int, int> TheoreticalHist;
  std::map<int, int> RealHist;
  int n =(int) hyperEdges.size();

  int max = 0;
  int maxp = 0;
  for (int i = 0; i < n; ++i) {
    RealHist[(*actualP)[i]]++;
    if (maxp < (*actualP)[i])
      maxp = (*actualP)[i];
  }
  for (int i = 0; i <= maxp; ++i) {

    x.push_back(i);
    yReal.push_back(RealHist[i]);

    if (max < yReal[i])
      max = yReal[i];
  }
  for (int i = 0; i <= maxp; ++i) {
    yReal[i] /= n;
  }

  ui->WykresP->graph(0)->setData(x, yReal);

  ui->WykresP->xAxis->setRange(0, 1.1 * maxp);
  ui->WykresP->yAxis->setRange(0, 1);

  ui->WykresP->replot();
  delete actualP;
}
void MainWindow::on_pushButton_clicked() {

  int numberOfVertices{ui->boxNumberOfVertices->value()};
  int sizeOfHyperedges{ui->boxSizeOfHyperedge->value()};

  // std::default_random_engine e((std::random_device())());
  // std::poisson_distribution<int> poisson(9);
  // kDistribution=std::bind(poisson,e);

  kTable.reset(
      HyperGraphManager::generateKTable(kDistribution, numberOfVertices));

  auto begin = std::chrono::steady_clock::now();

  hyperGraph.reset(HyperGraphFabric::createRandomIncidencyMatrix(
      numberOfVertices, sizeOfHyperedges, *kTable));

  auto end = std::chrono::steady_clock::now();

  std::cout << "Creation Time of HyperGraph = "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     begin)
                   .count()
            << "ms";
  std::cout << " |  "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     begin)
                   .count()
            << "us";
  std::cout << " | "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin)
                   .count()
            << "ns" << std::endl;

  begin = std::chrono::steady_clock::now();

  drawHyperGraph(sizeOfHyperedges);

  end = std::chrono::steady_clock::now();
  std::cout << "Drawing Time of HyperGraph = "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     begin)
                   .count()
            << "ms";
  std::cout << " |  "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     begin)
                   .count()
            << "us";
  std::cout << " | "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin)
                   .count()
            << "ns" << std::endl;
  std::cout << std::endl;

  drawKHistogram();
  drawPHistogram();
}

void MainWindow::on_pushButton_2_clicked() {
  saveGuiTofile("HyperGraph.png");
  // hyperGraph->print();
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
  ui->graphicsView->setScene(scene.get());
}
