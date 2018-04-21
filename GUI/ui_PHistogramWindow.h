/********************************************************************************
** Form generated from reading UI file 'PHistogramWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHISTOGRAMWINDOW_H
#define UI_PHISTOGRAMWINDOW_H

#include <QCustomPlot/qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PHistogramWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCheckBox *YAxisLogScalChb;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *PStandDevPL;
    QLabel *label;
    QLabel *label_8;
    QLabel *PAveragePL;
    QLabel *label_2;
    QLabel *label_10;
    QLabel *PMedianPL;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_3;
    QLabel *PStandDevTheoL;
    QLabel *PMeanTheoL;
    QLabel *label_4;
    QLabel *PMedianTheoL;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    QLabel *label_17;
    QLabel *PStudentTestL;
    QLabel *label_19;
    QLabel *PChiSquareL;
    QLabel *label_7;
    QCheckBox *XAxisLogScalChb;
    QPushButton *HAnalyzeBtn;
    QCustomPlot *pPlotWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PHistogramWindow)
    {
        if (PHistogramWindow->objectName().isEmpty())
            PHistogramWindow->setObjectName(QStringLiteral("PHistogramWindow"));
        PHistogramWindow->resize(800, 600);
        centralwidget = new QWidget(PHistogramWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        YAxisLogScalChb = new QCheckBox(centralwidget);
        YAxisLogScalChb->setObjectName(QStringLiteral("YAxisLogScalChb"));

        gridLayout->addWidget(YAxisLogScalChb, 5, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        PStandDevPL = new QLabel(frame);
        PStandDevPL->setObjectName(QStringLiteral("PStandDevPL"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PStandDevPL->sizePolicy().hasHeightForWidth());
        PStandDevPL->setSizePolicy(sizePolicy1);
        PStandDevPL->setLayoutDirection(Qt::LeftToRight);
        PStandDevPL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(PStandDevPL, 8, 0, 1, 3);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label, 1, 0, 1, 3);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_8, 7, 0, 1, 3);

        PAveragePL = new QLabel(frame);
        PAveragePL->setObjectName(QStringLiteral("PAveragePL"));
        sizePolicy1.setHeightForWidth(PAveragePL->sizePolicy().hasHeightForWidth());
        PAveragePL->setSizePolicy(sizePolicy1);
        PAveragePL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(PAveragePL, 3, 0, 1, 3);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 4, 0, 1, 2);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_10, 2, 0, 1, 2);

        PMedianPL = new QLabel(frame);
        PMedianPL->setObjectName(QStringLiteral("PMedianPL"));
        sizePolicy1.setHeightForWidth(PMedianPL->sizePolicy().hasHeightForWidth());
        PMedianPL->setSizePolicy(sizePolicy1);
        PMedianPL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(PMedianPL, 6, 0, 1, 3);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_9, 5, 0, 1, 1);

        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_13, 1, 0, 1, 2);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 2);

        PStandDevTheoL = new QLabel(frame_3);
        PStandDevTheoL->setObjectName(QStringLiteral("PStandDevTheoL"));
        PStandDevTheoL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(PStandDevTheoL, 6, 0, 1, 1);

        PMeanTheoL = new QLabel(frame_3);
        PMeanTheoL->setObjectName(QStringLiteral("PMeanTheoL"));
        sizePolicy1.setHeightForWidth(PMeanTheoL->sizePolicy().hasHeightForWidth());
        PMeanTheoL->setSizePolicy(sizePolicy1);
        PMeanTheoL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(PMeanTheoL, 2, 0, 1, 2);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 3, 0, 1, 1);

        PMedianTheoL = new QLabel(frame_3);
        PMedianTheoL->setObjectName(QStringLiteral("PMedianTheoL"));
        PMedianTheoL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(PMedianTheoL, 4, 0, 1, 1);


        gridLayout->addWidget(frame_3, 1, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy3);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_17 = new QLabel(frame_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(label_17, 1, 1, 1, 1);

        PStudentTestL = new QLabel(frame_2);
        PStudentTestL->setObjectName(QStringLiteral("PStudentTestL"));
        PStudentTestL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(PStudentTestL, 1, 2, 1, 1);

        label_19 = new QLabel(frame_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(label_19, 2, 1, 1, 1);

        PChiSquareL = new QLabel(frame_2);
        PChiSquareL->setObjectName(QStringLiteral("PChiSquareL"));
        PChiSquareL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(PChiSquareL, 2, 2, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(label_7, 0, 1, 1, 2);


        gridLayout->addWidget(frame_2, 2, 0, 2, 1);

        XAxisLogScalChb = new QCheckBox(centralwidget);
        XAxisLogScalChb->setObjectName(QStringLiteral("XAxisLogScalChb"));

        gridLayout->addWidget(XAxisLogScalChb, 4, 0, 1, 1);

        HAnalyzeBtn = new QPushButton(centralwidget);
        HAnalyzeBtn->setObjectName(QStringLiteral("HAnalyzeBtn"));

        gridLayout->addWidget(HAnalyzeBtn, 6, 0, 1, 1);

        pPlotWidget = new QCustomPlot(centralwidget);
        pPlotWidget->setObjectName(QStringLiteral("pPlotWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pPlotWidget->sizePolicy().hasHeightForWidth());
        pPlotWidget->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pPlotWidget, 0, 1, 7, 1);

        PHistogramWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PHistogramWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        PHistogramWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PHistogramWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PHistogramWindow->setStatusBar(statusbar);

        retranslateUi(PHistogramWindow);

        QMetaObject::connectSlotsByName(PHistogramWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PHistogramWindow)
    {
        PHistogramWindow->setWindowTitle(QApplication::translate("PHistogramWindow", "MainWindow", 0));
        YAxisLogScalChb->setText(QApplication::translate("PHistogramWindow", "y-axis log scale", 0));
        PStandDevPL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        label->setText(QApplication::translate("PHistogramWindow", "HyperEdge Results :", 0));
        label_8->setText(QApplication::translate("PHistogramWindow", "<html><head/><body><p>Standard deviation :</p></body></html>", 0));
        PAveragePL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        label_2->setText(QApplication::translate("PHistogramWindow", "Median :", 0));
        label_10->setText(QApplication::translate("PHistogramWindow", "<html><head/><body><p>Mean :</p></body></html>", 0));
        PMedianPL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        label_9->setText(QApplication::translate("PHistogramWindow", "<html><head/><body><p>Standard deviation :</p></body></html>", 0));
        label_13->setText(QApplication::translate("PHistogramWindow", "<html><head/><body><p>Mean :</p></body></html>", 0));
        label_3->setText(QApplication::translate("PHistogramWindow", "Theoretical Values :", 0));
        PStandDevTheoL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        PMeanTheoL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        label_4->setText(QApplication::translate("PHistogramWindow", "Median :", 0));
        PMedianTheoL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        label_17->setText(QApplication::translate("PHistogramWindow", "t-Student", 0));
        PStudentTestL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        label_19->setText(QApplication::translate("PHistogramWindow", "<html><head/><body><p>\316\247<span style=\" vertical-align:super;\">2 </span>= </p></body></html>", 0));
        PChiSquareL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        label_7->setText(QApplication::translate("PHistogramWindow", "Statistic Tests Result:", 0));
        XAxisLogScalChb->setText(QApplication::translate("PHistogramWindow", "x-axis log scale", 0));
        HAnalyzeBtn->setText(QApplication::translate("PHistogramWindow", "Analyze ", 0));
    } // retranslateUi

};

namespace Ui {
    class PHistogramWindow: public Ui_PHistogramWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHISTOGRAMWINDOW_H
