#include "hypergraphdrawdialog.h"
#include "ui_hypergraphdrawdialog.h"

HyperGraphDrawDialog::HyperGraphDrawDialog(QWidget *parent) : QDialog(parent), ui(new Ui::HyperGraphDrawDialog),m_Vertexes{},m_HyperEdges{},m_Lines{}
{
    ui->setupUi(this);
    this->setWindowTitle("Hypergraph Drawer");
    m_Scene = std::make_unique<QGraphicsScene>(this);

    ui->HypergraphView->setScene(m_Scene.get());
}

HyperGraphDrawDialog::~HyperGraphDrawDialog()
{
    ClearScene();
    delete ui;
}

void HyperGraphDrawDialog::on_HypergraphDrawButton_clicked()
{
    DrawHyperGraph();
}

void HyperGraphDrawDialog::SaveGuiTofile(const std::string &nameOfFile) const
{
  QImage img(m_Scene->width(), m_Scene->height(),QImage::Format_ARGB32_Premultiplied);
  QPainter p(&img);
  m_Scene->render(&p);
  p.end();
  img.save(QString::fromStdString(nameOfFile));
}

void HyperGraphDrawDialog::ClearScene()
{
    m_Vertexes.clear();
    m_HyperEdges.clear();
    m_Lines.clear();
    m_Scene.reset(new QGraphicsScene(this));
    ui->HypergraphView->setScene(m_Scene.get());
}

void HyperGraphDrawDialog::DrawHyperGraph()
{
  ClearScene();

  QPen randomPen(Qt::black);
  randomPen.setWidth(5);

  int numberOfVertexes = DATA.GetHyperGraph().GetNumberOfVertices();
  int numberOfHyperEdges = DATA.GetHyperGraph().size();

  m_Vertexes.reserve(numberOfVertexes);
  m_HyperEdges.reserve(numberOfHyperEdges);

  for (int i = 0; i < numberOfVertexes; ++i)
  {
    m_Vertexes.emplace_back(
        std::make_unique<GUIVertex>(QRectF(100, 150 * i, 50, 50), randomPen, m_HyperedgeBrush));
  }
  for (int i = 0; i < numberOfHyperEdges; ++i)
  {
    m_HyperEdges.emplace_back(
        std::make_unique<GUIHyperEdge>(QRectF(300, 150 * i, 50, 50), randomPen, m_VerticesBrush));
  }
  randomPen.setWidth(3);

  for (int i = 0; i < numberOfHyperEdges; ++i)
  {
    randomPen.setColor(QColor(Uniform::Get(0,255), Uniform::Get(0,255), Uniform::Get(0,255)));
    for(auto&& vertex : DATA.GetHyperGraph().GetHyperEdge(i))
    {
        m_Lines.emplace_back(m_Scene->addLine(QLineF(40, 40, 80, 80),randomPen));
        m_Vertexes[vertex]->AddLine(m_Lines.back().get());
        m_HyperEdges[i]->AddLine(m_Lines.back().get());
    }
  }
  for (const auto &vertex : m_Vertexes)
  {
    m_Scene->addItem(vertex.get());
  }
  for (const auto &hyperedge : m_HyperEdges)
  {
    m_Scene->addItem(hyperedge.get());
  }

}
