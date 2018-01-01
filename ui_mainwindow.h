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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_as;
    QAction *actionLoad;
    QAction *actionLoad_kTable;
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QFrame *CreateHypergraphFrame;
    QGridLayout *gridLayout_4;
    QPushButton *StartBtn;
    QFrame *ChooseAlgorithmFrame;
    QGridLayout *gridLayout;
    QLabel *AlgorithmL;
    QComboBox *AlgorithmsCB;
    QFrame *AdditionalOptionFrame;
    QFormLayout *formLayout;
    QLabel *WattodoL;
    QPushButton *PlotKHistogramBtn;
    QPushButton *PlotPHistogramBtn;
    QPushButton *pushButton_5;
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
    QLabel *VDegreeRangeL;
    QLabel *VerticiesL;
    QPushButton *VCheckBtn;
    QCheckBox *VUseLoadedChB;
    QFrame *HyperEdgeFrame;
    QGridLayout *gridLayout_3;
    QLabel *HyperEdgeL;
    QDoubleSpinBox *HDistributionParamDSB;
    QSpinBox *HMaxDegreeS;
    QLabel *HAverageDegreeL;
    QLabel *HDistibutionL;
    QSpinBox *HMinDegreeS;
    QLabel *HtoL;
    QSpinBox *HAverageDegreeS;
    QLabel *HDegreeRandgeL;
    QLabel *HDistributionParamL;
    QComboBox *HDistributionCB;
    QPushButton *HCheckBtn;
    QMenuBar *menuBar;
    QMenu *menuFiles;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(331, 781);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionLoad_kTable = new QAction(MainWindow);
        actionLoad_kTable->setObjectName(QStringLiteral("actionLoad_kTable"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        CreateHypergraphFrame = new QFrame(centralWidget);
        CreateHypergraphFrame->setObjectName(QStringLiteral("CreateHypergraphFrame"));
        CreateHypergraphFrame->setFrameShape(QFrame::StyledPanel);
        CreateHypergraphFrame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(CreateHypergraphFrame);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        StartBtn = new QPushButton(CreateHypergraphFrame);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(StartBtn->sizePolicy().hasHeightForWidth());
        StartBtn->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(StartBtn, 0, 0, 1, 1);


        gridLayout_6->addWidget(CreateHypergraphFrame, 5, 0, 1, 1);

        ChooseAlgorithmFrame = new QFrame(centralWidget);
        ChooseAlgorithmFrame->setObjectName(QStringLiteral("ChooseAlgorithmFrame"));
        sizePolicy1.setHeightForWidth(ChooseAlgorithmFrame->sizePolicy().hasHeightForWidth());
        ChooseAlgorithmFrame->setSizePolicy(sizePolicy1);
        ChooseAlgorithmFrame->setFrameShape(QFrame::StyledPanel);
        ChooseAlgorithmFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(ChooseAlgorithmFrame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(1);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(-1, -1, 9, -1);
        AlgorithmL = new QLabel(ChooseAlgorithmFrame);
        AlgorithmL->setObjectName(QStringLiteral("AlgorithmL"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(AlgorithmL->sizePolicy().hasHeightForWidth());
        AlgorithmL->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(AlgorithmL, 0, 0, 1, 1);

        AlgorithmsCB = new QComboBox(ChooseAlgorithmFrame);
        AlgorithmsCB->setObjectName(QStringLiteral("AlgorithmsCB"));
        sizePolicy2.setHeightForWidth(AlgorithmsCB->sizePolicy().hasHeightForWidth());
        AlgorithmsCB->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(AlgorithmsCB, 2, 0, 1, 2);


        gridLayout_6->addWidget(ChooseAlgorithmFrame, 0, 0, 1, 1);

        AdditionalOptionFrame = new QFrame(centralWidget);
        AdditionalOptionFrame->setObjectName(QStringLiteral("AdditionalOptionFrame"));
        AdditionalOptionFrame->setEnabled(true);
        sizePolicy1.setHeightForWidth(AdditionalOptionFrame->sizePolicy().hasHeightForWidth());
        AdditionalOptionFrame->setSizePolicy(sizePolicy1);
        AdditionalOptionFrame->setFrameShape(QFrame::StyledPanel);
        AdditionalOptionFrame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(AdditionalOptionFrame);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        WattodoL = new QLabel(AdditionalOptionFrame);
        WattodoL->setObjectName(QStringLiteral("WattodoL"));

        formLayout->setWidget(0, QFormLayout::LabelRole, WattodoL);

        PlotKHistogramBtn = new QPushButton(AdditionalOptionFrame);
        PlotKHistogramBtn->setObjectName(QStringLiteral("PlotKHistogramBtn"));
        sizePolicy2.setHeightForWidth(PlotKHistogramBtn->sizePolicy().hasHeightForWidth());
        PlotKHistogramBtn->setSizePolicy(sizePolicy2);

        formLayout->setWidget(2, QFormLayout::LabelRole, PlotKHistogramBtn);

        PlotPHistogramBtn = new QPushButton(AdditionalOptionFrame);
        PlotPHistogramBtn->setObjectName(QStringLiteral("PlotPHistogramBtn"));
        sizePolicy2.setHeightForWidth(PlotPHistogramBtn->sizePolicy().hasHeightForWidth());
        PlotPHistogramBtn->setSizePolicy(sizePolicy2);

        formLayout->setWidget(3, QFormLayout::LabelRole, PlotPHistogramBtn);

        pushButton_5 = new QPushButton(AdditionalOptionFrame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        formLayout->setWidget(4, QFormLayout::LabelRole, pushButton_5);


        gridLayout_6->addWidget(AdditionalOptionFrame, 6, 0, 1, 1);

        VertexFrame = new QFrame(centralWidget);
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
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(VDistributionParamL->sizePolicy().hasHeightForWidth());
        VDistributionParamL->setSizePolicy(sizePolicy3);

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
        sizePolicy2.setHeightForWidth(VDistributionParamDSP->sizePolicy().hasHeightForWidth());
        VDistributionParamDSP->setSizePolicy(sizePolicy2);
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
        sizePolicy3.setHeightForWidth(VDistributionCB->sizePolicy().hasHeightForWidth());
        VDistributionCB->setSizePolicy(sizePolicy3);

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

        VDegreeRangeL = new QLabel(VertexFrame);
        VDegreeRangeL->setObjectName(QStringLiteral("VDegreeRangeL"));
        sizePolicy3.setHeightForWidth(VDegreeRangeL->sizePolicy().hasHeightForWidth());
        VDegreeRangeL->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(VDegreeRangeL, 9, 0, 1, 2);

        VerticiesL = new QLabel(VertexFrame);
        VerticiesL->setObjectName(QStringLiteral("VerticiesL"));
        sizePolicy3.setHeightForWidth(VerticiesL->sizePolicy().hasHeightForWidth());
        VerticiesL->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(VerticiesL, 0, 0, 1, 3);

        VCheckBtn = new QPushButton(VertexFrame);
        VCheckBtn->setObjectName(QStringLiteral("VCheckBtn"));

        gridLayout_2->addWidget(VCheckBtn, 11, 1, 1, 1);

        VUseLoadedChB = new QCheckBox(VertexFrame);
        VUseLoadedChB->setObjectName(QStringLiteral("VUseLoadedChB"));
        VUseLoadedChB->setEnabled(false);
        VUseLoadedChB->setCheckable(false);

        gridLayout_2->addWidget(VUseLoadedChB, 11, 2, 1, 1);


        gridLayout_6->addWidget(VertexFrame, 1, 0, 2, 1);

        HyperEdgeFrame = new QFrame(centralWidget);
        HyperEdgeFrame->setObjectName(QStringLiteral("HyperEdgeFrame"));
        sizePolicy1.setHeightForWidth(HyperEdgeFrame->sizePolicy().hasHeightForWidth());
        HyperEdgeFrame->setSizePolicy(sizePolicy1);
        HyperEdgeFrame->setFrameShape(QFrame::StyledPanel);
        HyperEdgeFrame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(HyperEdgeFrame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        HyperEdgeL = new QLabel(HyperEdgeFrame);
        HyperEdgeL->setObjectName(QStringLiteral("HyperEdgeL"));
        sizePolicy3.setHeightForWidth(HyperEdgeL->sizePolicy().hasHeightForWidth());
        HyperEdgeL->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(HyperEdgeL, 1, 0, 1, 3);

        HDistributionParamDSB = new QDoubleSpinBox(HyperEdgeFrame);
        HDistributionParamDSB->setObjectName(QStringLiteral("HDistributionParamDSB"));
        HDistributionParamDSB->setEnabled(false);
        sizePolicy1.setHeightForWidth(HDistributionParamDSB->sizePolicy().hasHeightForWidth());
        HDistributionParamDSB->setSizePolicy(sizePolicy1);
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
        sizePolicy3.setHeightForWidth(HAverageDegreeL->sizePolicy().hasHeightForWidth());
        HAverageDegreeL->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(HAverageDegreeL, 6, 0, 1, 1);

        HDistibutionL = new QLabel(HyperEdgeFrame);
        HDistibutionL->setObjectName(QStringLiteral("HDistibutionL"));
        sizePolicy3.setHeightForWidth(HDistibutionL->sizePolicy().hasHeightForWidth());
        HDistibutionL->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(HDistibutionL, 2, 0, 1, 1);

        HMinDegreeS = new QSpinBox(HyperEdgeFrame);
        HMinDegreeS->setObjectName(QStringLiteral("HMinDegreeS"));
        HMinDegreeS->setEnabled(false);
        sizePolicy3.setHeightForWidth(HMinDegreeS->sizePolicy().hasHeightForWidth());
        HMinDegreeS->setSizePolicy(sizePolicy3);
        HMinDegreeS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        HMinDegreeS->setMaximum(99999999);

        gridLayout_3->addWidget(HMinDegreeS, 8, 0, 1, 1);

        HtoL = new QLabel(HyperEdgeFrame);
        HtoL->setObjectName(QStringLiteral("HtoL"));

        gridLayout_3->addWidget(HtoL, 8, 1, 1, 1);

        HAverageDegreeS = new QSpinBox(HyperEdgeFrame);
        HAverageDegreeS->setObjectName(QStringLiteral("HAverageDegreeS"));
        sizePolicy.setHeightForWidth(HAverageDegreeS->sizePolicy().hasHeightForWidth());
        HAverageDegreeS->setSizePolicy(sizePolicy);
        HAverageDegreeS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        HAverageDegreeS->setMaximum(99999);
        HAverageDegreeS->setValue(3);

        gridLayout_3->addWidget(HAverageDegreeS, 6, 2, 1, 1);

        HDegreeRandgeL = new QLabel(HyperEdgeFrame);
        HDegreeRandgeL->setObjectName(QStringLiteral("HDegreeRandgeL"));
        sizePolicy3.setHeightForWidth(HDegreeRandgeL->sizePolicy().hasHeightForWidth());
        HDegreeRandgeL->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(HDegreeRandgeL, 7, 0, 1, 3);

        HDistributionParamL = new QLabel(HyperEdgeFrame);
        HDistributionParamL->setObjectName(QStringLiteral("HDistributionParamL"));
        sizePolicy3.setHeightForWidth(HDistributionParamL->sizePolicy().hasHeightForWidth());
        HDistributionParamL->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(HDistributionParamL, 3, 0, 1, 2);

        HDistributionCB = new QComboBox(HyperEdgeFrame);
        HDistributionCB->setObjectName(QStringLiteral("HDistributionCB"));
        sizePolicy.setHeightForWidth(HDistributionCB->sizePolicy().hasHeightForWidth());
        HDistributionCB->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(HDistributionCB, 2, 2, 1, 1);

        HCheckBtn = new QPushButton(HyperEdgeFrame);
        HCheckBtn->setObjectName(QStringLiteral("HCheckBtn"));

        gridLayout_3->addWidget(HCheckBtn, 9, 1, 1, 1);


        gridLayout_6->addWidget(HyperEdgeFrame, 3, 0, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 331, 22));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QStringLiteral("menuFiles"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFiles->menuAction());
        menuFiles->addAction(actionSave_as);
        menuFiles->addAction(actionLoad);
        menuFiles->addAction(actionLoad_kTable);

        retranslateUi(MainWindow);

        AlgorithmsCB->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionLoad_kTable->setText(QApplication::translate("MainWindow", "Load kTable", 0));
        StartBtn->setText(QApplication::translate("MainWindow", "4. Create HyperGraph", 0));
        AlgorithmL->setText(QApplication::translate("MainWindow", "1. Choose Algorithm :", 0));
        AlgorithmsCB->clear();
        AlgorithmsCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random Hypergraph", 0)
         << QApplication::translate("MainWindow", "Full HyperGraph", 0)
         << QApplication::translate("MainWindow", "Test", 0)
         << QApplication::translate("MainWindow", "Choose Algorithm", 0)
        );
        WattodoL->setText(QApplication::translate("MainWindow", "5. Additional Options :", 0));
        PlotKHistogramBtn->setText(QApplication::translate("MainWindow", "Plot k-Histgram", 0));
        PlotPHistogramBtn->setText(QApplication::translate("MainWindow", "Plot p-Histogram", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Draw HyperGraph", 0));
        AmountL->setText(QApplication::translate("MainWindow", "Amount :", 0));
        VtoL->setText(QApplication::translate("MainWindow", " to", 0));
        VDistributionParamL->setText(QApplication::translate("MainWindow", "Parameter", 0));
        VAvarageDegreeL->setText(QApplication::translate("MainWindow", "Degree :", 0));
        VDistributionCB->clear();
        VDistributionCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Constant", 0)
         << QApplication::translate("MainWindow", "Uniform", 0)
         << QApplication::translate("MainWindow", "Poisson", 0)
         << QApplication::translate("MainWindow", "Geometric", 0)
         << QApplication::translate("MainWindow", "Power Law", 0)
        );
        VDistributionL->setText(QApplication::translate("MainWindow", "Distribution :", 0));
        VDegreeRangeL->setText(QApplication::translate("MainWindow", "Degree Range :", 0));
        VerticiesL->setText(QApplication::translate("MainWindow", "<html><head/><body><p>2. Vertex degree distribution</p></body></html>", 0));
        VCheckBtn->setText(QApplication::translate("MainWindow", "Check", 0));
        VUseLoadedChB->setText(QApplication::translate("MainWindow", "use Loaded", 0));
        HyperEdgeL->setText(QApplication::translate("MainWindow", "<html><head/><body><p>3. Hyperegde degree distribution</p></body></html>", 0));
        HAverageDegreeL->setText(QApplication::translate("MainWindow", "Degree :", 0));
        HDistibutionL->setText(QApplication::translate("MainWindow", "Distribution :", 0));
        HtoL->setText(QApplication::translate("MainWindow", "to", 0));
        HDegreeRandgeL->setText(QApplication::translate("MainWindow", "Degree Range :", 0));
        HDistributionParamL->setText(QApplication::translate("MainWindow", "Parameter", 0));
        HDistributionCB->clear();
        HDistributionCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Constant", 0)
         << QApplication::translate("MainWindow", "Uniform", 0)
         << QApplication::translate("MainWindow", "Poisson", 0)
         << QApplication::translate("MainWindow", "Geometric", 0)
         << QApplication::translate("MainWindow", "Power Law", 0)
        );
        HCheckBtn->setText(QApplication::translate("MainWindow", "Check", 0));
        menuFiles->setTitle(QApplication::translate("MainWindow", "Files", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
