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
    QCustomPlot *pPlotWidget;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_10;
    QPushButton *HAnalyzeBtn;
    QLabel *PStandDevPL;
    QLabel *PChiSquareL;
    QLabel *PAveragePL;
    QLabel *label_2;
    QLabel *PStudentTestL;
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
        pPlotWidget = new QCustomPlot(centralwidget);
        pPlotWidget->setObjectName(QStringLiteral("pPlotWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pPlotWidget->sizePolicy().hasHeightForWidth());
        pPlotWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pPlotWidget, 0, 1, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_11, 4, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label, 1, 0, 1, 4);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        HAnalyzeBtn = new QPushButton(frame);
        HAnalyzeBtn->setObjectName(QStringLiteral("HAnalyzeBtn"));

        gridLayout_2->addWidget(HAnalyzeBtn, 0, 0, 1, 4);

        PStandDevPL = new QLabel(frame);
        PStandDevPL->setObjectName(QStringLiteral("PStandDevPL"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PStandDevPL->sizePolicy().hasHeightForWidth());
        PStandDevPL->setSizePolicy(sizePolicy2);
        PStandDevPL->setLayoutDirection(Qt::LeftToRight);
        PStandDevPL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(PStandDevPL, 4, 1, 1, 3);

        PChiSquareL = new QLabel(frame);
        PChiSquareL->setObjectName(QStringLiteral("PChiSquareL"));
        PChiSquareL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(PChiSquareL, 3, 1, 1, 3);

        PAveragePL = new QLabel(frame);
        PAveragePL->setObjectName(QStringLiteral("PAveragePL"));
        sizePolicy2.setHeightForWidth(PAveragePL->sizePolicy().hasHeightForWidth());
        PAveragePL->setSizePolicy(sizePolicy2);
        PAveragePL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(PAveragePL, 2, 1, 1, 3);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 5, 0, 1, 1);

        PStudentTestL = new QLabel(frame);
        PStudentTestL->setObjectName(QStringLiteral("PStudentTestL"));
        PStudentTestL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(PStudentTestL, 5, 1, 1, 3);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

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
        label_11->setText(QApplication::translate("PHistogramWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\316\247<span style=\" vertical-align:super;\">2 </span>= </p></body></html>", 0));
        label->setText(QApplication::translate("PHistogramWindow", "HyperEdge Results :", 0));
        label_8->setText(QApplication::translate("PHistogramWindow", "<html><head/><body><p>\317\203<span style=\" vertical-align:sub;\">p</span> =</p></body></html>", 0));
        label_10->setText(QApplication::translate("PHistogramWindow", "<html><head/><body><p>\316\274(p) =</p></body></html>", 0));
        HAnalyzeBtn->setText(QApplication::translate("PHistogramWindow", "Analyze ", 0));
        PStandDevPL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        PChiSquareL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        PAveragePL->setText(QApplication::translate("PHistogramWindow", "0", 0));
        label_2->setText(QApplication::translate("PHistogramWindow", "t =", 0));
        PStudentTestL->setText(QApplication::translate("PHistogramWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class PHistogramWindow: public Ui_PHistogramWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHISTOGRAMWINDOW_H
