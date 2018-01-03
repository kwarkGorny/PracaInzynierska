#ifndef HYPERGRAPHDRAWDIALOG_H
#define HYPERGRAPHDRAWDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QtCore>
#include <QGraphicsScene>


#include "Patterns/Data.h"
#include "Distributions/uniform.h"

#include"guivertex.h"
#include"guihyperedge.h"

#include<memory>

/**
 * @author   Adam Szczepanski
 * @date 27.12.2017
 * @brief Graphic component use to draw HyperGraph
*/


namespace Ui
{
    class HyperGraphDrawDialog;
}

class HyperGraphDrawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HyperGraphDrawDialog(QWidget *parent = 0);
    ~HyperGraphDrawDialog();

    void DrawHyperGraph();

    void SaveGuiTofile(const std::string &nameOfFile) const ;

    void ClearScene();

private slots:
    void on_HypergraphDrawButton_clicked();

private:
    Ui::HyperGraphDrawDialog *ui;

    std::unique_ptr<QGraphicsScene> m_Scene;

    std::vector<std::unique_ptr<GUIVertex>> m_Vertexes;
    std::vector<std::unique_ptr<GUIHyperEdge>> m_HyperEdges;
    std::vector<std::unique_ptr<QGraphicsLineItem>> m_Lines;

    const QBrush m_VerticesBrush{QColor(255, 50, 50)};
    const QBrush m_HyperedgeBrush{QColor(100, 149, 237)};

};

#endif // HYPERGRAPHDRAWDIALOG_H
