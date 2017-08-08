/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QCustomPlot/qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QFrame *ParametersFrame;
    QGridLayout *gridLayout_4;
    QFrame *HyperEdgeFrame;
    QGridLayout *gridLayout_3;
    QLabel *HDegreeRandgeL;
    QLabel *HtoL;
    QSpinBox *HMinDegreeS;
    QLabel *HDistibutionL;
    QComboBox *HDistributionCB;
    QLabel *HAverageDegreeL;
    QSpinBox *HMaxDegreeS;
    QLabel *HyperEdgeL;
    QSpinBox *HAverageDegreeS;
    QFrame *ResultFrame;
    QGridLayout *gridLayout;
    QCheckBox *DrawHypergraphChB;
    QComboBox *AlgorithmsCB;
    QCheckBox *pHistogramChB;
    QLabel *WattodoL;
    QCheckBox *kHistogramChB;
    QLabel *AlgorithmL;
    QFrame *VertexFrame;
    QGridLayout *gridLayout_2;
    QLabel *VtoL;
    QLabel *AmountL;
    QSpinBox *VMinDegreeS;
    QLabel *VDistributionL;
    QLabel *VerticiesL;
    QSpinBox *VAverageDegreeS;
    QSpinBox *VAmountS;
    QSpinBox *VMaxDegreeS;
    QLabel *AvarageDegreeL;
    QComboBox *VDistributionCB;
    QLabel *VDegreeRangeL;
    QPushButton *StartBtn;
    QFrame *DrawFrame;
    QGridLayout *gridLayout_5;
    QGraphicsView *HypergraphDrawView;
    QFrame *HistogramsFrame;
    QGridLayout *gridLayout_9;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QCustomPlot *kPlotWidget;
    QCustomPlot *pPlotWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 622);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        ParametersFrame = new QFrame(centralWidget);
        ParametersFrame->setObjectName(QStringLiteral("ParametersFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ParametersFrame->sizePolicy().hasHeightForWidth());
        ParametersFrame->setSizePolicy(sizePolicy1);
        ParametersFrame->setFrameShape(QFrame::StyledPanel);
        ParametersFrame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(ParametersFrame);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        HyperEdgeFrame = new QFrame(ParametersFrame);
        HyperEdgeFrame->setObjectName(QStringLiteral("HyperEdgeFrame"));
        sizePolicy.setHeightForWidth(HyperEdgeFrame->sizePolicy().hasHeightForWidth());
        HyperEdgeFrame->setSizePolicy(sizePolicy);
        HyperEdgeFrame->setFrameShape(QFrame::StyledPanel);
        HyperEdgeFrame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(HyperEdgeFrame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        HDegreeRandgeL = new QLabel(HyperEdgeFrame);
        HDegreeRandgeL->setObjectName(QStringLiteral("HDegreeRandgeL"));
        sizePolicy1.setHeightForWidth(HDegreeRandgeL->sizePolicy().hasHeightForWidth());
        HDegreeRandgeL->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(HDegreeRandgeL, 7, 0, 1, 2);

        HtoL = new QLabel(HyperEdgeFrame);
        HtoL->setObjectName(QStringLiteral("HtoL"));

        gridLayout_3->addWidget(HtoL, 8, 1, 1, 1);

        HMinDegreeS = new QSpinBox(HyperEdgeFrame);
        HMinDegreeS->setObjectName(QStringLiteral("HMinDegreeS"));
        HMinDegreeS->setEnabled(false);
        sizePolicy.setHeightForWidth(HMinDegreeS->sizePolicy().hasHeightForWidth());
        HMinDegreeS->setSizePolicy(sizePolicy);
        HMinDegreeS->setMaximum(999999999);

        gridLayout_3->addWidget(HMinDegreeS, 8, 0, 1, 1);

        HDistibutionL = new QLabel(HyperEdgeFrame);
        HDistibutionL->setObjectName(QStringLiteral("HDistibutionL"));
        sizePolicy1.setHeightForWidth(HDistibutionL->sizePolicy().hasHeightForWidth());
        HDistibutionL->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(HDistibutionL, 2, 0, 1, 1);

        HDistributionCB = new QComboBox(HyperEdgeFrame);
        HDistributionCB->setObjectName(QStringLiteral("HDistributionCB"));
        sizePolicy.setHeightForWidth(HDistributionCB->sizePolicy().hasHeightForWidth());
        HDistributionCB->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(HDistributionCB, 2, 1, 1, 2);

        HAverageDegreeL = new QLabel(HyperEdgeFrame);
        HAverageDegreeL->setObjectName(QStringLiteral("HAverageDegreeL"));
        sizePolicy1.setHeightForWidth(HAverageDegreeL->sizePolicy().hasHeightForWidth());
        HAverageDegreeL->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(HAverageDegreeL, 6, 0, 1, 1);

        HMaxDegreeS = new QSpinBox(HyperEdgeFrame);
        HMaxDegreeS->setObjectName(QStringLiteral("HMaxDegreeS"));
        HMaxDegreeS->setEnabled(false);
        sizePolicy.setHeightForWidth(HMaxDegreeS->sizePolicy().hasHeightForWidth());
        HMaxDegreeS->setSizePolicy(sizePolicy);
        HMaxDegreeS->setMaximum(999999999);

        gridLayout_3->addWidget(HMaxDegreeS, 8, 2, 1, 1);

        HyperEdgeL = new QLabel(HyperEdgeFrame);
        HyperEdgeL->setObjectName(QStringLiteral("HyperEdgeL"));

        gridLayout_3->addWidget(HyperEdgeL, 1, 0, 1, 1);

        HAverageDegreeS = new QSpinBox(HyperEdgeFrame);
        HAverageDegreeS->setObjectName(QStringLiteral("HAverageDegreeS"));
        sizePolicy.setHeightForWidth(HAverageDegreeS->sizePolicy().hasHeightForWidth());
        HAverageDegreeS->setSizePolicy(sizePolicy);
        HAverageDegreeS->setMaximum(999999999);
        HAverageDegreeS->setValue(3);

        gridLayout_3->addWidget(HAverageDegreeS, 6, 2, 1, 1);


        gridLayout_4->addWidget(HyperEdgeFrame, 3, 0, 1, 1);

        ResultFrame = new QFrame(ParametersFrame);
        ResultFrame->setObjectName(QStringLiteral("ResultFrame"));
        ResultFrame->setFrameShape(QFrame::StyledPanel);
        ResultFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(ResultFrame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        DrawHypergraphChB = new QCheckBox(ResultFrame);
        DrawHypergraphChB->setObjectName(QStringLiteral("DrawHypergraphChB"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DrawHypergraphChB->sizePolicy().hasHeightForWidth());
        DrawHypergraphChB->setSizePolicy(sizePolicy2);
        DrawHypergraphChB->setChecked(true);

        gridLayout->addWidget(DrawHypergraphChB, 4, 0, 1, 1);

        AlgorithmsCB = new QComboBox(ResultFrame);
        AlgorithmsCB->setObjectName(QStringLiteral("AlgorithmsCB"));
        sizePolicy.setHeightForWidth(AlgorithmsCB->sizePolicy().hasHeightForWidth());
        AlgorithmsCB->setSizePolicy(sizePolicy);

        gridLayout->addWidget(AlgorithmsCB, 2, 0, 1, 1);

        pHistogramChB = new QCheckBox(ResultFrame);
        pHistogramChB->setObjectName(QStringLiteral("pHistogramChB"));
        sizePolicy2.setHeightForWidth(pHistogramChB->sizePolicy().hasHeightForWidth());
        pHistogramChB->setSizePolicy(sizePolicy2);
        pHistogramChB->setChecked(true);

        gridLayout->addWidget(pHistogramChB, 6, 0, 1, 1);

        WattodoL = new QLabel(ResultFrame);
        WattodoL->setObjectName(QStringLiteral("WattodoL"));

        gridLayout->addWidget(WattodoL, 3, 0, 1, 1);

        kHistogramChB = new QCheckBox(ResultFrame);
        kHistogramChB->setObjectName(QStringLiteral("kHistogramChB"));
        sizePolicy2.setHeightForWidth(kHistogramChB->sizePolicy().hasHeightForWidth());
        kHistogramChB->setSizePolicy(sizePolicy2);
        kHistogramChB->setChecked(true);

        gridLayout->addWidget(kHistogramChB, 5, 0, 1, 1);

        AlgorithmL = new QLabel(ResultFrame);
        AlgorithmL->setObjectName(QStringLiteral("AlgorithmL"));

        gridLayout->addWidget(AlgorithmL, 0, 0, 1, 1);


        gridLayout_4->addWidget(ResultFrame, 0, 0, 1, 1);

        VertexFrame = new QFrame(ParametersFrame);
        VertexFrame->setObjectName(QStringLiteral("VertexFrame"));
        sizePolicy.setHeightForWidth(VertexFrame->sizePolicy().hasHeightForWidth());
        VertexFrame->setSizePolicy(sizePolicy);
        VertexFrame->setFrameShape(QFrame::StyledPanel);
        VertexFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(VertexFrame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        VtoL = new QLabel(VertexFrame);
        VtoL->setObjectName(QStringLiteral("VtoL"));

        gridLayout_2->addWidget(VtoL, 9, 1, 1, 1);

        AmountL = new QLabel(VertexFrame);
        AmountL->setObjectName(QStringLiteral("AmountL"));

        gridLayout_2->addWidget(AmountL, 1, 0, 1, 1);

        VMinDegreeS = new QSpinBox(VertexFrame);
        VMinDegreeS->setObjectName(QStringLiteral("VMinDegreeS"));
        VMinDegreeS->setEnabled(false);
        sizePolicy.setHeightForWidth(VMinDegreeS->sizePolicy().hasHeightForWidth());
        VMinDegreeS->setSizePolicy(sizePolicy);
        VMinDegreeS->setMaximum(999999999);

        gridLayout_2->addWidget(VMinDegreeS, 9, 0, 1, 1);

        VDistributionL = new QLabel(VertexFrame);
        VDistributionL->setObjectName(QStringLiteral("VDistributionL"));

        gridLayout_2->addWidget(VDistributionL, 3, 0, 1, 1);

        VerticiesL = new QLabel(VertexFrame);
        VerticiesL->setObjectName(QStringLiteral("VerticiesL"));

        gridLayout_2->addWidget(VerticiesL, 0, 0, 1, 2);

        VAverageDegreeS = new QSpinBox(VertexFrame);
        VAverageDegreeS->setObjectName(QStringLiteral("VAverageDegreeS"));
        VAverageDegreeS->setEnabled(true);
        sizePolicy.setHeightForWidth(VAverageDegreeS->sizePolicy().hasHeightForWidth());
        VAverageDegreeS->setSizePolicy(sizePolicy);
        VAverageDegreeS->setMaximum(999999999);
        VAverageDegreeS->setValue(5);

        gridLayout_2->addWidget(VAverageDegreeS, 6, 2, 1, 1);

        VAmountS = new QSpinBox(VertexFrame);
        VAmountS->setObjectName(QStringLiteral("VAmountS"));
        sizePolicy.setHeightForWidth(VAmountS->sizePolicy().hasHeightForWidth());
        VAmountS->setSizePolicy(sizePolicy);
        VAmountS->setMaximum(999999999);
        VAmountS->setValue(1000);

        gridLayout_2->addWidget(VAmountS, 1, 2, 1, 1);

        VMaxDegreeS = new QSpinBox(VertexFrame);
        VMaxDegreeS->setObjectName(QStringLiteral("VMaxDegreeS"));
        VMaxDegreeS->setEnabled(false);
        sizePolicy.setHeightForWidth(VMaxDegreeS->sizePolicy().hasHeightForWidth());
        VMaxDegreeS->setSizePolicy(sizePolicy);
        VMaxDegreeS->setMaximum(999999999);

        gridLayout_2->addWidget(VMaxDegreeS, 9, 2, 1, 1);

        AvarageDegreeL = new QLabel(VertexFrame);
        AvarageDegreeL->setObjectName(QStringLiteral("AvarageDegreeL"));

        gridLayout_2->addWidget(AvarageDegreeL, 6, 0, 1, 1);

        VDistributionCB = new QComboBox(VertexFrame);
        VDistributionCB->setObjectName(QStringLiteral("VDistributionCB"));
        sizePolicy.setHeightForWidth(VDistributionCB->sizePolicy().hasHeightForWidth());
        VDistributionCB->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(VDistributionCB, 3, 2, 1, 1);

        VDegreeRangeL = new QLabel(VertexFrame);
        VDegreeRangeL->setObjectName(QStringLiteral("VDegreeRangeL"));
        sizePolicy1.setHeightForWidth(VDegreeRangeL->sizePolicy().hasHeightForWidth());
        VDegreeRangeL->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(VDegreeRangeL, 8, 0, 1, 1);


        gridLayout_4->addWidget(VertexFrame, 1, 0, 1, 1);

        StartBtn = new QPushButton(ParametersFrame);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        sizePolicy2.setHeightForWidth(StartBtn->sizePolicy().hasHeightForWidth());
        StartBtn->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(StartBtn, 4, 0, 1, 1);


        gridLayout_6->addWidget(ParametersFrame, 0, 0, 1, 1);

        DrawFrame = new QFrame(centralWidget);
        DrawFrame->setObjectName(QStringLiteral("DrawFrame"));
        sizePolicy.setHeightForWidth(DrawFrame->sizePolicy().hasHeightForWidth());
        DrawFrame->setSizePolicy(sizePolicy);
        DrawFrame->setFrameShape(QFrame::StyledPanel);
        DrawFrame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(DrawFrame);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        HypergraphDrawView = new QGraphicsView(DrawFrame);
        HypergraphDrawView->setObjectName(QStringLiteral("HypergraphDrawView"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(HypergraphDrawView->sizePolicy().hasHeightForWidth());
        HypergraphDrawView->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(HypergraphDrawView, 0, 0, 1, 1);

        HistogramsFrame = new QFrame(DrawFrame);
        HistogramsFrame->setObjectName(QStringLiteral("HistogramsFrame"));
        sizePolicy.setHeightForWidth(HistogramsFrame->sizePolicy().hasHeightForWidth());
        HistogramsFrame->setSizePolicy(sizePolicy);
        HistogramsFrame->setFrameShape(QFrame::StyledPanel);
        HistogramsFrame->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(HistogramsFrame);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_2 = new QLabel(HistogramsFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);

        gridLayout_9->addWidget(label_2, 4, 0, 1, 1);

        lineEdit = new QLineEdit(HistogramsFrame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        gridLayout_9->addWidget(lineEdit, 1, 1, 1, 1);

        label = new QLabel(HistogramsFrame);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        gridLayout_9->addWidget(label, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(HistogramsFrame);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);

        gridLayout_9->addWidget(lineEdit_2, 4, 1, 1, 1);

        pushButton_2 = new QPushButton(HistogramsFrame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_9->addWidget(pushButton_2, 4, 2, 1, 1);

        pushButton = new QPushButton(HistogramsFrame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);

        gridLayout_9->addWidget(pushButton, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(HistogramsFrame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_9->addWidget(pushButton_3, 4, 3, 1, 1);

        pushButton_4 = new QPushButton(HistogramsFrame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_9->addWidget(pushButton_4, 1, 3, 1, 1);

        kPlotWidget = new QCustomPlot(HistogramsFrame);
        kPlotWidget->setObjectName(QStringLiteral("kPlotWidget"));

        gridLayout_9->addWidget(kPlotWidget, 0, 0, 1, 4);

        pPlotWidget = new QCustomPlot(HistogramsFrame);
        pPlotWidget->setObjectName(QStringLiteral("pPlotWidget"));
        sizePolicy.setHeightForWidth(pPlotWidget->sizePolicy().hasHeightForWidth());
        pPlotWidget->setSizePolicy(sizePolicy);

        gridLayout_9->addWidget(pPlotWidget, 3, 0, 1, 4);


        gridLayout_5->addWidget(HistogramsFrame, 0, 1, 1, 1);


        gridLayout_6->addWidget(DrawFrame, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        HDegreeRandgeL->setText(QApplication::translate("MainWindow", "Degree Range :", 0));
        HtoL->setText(QApplication::translate("MainWindow", "to", 0));
        HDistibutionL->setText(QApplication::translate("MainWindow", "Distribution :", 0));
        HDistributionCB->clear();
        HDistributionCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Constant", 0)
         << QApplication::translate("MainWindow", "Uniform", 0)
         << QApplication::translate("MainWindow", "Poisson", 0)
        );
        HAverageDegreeL->setText(QApplication::translate("MainWindow", "Average Degree :", 0));
        HyperEdgeL->setText(QApplication::translate("MainWindow", "HyperEdge Options", 0));
        DrawHypergraphChB->setText(QApplication::translate("MainWindow", "Draw Hypergraph", 0));
        AlgorithmsCB->clear();
        AlgorithmsCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random Hypergraph", 0)
         << QApplication::translate("MainWindow", "Full HyperGraph", 0)
         << QApplication::translate("MainWindow", "Test", 0)
        );
        pHistogramChB->setText(QApplication::translate("MainWindow", "Make p Histogram ", 0));
        WattodoL->setText(QApplication::translate("MainWindow", "What to do?", 0));
        kHistogramChB->setText(QApplication::translate("MainWindow", "Make k Histogram", 0));
        AlgorithmL->setText(QApplication::translate("MainWindow", "Choose Algorithm :", 0));
        VtoL->setText(QApplication::translate("MainWindow", " to", 0));
        AmountL->setText(QApplication::translate("MainWindow", "Amount :", 0));
        VDistributionL->setText(QApplication::translate("MainWindow", "Distribution :", 0));
        VerticiesL->setText(QApplication::translate("MainWindow", "Vertex Options", 0));
        AvarageDegreeL->setText(QApplication::translate("MainWindow", "Average Degree :", 0));
        VDistributionCB->clear();
        VDistributionCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Constant", 0)
         << QApplication::translate("MainWindow", "Uniform", 0)
         << QApplication::translate("MainWindow", "Poisson", 0)
        );
        VDegreeRangeL->setText(QApplication::translate("MainWindow", "Degree Range :", 0));
        StartBtn->setText(QApplication::translate("MainWindow", "Start!", 0));
        label_2->setText(QApplication::translate("MainWindow", "Name of file :", 0));
        label->setText(QApplication::translate("MainWindow", "Name of file :", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Save to png", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Save to png", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Save to txt", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Save to txt", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
