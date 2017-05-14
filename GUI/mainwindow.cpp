#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Patterns/hypergraphfabric.h"
#include <random>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //this->setStyleSheet("background-color: white;");
    this->setWindowTitle("Rysownik HiperGrafu");
    scene= new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    hyperGraph=std::make_unique<IncidencyMatrix>();

}

MainWindow::~MainWindow()
{
    clearScene();
    delete ui;
}

void MainWindow::drawHyperGraph()
{

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);

    std::default_random_engine e((std::random_device())());
    std::uniform_int_distribution<int> d(0,255);

    int numberOfVertexes=hyperGraph->getNumberOfVertexes();
    int numberOfHyperEdges=hyperGraph->getIncidencyMatrix().size();

    for(int i=0;i<numberOfVertexes;i++)
    {
        vertexes.push_back(scene->addEllipse(100,150*i,75,75,blackPen,blueBrush));
    }
    for(int i=0;i<numberOfHyperEdges;i++)
    {
        hyperEdges.push_back(scene->addRect(300,150*i,75,75,blackPen,redBrush));
    }
    blackPen.setWidth(3);
    for(int j=0;j<numberOfHyperEdges;j++)
    {
        QColor color(d(e),d(e),d(e));
        blackPen.setColor(color);

        double rx=hyperEdges[j]->rect().x()+hyperEdges[j]->rect().width()/2;
        double ry=hyperEdges[j]->rect().y()+hyperEdges[j]->rect().height()/2;

        for(int i=0;i<numberOfVertexes;i++)
        {
            if(hyperGraph->getConnection(j,i))
            {
                double cx=vertexes[i]->rect().x()+vertexes[i]->rect().width()/2;
                double cy=vertexes[i]->rect().y()+vertexes[i]->rect().height()/2;

                lines.push_back(scene->addLine(cx,cy,rx,ry,blackPen));
            }
        }
    }
}

void MainWindow::saveGuiTofile(const std::string& nameOfFile)
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
    delete scene;
}

void MainWindow::on_pushButton_clicked()
{
    clearScene();

    scene= new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    hyperGraph.reset(HyperGraphFabric::createTestIncidencyMatrix(6,6));

    drawHyperGraph();
}

void MainWindow::on_pushButton_2_clicked()
{
    hyperGraph->print();
}
