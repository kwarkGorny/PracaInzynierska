#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include <QGraphicsScene>
#include<string>
#include<vector>
#include<memory>

#include"Matrix/incidencymatrix.h"

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

    void saveGuiTofile(const std::string& nameOfFile);

protected:
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void drawHyperGraph();
    void clearScene();


    Ui::MainWindow *ui;
    QGraphicsScene* scene;

    std::unique_ptr<IncidencyMatrix> hyperGraph;

    std::vector<QGraphicsEllipseItem*> vertexes;
    std::vector<QGraphicsRectItem*> hyperEdges;
    std::vector<QGraphicsLineItem*> lines;
};

#endif // MAINWINDOW_H
