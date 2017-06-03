#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include <QGraphicsScene>
#include<string>
#include<vector>
#include<memory>
#include<functional>
#include"Matrix/incidencymatrix.h"
#include"guivertex.h"
#include"guihyperedge.h"
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void drawHyperGraph(int sizeOfHyperedges);
    void clearScene();
    void saveGuiTofile(const std::string& nameOfFile)const;


    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<QGraphicsScene> scene;
    std::unique_ptr<IncidencyMatrix> hyperGraph;

    std::vector<std::unique_ptr<GUIVertex>> vertexes;
    std::vector<std::unique_ptr<GUIHyperEdge>> hyperEdges;
    std::vector<std::unique_ptr<QGraphicsLineItem>> lines;

    std::function<int()> kDistribution;

};

#endif // MAINWINDOW_H
