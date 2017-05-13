#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // this->setStyleSheet("background-color: white;");
    scene= new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen redPen(Qt::red);
    QPen blackPen(Qt::black);

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::drawHyperGraph(IncidencyMatrix* hyperGraph)
{
    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
   // QPen redPen(Qt::red);
    QPen blackPen(Qt::black);
    blackPen.setWidth(3);
    for(int i=0;i<hyperGraph->getNumberOfVertexes();i++)
    {
        vertexes.push_back(scene->addEllipse(100,100*i,50,50,blackPen,blueBrush));
    }
    for(int i=0;i<hyperGraph->getIncidencyMatrix().size();i++)
    {
        hyperEdges.push_back(scene->addRect(300,100*i,50,50,blackPen,redBrush));
    }

    for(int j=0;j<hyperGraph->getIncidencyMatrix().size();j++)
    {
        for(int i=0;i<hyperGraph->getNumberOfVertexes();i++)
        {
            if(hyperGraph->getConnection(j,i))
            {
                double cx=vertexes[i]->rect().x()+vertexes[i]->rect().width()/2;
                double cy=vertexes[i]->rect().y()+vertexes[i]->rect().height()/2;
                double rx=hyperEdges[j]->rect().x()+hyperEdges[j]->rect().width()/2;
                double ry=hyperEdges[j]->rect().y()+hyperEdges[j]->rect().height()/2;

                blackPen.setColor(QColor(100+i*j*2,40*j,20+20*j));
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
