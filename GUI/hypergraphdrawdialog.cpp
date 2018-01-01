#include "hypergraphdrawdialog.h"
#include "ui_hypergraphdrawdialog.h"

HyperGraphDrawDialog::HyperGraphDrawDialog(QWidget *parent) : QDialog(parent), ui(new Ui::HyperGraphDrawDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Hypergraph Drawer");
    scene = std::make_unique<QGraphicsScene>(this);

    ui->HypergraphView->setScene(scene.get());
}

HyperGraphDrawDialog::~HyperGraphDrawDialog()
{
    clearScene();
    delete ui;
}

void HyperGraphDrawDialog::on_HypergraphDrawButton_clicked()
{
    drawHyperGraph();
}

void HyperGraphDrawDialog::saveGuiTofile(const std::string &nameOfFile) const
{
  QImage img(scene->width(), scene->height(),QImage::Format_ARGB32_Premultiplied);
  QPainter p(&img);
  scene->render(&p);
  p.end();
  img.save(QString::fromStdString(nameOfFile));
}

void HyperGraphDrawDialog::clearScene()
{
  vertexes.clear();
  hyperEdges.clear();
  lines.clear();
  scene.reset(new QGraphicsScene(this));
  ui->HypergraphView->setScene(scene.get());
}

void HyperGraphDrawDialog::drawHyperGraph()
{
  clearScene();

  QPen randomPen(Qt::black);
  randomPen.setWidth(5);

  int numberOfVertexes = DATA.GetHyperGraph().GetNumberOfVertices();
  int numberOfHyperEdges = DATA.GetHyperGraph().size();

  vertexes.reserve(numberOfVertexes);
  hyperEdges.reserve(numberOfHyperEdges);

  for (int i = 0; i < numberOfVertexes; ++i)
  {
    vertexes.emplace_back(
        std::make_unique<GUIVertex>(QRectF(100, 150 * i, 50, 50), randomPen, hyperedgeBrush));
  }
  for (int i = 0; i < numberOfHyperEdges; ++i)
  {
    hyperEdges.emplace_back(
        std::make_unique<GUIHyperEdge>(QRectF(300, 150 * i, 50, 50), randomPen, verticesBrush));
  }
  randomPen.setWidth(3);

  for (int i = 0; i < numberOfHyperEdges; ++i)
  {

    randomPen.setColor(QColor(Uniform::get(0,255), Uniform::get(0,255), Uniform::get(0,255)));
    for(auto&& vertex : DATA.GetHyperGraph().GetHyperEdge(i))
    {
        lines.emplace_back(scene->addLine(QLineF(40, 40, 80, 80),randomPen));
        vertexes[vertex]->addLine(lines.back().get());
        hyperEdges[i]->addLine(lines.back().get());
    }
  }

  for (const auto &vertex : vertexes)
  {
    scene->addItem(vertex.get());
  }
  for (const auto &hyperedge : hyperEdges)
  {
    scene->addItem(hyperedge.get());
  }

}
