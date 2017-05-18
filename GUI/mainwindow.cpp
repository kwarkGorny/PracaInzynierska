#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Patterns/hypergraphfabric.h"
#include <random>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //this->setStyleSheet("background-color: white;");
    this->setWindowTitle("Rysownik HiperGrafu");
    scene= std::make_unique<QGraphicsScene>(this);
    ui->graphicsView->setScene(scene.get());
    //scene->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    hyperGraph=std::make_unique<IncidencyMatrix>();
}

MainWindow::~MainWindow()
{
    clearScene();
    delete ui;
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
        vertexes.push_back(new GUIVertex(QRectF(100,150*i,50,50),randomPen,blueBrush));
        scene->addItem(vertexes[i]);
       //vertexes[i]->setFlags(QGraphicsItem::ItemIsMovable);
    }
    for(int i=0;i<numberOfHyperEdges;i++)
    {
        hyperEdges.push_back(new GUIHyperEdge(QRectF(300,150*i,50,50),randomPen,redBrush));
        scene->addItem(hyperEdges[i]);
    }
    randomPen.setWidth(3);
    for(int j=0;j<numberOfHyperEdges;j++)
    {
        randomPen.setColor(QColor (d(e),d(e),d(e)));

        for(int i=0;i<numberOfVertexes;i++)
        {
            if(hyperGraph->getConnection(j,i))
            {
                QGraphicsLineItem *line = scene->addLine(QLineF(40, 40, 80, 80));
                line->setPen(randomPen);
                lines.push_back(line);
                vertexes[i]->addLine(line);
                hyperEdges[j]->addLine(line);
            }
        }
    }

}

void MainWindow::on_pushButton_clicked()
{
    clearScene();

    scene.reset(new QGraphicsScene (this));
    ui->graphicsView->setScene(scene.get());

    hyperGraph.reset(HyperGraphFabric::createTestIncidencyMatrix(6,6));

    drawHyperGraph();
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

    for (auto&vertex : vertexes)
    {
         delete vertex;
    }
    vertexes.clear();
    for (auto&hyperedge : hyperEdges)
    {
         delete hyperedge;
    }
    hyperEdges.clear();
    for (auto& line : lines)
    {
         delete line;
    }
    lines.clear();
}
