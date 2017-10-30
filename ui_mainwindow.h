/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QFrame *VertexFrame;
    QGridLayout *gridLayout_2;
    QLabel *AmountL;
    QLabel *VtoL;
    QLabel *VDistributionParamL;
    QSpinBox *VAverageDegreeS;
    QDoubleSpinBox *VDistributionParamDSP;
    QSpinBox *VMinDegreeS;
    QLabel *VAvarageDegreeL;
    QSpinBox *VAmountS;
    QComboBox *VDistributionCB;
    QSpinBox *VMaxDegreeS;
    QLabel *VDistributionL;
    QLabel *VerticiesL;
    QLabel *VDegreeRangeL;
    QFrame *ResultFrame;
    QGridLayout *gridLayout;
    QLabel *AlgorithmL;
    QComboBox *AlgorithmsCB;
    QFrame *HyperEdgeFrame;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *HDistributionParamDSB;
    QSpinBox *HMaxDegreeS;
    QLabel *HAverageDegreeL;
    QLabel *HDistibutionL;
    QSpinBox *HMinDegreeS;
    QLabel *HtoL;
    QLabel *HyperEdgeL;
    QSpinBox *HAverageDegreeS;
    QComboBox *HDistributionCB;
    QLabel *HDegreeRandgeL;
    QLabel *HDistributionParamL;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QPushButton *PlotKHistogramBtn;
    QPushButton *PlotPHistogramBtn;
    QPushButton *pushButton_5;
    QLabel *WattodoL;
    QPushButton *StartBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(280, 687);
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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
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
        VertexFrame = new QFrame(ParametersFrame);
        VertexFrame->setObjectName(QStringLiteral("VertexFrame"));
        sizePolicy1.setHeightForWidth(VertexFrame->sizePolicy().hasHeightForWidth());
        VertexFrame->setSizePolicy(sizePolicy1);
        VertexFrame->setFrameShape(QFrame::StyledPanel);
        VertexFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(VertexFrame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        AmountL = new QLabel(VertexFrame);
        AmountL->setObjectName(QStringLiteral("AmountL"));

        gridLayout_2->addWidget(AmountL, 1, 0, 1, 1);

        VtoL = new QLabel(VertexFrame);
        VtoL->setObjectName(QStringLiteral("VtoL"));

        gridLayout_2->addWidget(VtoL, 10, 1, 1, 1);

        VDistributionParamL = new QLabel(VertexFrame);
        VDistributionParamL->setObjectName(QStringLiteral("VDistributionParamL"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(VDistributionParamL->sizePolicy().hasHeightForWidth());
        VDistributionParamL->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(VDistributionParamL, 6, 0, 1, 1);

        VAverageDegreeS = new QSpinBox(VertexFrame);
        VAverageDegreeS->setObjectName(QStringLiteral("VAverageDegreeS"));
        VAverageDegreeS->setEnabled(true);
        sizePolicy.setHeightForWidth(VAverageDegreeS->sizePolicy().hasHeightForWidth());
        VAverageDegreeS->setSizePolicy(sizePolicy);
        VAverageDegreeS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        VAverageDegreeS->setMaximum(999999);
        VAverageDegreeS->setValue(5);

        gridLayout_2->addWidget(VAverageDegreeS, 7, 2, 1, 1);

        VDistributionParamDSP = new QDoubleSpinBox(VertexFrame);
        VDistributionParamDSP->setObjectName(QStringLiteral("VDistributionParamDSP"));
        VDistributionParamDSP->setEnabled(false);
        sizePolicy1.setHeightForWidth(VDistributionParamDSP->sizePolicy().hasHeightForWidth());
        VDistributionParamDSP->setSizePolicy(sizePolicy1);
        VDistributionParamDSP->setDecimals(5);
        VDistributionParamDSP->setMaximum(1);
        VDistributionParamDSP->setSingleStep(0.001);
        VDistributionParamDSP->setValue(0.2);

        gridLayout_2->addWidget(VDistributionParamDSP, 6, 2, 1, 1);

        VMinDegreeS = new QSpinBox(VertexFrame);
        VMinDegreeS->setObjectName(QStringLiteral("VMinDegreeS"));
        VMinDegreeS->setEnabled(false);
        sizePolicy.setHeightForWidth(VMinDegreeS->sizePolicy().hasHeightForWidth());
        VMinDegreeS->setSizePolicy(sizePolicy);
        VMinDegreeS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        VMinDegreeS->setMaximum(999999);

        gridLayout_2->addWidget(VMinDegreeS, 10, 0, 1, 1);

        VAvarageDegreeL = new QLabel(VertexFrame);
        VAvarageDegreeL->setObjectName(QStringLiteral("VAvarageDegreeL"));

        gridLayout_2->addWidget(VAvarageDegreeL, 7, 0, 1, 1);

        VAmountS = new QSpinBox(VertexFrame);
        VAmountS->setObjectName(QStringLiteral("VAmountS"));
        sizePolicy.setHeightForWidth(VAmountS->sizePolicy().hasHeightForWidth());
        VAmountS->setSizePolicy(sizePolicy);
        VAmountS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        VAmountS->setMaximum(99999999);
        VAmountS->setValue(1000);

        gridLayout_2->addWidget(VAmountS, 1, 2, 1, 1);

        VDistributionCB = new QComboBox(VertexFrame);
        VDistributionCB->setObjectName(QStringLiteral("VDistributionCB"));
        sizePolicy2.setHeightForWidth(VDistributionCB->sizePolicy().hasHeightForWidth());
        VDistributionCB->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(VDistributionCB, 3, 2, 1, 1);

        VMaxDegreeS = new QSpinBox(VertexFrame);
        VMaxDegreeS->setObjectName(QStringLiteral("VMaxDegreeS"));
        VMaxDegreeS->setEnabled(false);
        sizePolicy.setHeightForWidth(VMaxDegreeS->sizePolicy().hasHeightForWidth());
        VMaxDegreeS->setSizePolicy(sizePolicy);
        VMaxDegreeS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        VMaxDegreeS->setMaximum(999999);

        gridLayout_2->addWidget(VMaxDegreeS, 10, 2, 1, 1);

        VDistributionL = new QLabel(VertexFrame);
        VDistributionL->setObjectName(QStringLiteral("VDistributionL"));

        gridLayout_2->addWidget(VDistributionL, 3, 0, 1, 1);

        VerticiesL = new QLabel(VertexFrame);
        VerticiesL->setObjectName(QStringLiteral("VerticiesL"));
        sizePolicy2.setHeightForWidth(VerticiesL->sizePolicy().hasHeightForWidth());
        VerticiesL->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(VerticiesL, 0, 0, 1, 2);

        VDegreeRangeL = new QLabel(VertexFrame);
        VDegreeRangeL->setObjectName(QStringLiteral("VDegreeRangeL"));
        sizePolicy2.setHeightForWidth(VDegreeRangeL->sizePolicy().hasHeightForWidth());
        VDegreeRangeL->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(VDegreeRangeL, 9, 0, 1, 2);


        gridLayout_4->addWidget(VertexFrame, 1, 0, 1, 1);

        ResultFrame = new QFrame(ParametersFrame);
        ResultFrame->setObjectName(QStringLiteral("ResultFrame"));
        sizePolicy.setHeightForWidth(ResultFrame->sizePolicy().hasHeightForWidth());
        ResultFrame->setSizePolicy(sizePolicy);
        ResultFrame->setFrameShape(QFrame::StyledPanel);
        ResultFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(ResultFrame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(1);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(-1, -1, 9, -1);
        AlgorithmL = new QLabel(ResultFrame);
        AlgorithmL->setObjectName(QStringLiteral("AlgorithmL"));
        sizePolicy1.setHeightForWidth(AlgorithmL->sizePolicy().hasHeightForWidth());
        AlgorithmL->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(AlgorithmL, 0, 0, 1, 1);

        AlgorithmsCB = new QComboBox(ResultFrame);
        AlgorithmsCB->setObjectName(QStringLiteral("AlgorithmsCB"));
        sizePolicy1.setHeightForWidth(AlgorithmsCB->sizePolicy().hasHeightForWidth());
        AlgorithmsCB->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(AlgorithmsCB, 2, 0, 1, 2);


        gridLayout_4->addWidget(ResultFrame, 0, 0, 1, 1);

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
        HDistributionParamDSB = new QDoubleSpinBox(HyperEdgeFrame);
        HDistributionParamDSB->setObjectName(QStringLiteral("HDistributionParamDSB"));
        HDistributionParamDSB->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(HDistributionParamDSB->sizePolicy().hasHeightForWidth());
        HDistributionParamDSB->setSizePolicy(sizePolicy3);
        HDistributionParamDSB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        HDistributionParamDSB->setDecimals(5);
        HDistributionParamDSB->setMaximum(1);
        HDistributionParamDSB->setSingleStep(0.001);
        HDistributionParamDSB->setValue(0.2);

        gridLayout_3->addWidget(HDistributionParamDSB, 3, 2, 1, 1);

        HMaxDegreeS = new QSpinBox(HyperEdgeFrame);
        HMaxDegreeS->setObjectName(QStringLiteral("HMaxDegreeS"));
        HMaxDegreeS->setEnabled(false);
        sizePolicy.setHeightForWidth(HMaxDegreeS->sizePolicy().hasHeightForWidth());
        HMaxDegreeS->setSizePolicy(sizePolicy);
        HMaxDegreeS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        HMaxDegreeS->setMaximum(999999);

        gridLayout_3->addWidget(HMaxDegreeS, 8, 2, 1, 1);

        HAverageDegreeL = new QLabel(HyperEdgeFrame);
        HAverageDegreeL->setObjectName(QStringLiteral("HAverageDegreeL"));
        sizePolicy2.setHeightForWidth(HAverageDegreeL->sizePolicy().hasHeightForWidth());
        HAverageDegreeL->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(HAverageDegreeL, 6, 0, 1, 1);

        HDistibutionL = new QLabel(HyperEdgeFrame);
        HDistibutionL->setObjectName(QStringLiteral("HDistibutionL"));
        sizePolicy2.setHeightForWidth(HDistibutionL->sizePolicy().hasHeightForWidth());
        HDistibutionL->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(HDistibutionL, 2, 0, 1, 1);

        HMinDegreeS = new QSpinBox(HyperEdgeFrame);
        HMinDegreeS->setObjectName(QStringLiteral("HMinDegreeS"));
        HMinDegreeS->setEnabled(false);
        sizePolicy2.setHeightForWidth(HMinDegreeS->sizePolicy().hasHeightForWidth());
        HMinDegreeS->setSizePolicy(sizePolicy2);
        HMinDegreeS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        HMinDegreeS->setMaximum(99999999);

        gridLayout_3->addWidget(HMinDegreeS, 8, 0, 1, 1);

        HtoL = new QLabel(HyperEdgeFrame);
        HtoL->setObjectName(QStringLiteral("HtoL"));

        gridLayout_3->addWidget(HtoL, 8, 1, 1, 1);

        HyperEdgeL = new QLabel(HyperEdgeFrame);
        HyperEdgeL->setObjectName(QStringLiteral("HyperEdgeL"));
        sizePolicy2.setHeightForWidth(HyperEdgeL->sizePolicy().hasHeightForWidth());
        HyperEdgeL->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(HyperEdgeL, 1, 0, 1, 2);

        HAverageDegreeS = new QSpinBox(HyperEdgeFrame);
        HAverageDegreeS->setObjectName(QStringLiteral("HAverageDegreeS"));
        sizePolicy.setHeightForWidth(HAverageDegreeS->sizePolicy().hasHeightForWidth());
        HAverageDegreeS->setSizePolicy(sizePolicy);
        HAverageDegreeS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        HAverageDegreeS->setMaximum(99999);
        HAverageDegreeS->setValue(3);

        gridLayout_3->addWidget(HAverageDegreeS, 6, 2, 1, 1);

        HDistributionCB = new QComboBox(HyperEdgeFrame);
        HDistributionCB->setObjectName(QStringLiteral("HDistributionCB"));
        sizePolicy.setHeightForWidth(HDistributionCB->sizePolicy().hasHeightForWidth());
        HDistributionCB->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(HDistributionCB, 2, 1, 1, 2);

        HDegreeRandgeL = new QLabel(HyperEdgeFrame);
        HDegreeRandgeL->setObjectName(QStringLiteral("HDegreeRandgeL"));
        sizePolicy2.setHeightForWidth(HDegreeRandgeL->sizePolicy().hasHeightForWidth());
        HDegreeRandgeL->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(HDegreeRandgeL, 7, 0, 1, 3);

        HDistributionParamL = new QLabel(HyperEdgeFrame);
        HDistributionParamL->setObjectName(QStringLiteral("HDistributionParamL"));
        sizePolicy2.setHeightForWidth(HDistributionParamL->sizePolicy().hasHeightForWidth());
        HDistributionParamL->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(HDistributionParamL, 3, 0, 1, 2);


        gridLayout_4->addWidget(HyperEdgeFrame, 2, 0, 1, 1);

        frame = new QFrame(ParametersFrame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setEnabled(true);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        PlotKHistogramBtn = new QPushButton(frame);
        PlotKHistogramBtn->setObjectName(QStringLiteral("PlotKHistogramBtn"));
        sizePolicy1.setHeightForWidth(PlotKHistogramBtn->sizePolicy().hasHeightForWidth());
        PlotKHistogramBtn->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(PlotKHistogramBtn, 4, 0, 1, 1);

        PlotPHistogramBtn = new QPushButton(frame);
        PlotPHistogramBtn->setObjectName(QStringLiteral("PlotPHistogramBtn"));
        sizePolicy1.setHeightForWidth(PlotPHistogramBtn->sizePolicy().hasHeightForWidth());
        PlotPHistogramBtn->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(PlotPHistogramBtn, 5, 0, 1, 1);

        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy3.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy3);

        gridLayout_8->addWidget(pushButton_5, 6, 0, 1, 1);

        WattodoL = new QLabel(frame);
        WattodoL->setObjectName(QStringLiteral("WattodoL"));

        gridLayout_8->addWidget(WattodoL, 1, 0, 1, 1);

        StartBtn = new QPushButton(frame);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        sizePolicy3.setHeightForWidth(StartBtn->sizePolicy().hasHeightForWidth());
        StartBtn->setSizePolicy(sizePolicy3);

        gridLayout_8->addWidget(StartBtn, 2, 0, 1, 1);


        gridLayout_4->addWidget(frame, 3, 0, 1, 1);


        gridLayout_6->addWidget(ParametersFrame, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        AmountL->setText(QApplication::translate("MainWindow", "Amount :", 0));
        VtoL->setText(QApplication::translate("MainWindow", " to", 0));
        VDistributionParamL->setText(QApplication::translate("MainWindow", "Parameter", 0));
        VAvarageDegreeL->setText(QApplication::translate("MainWindow", "Degree :", 0));
        VDistributionCB->clear();
        VDistributionCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Constant", 0)
         << QApplication::translate("MainWindow", "Uniform", 0)
         << QApplication::translate("MainWindow", "Poisson", 0)
         << QApplication::translate("MainWindow", "Binomial", 0)
         << QApplication::translate("MainWindow", "Geometric", 0)
        );
        VDistributionL->setText(QApplication::translate("MainWindow", "Distribution :", 0));
        VerticiesL->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Vertex Options</span></p></body></html>", 0));
        VDegreeRangeL->setText(QApplication::translate("MainWindow", "Degree Range :", 0));
        AlgorithmL->setText(QApplication::translate("MainWindow", "Algorithm :", 0));
        AlgorithmsCB->clear();
        AlgorithmsCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random Hypergraph", 0)
         << QApplication::translate("MainWindow", "Full HyperGraph", 0)
         << QApplication::translate("MainWindow", "Test", 0)
        );
        HAverageDegreeL->setText(QApplication::translate("MainWindow", "Degree :", 0));
        HDistibutionL->setText(QApplication::translate("MainWindow", "Distribution :", 0));
        HtoL->setText(QApplication::translate("MainWindow", "to", 0));
        HyperEdgeL->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Hyperedge Options</span></p></body></html>", 0));
        HDistributionCB->clear();
        HDistributionCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Constant", 0)
         << QApplication::translate("MainWindow", "Uniform", 0)
         << QApplication::translate("MainWindow", "Poisson", 0)
         << QApplication::translate("MainWindow", "Binomial", 0)
         << QApplication::translate("MainWindow", "Geometric", 0)
        );
        HDegreeRandgeL->setText(QApplication::translate("MainWindow", "Degree Range :", 0));
        HDistributionParamL->setText(QApplication::translate("MainWindow", "Parameter", 0));
        PlotKHistogramBtn->setText(QApplication::translate("MainWindow", "Plot k-Histgram", 0));
        PlotPHistogramBtn->setText(QApplication::translate("MainWindow", "Plot p-Histogram", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "HyperGraph Drawer", 0));
        WattodoL->setText(QApplication::translate("MainWindow", "What to do?", 0));
        StartBtn->setText(QApplication::translate("MainWindow", "Create HyperGraph", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
