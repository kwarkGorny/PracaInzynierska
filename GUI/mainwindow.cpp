#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Patterns/hypergraphfabric.h"
#include"Patterns/hypergraphmanager.h"
#include <random>
#include<iostream>
#include<chrono>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Rysownik HiperGrafu");
    scene= std::make_unique<QGraphicsScene>(this);
    ui->graphicsView->setScene(scene.get());
    hyperGraph=std::make_unique<IncidencyMatrix>();

    std::default_random_engine e((std::random_device())());

    std::poisson_distribution<int> poisson(3.1);
      // std::uniform_int_distribution<int> kDistribution(1,6);
    kDistribution=std::bind(poisson,e);

}

MainWindow::~MainWindow()
{
    clearScene();
}

void MainWindow::drawHyperGraph()
{

    QBrush redBrush(QColor(255,50,50));
    QBrush blueBrush(QColor(100,149,237));
    QPen randomPen(Qt::black);
    randomPen.setWidth(5);

    std::default_random_engine e((std::random_device())());
    std::uniform_int_distribution<int> d(0,255);

    int numberOfVertexes=hyperGraph->getNumberOfVertexes();
    int numberOfHyperEdges=hyperGraph->getIncidencyMatrix().size();

    for(int i=0;i<numberOfVertexes;i++)
    {
        vertexes.emplace_back(new GUIVertex(QRectF(100,150*i,50,50),randomPen,blueBrush));
    }
    for(int i=0;i<numberOfHyperEdges;i++)
    {
        hyperEdges.emplace_back(new GUIHyperEdge(QRectF(300,150*i,50,50),randomPen,redBrush));
    }
    randomPen.setWidth(3);
    for(int j=0;j<numberOfHyperEdges;j++)
    {
        randomPen.setColor(QColor (d(e),d(e),d(e)));

        for(int i=0;i<numberOfVertexes;i++)
        {
            if(hyperGraph->getConnection(j,i))
            {
               std::unique_ptr<QGraphicsLineItem> line( scene->addLine(QLineF(40, 40, 80, 80)));
                line->setPen(randomPen);
                vertexes[i]->addLine(line.get());
                hyperEdges[j]->addLine(line.get());
                lines.push_back(std::move(line));
            }
        }
    }

    for(const auto & vertex:vertexes)
    {
        scene->addItem(vertex.get());

    }
    for(const auto& hyperedge:hyperEdges)
    {
        scene->addItem(hyperedge.get());
    }
}

void MainWindow::on_pushButton_clicked()
{
    clearScene();

    ui->graphicsView->setScene(scene.get());

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    hyperGraph.reset(HyperGraphFabric::createRandomIncidencyMatrix(1000,5,kDistribution));

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()<<"ms" <<std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()<<"us" <<std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()<<"ns" <<std::endl;

    drawHyperGraph();
    QBrush yellowBrush(Qt::yellow);

    auto pTable=HyperGraphManager::calculatePTable(*(hyperGraph.get()));
    for(int i=0;i<hyperEdges.size();i++)
    {
        if((*pTable)[i]!=5)
        {
            hyperEdges[i]->setBrush(yellowBrush);
        }
    }
    delete pTable;

}

void MainWindow::on_pushButton_2_clicked()
{
    saveGuiTofile("HyperGraph.png");
    hyperGraph->print();
}

void MainWindow::saveGuiTofile(const std::string& nameOfFile)const
{
    QImage img(scene->width(),scene->height(),QImage::Format_ARGB32_Premultiplied);
    QPainter p(&img);
    scene->render(&p);
    p.end();
    img.save(QString::fromStdString(nameOfFile));
}
void MainWindow::clearScene()
{
    vertexes.clear();
    hyperEdges.clear();
    lines.clear();
    scene.reset(new QGraphicsScene (this));

}
