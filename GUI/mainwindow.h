#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include <QGraphicsScene>
#include<string>
#include<vector>

#include"Matrix/incidencymatrix.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void drawHyperGraph( IncidencyMatrix* hyperGraph);
    void saveGuiTofile(const std::string& nameOfFile);

protected:
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

    std::vector<QGraphicsEllipseItem*> vertexes;
    std::vector<QGraphicsRectItem*> hyperEdges;
    std::vector<QGraphicsLineItem*> lines;
};

#endif // MAINWINDOW_H
