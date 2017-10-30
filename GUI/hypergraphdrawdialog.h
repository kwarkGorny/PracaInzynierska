#ifndef HYPERGRAPHDRAWDIALOG_H
#define HYPERGRAPHDRAWDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QtCore>
#include <QGraphicsScene>



#include"AdjacencyList/AdjacencyList.h"
#include "Distributions/uniform.h"

#include"guivertex.h"
#include"guihyperedge.h"
#include "ui_hypergraphdrawwindow.h"

#include<memory>



namespace Ui {
class HyperGraphDrawDialog;
}

class HyperGraphDrawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HyperGraphDrawDialog(QWidget *parent = 0, AdjacencyList *hyperGraph = nullptr);
    ~HyperGraphDrawDialog();

    void drawHyperGraph();

    void saveGuiTofile(const std::string &nameOfFile) const ;

    void clearScene();

private slots:
    void on_HypergraphDrawButton_clicked();

private:
    Ui::HyperGraphDrawDialog *ui;

    std::unique_ptr<QGraphicsScene> scene;


    std::vector<std::unique_ptr<GUIVertex>> vertexes;
    std::vector<std::unique_ptr<GUIHyperEdge>> hyperEdges;
    std::vector<std::unique_ptr<QGraphicsLineItem>> lines;


    AdjacencyList* hyperGraph;


    const QBrush verticesBrush{QColor(255, 50, 50)};
    const QBrush hyperedgeBrush{QColor(100, 149, 237)};

};

#endif // HYPERGRAPHDRAWDIALOG_H
