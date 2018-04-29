/********************************************************************************
** Form generated from reading UI file 'KHistogramWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KHISTOGRAMWINDOW_H
#define UI_KHISTOGRAMWINDOW_H

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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KHistogramWindow
{
public:
    QAction *actionSave_as;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *kPlotWidget;
    QFrame *frame_5;
    QGridLayout *gridLayout_8;
    QLabel *VAverageKL;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *VMedianKL;
    QLabel *label;
    QLabel *VStandDevKL;
    QFrame *frame_3;
    QGridLayout *gridLayout_6;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_18;
    QLabel *VStandDevTheoL;
    QLabel *VMeanTheoL;
    QLabel *label_20;
    QLabel *VMedianTheoL;
    QFrame *frame_4;
    QGridLayout *gridLayout_7;
    QLabel *VChiSquareL;
    QLabel *VStudentTestL;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_21;
    QLabel *label_2;
    QLabel *KFredomDegreeL;
    QPushButton *VAnalyzeBtn;
    QCheckBox *XAxisLogScalChb;
    QCheckBox *YAxisLogScalChb;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *KHistogramWindow)
    {
        if (KHistogramWindow->objectName().isEmpty())
            KHistogramWindow->setObjectName(QStringLiteral("KHistogramWindow"));
        KHistogramWindow->resize(800, 602);
        actionSave_as = new QAction(KHistogramWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        centralwidget = new QWidget(KHistogramWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        kPlotWidget = new QCustomPlot(centralwidget);
        kPlotWidget->setObjectName(QStringLiteral("kPlotWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(kPlotWidget->sizePolicy().hasHeightForWidth());
        kPlotWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(kPlotWidget, 0, 1, 8, 1);

        frame_5 = new QFrame(centralwidget);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy1);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_5);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        VAverageKL = new QLabel(frame_5);
        VAverageKL->setObjectName(QStringLiteral("VAverageKL"));
        VAverageKL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(VAverageKL, 3, 0, 1, 3);

        label_25 = new QLabel(frame_5);
        label_25->setObjectName(QStringLiteral("label_25"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy2);

        gridLayout_8->addWidget(label_25, 7, 0, 1, 3);

        label_26 = new QLabel(frame_5);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_8->addWidget(label_26, 4, 0, 1, 2);

        label_27 = new QLabel(frame_5);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy1.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(label_27, 2, 0, 1, 2);

        VMedianKL = new QLabel(frame_5);
        VMedianKL->setObjectName(QStringLiteral("VMedianKL"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(VMedianKL->sizePolicy().hasHeightForWidth());
        VMedianKL->setSizePolicy(sizePolicy3);
        VMedianKL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(VMedianKL, 6, 0, 1, 3);

        label = new QLabel(frame_5);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(label, 1, 0, 1, 1);

        VStandDevKL = new QLabel(frame_5);
        VStandDevKL->setObjectName(QStringLiteral("VStandDevKL"));
        VStandDevKL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(VStandDevKL, 8, 0, 1, 3);


        gridLayout->addWidget(frame_5, 1, 0, 1, 1);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_3);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_15 = new QLabel(frame_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(label_15, 5, 0, 1, 1);

        label_16 = new QLabel(frame_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(label_16, 1, 0, 1, 2);

        label_18 = new QLabel(frame_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(label_18, 0, 0, 1, 2);

        VStandDevTheoL = new QLabel(frame_3);
        VStandDevTheoL->setObjectName(QStringLiteral("VStandDevTheoL"));
        VStandDevTheoL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(VStandDevTheoL, 6, 0, 1, 1);

        VMeanTheoL = new QLabel(frame_3);
        VMeanTheoL->setObjectName(QStringLiteral("VMeanTheoL"));
        sizePolicy3.setHeightForWidth(VMeanTheoL->sizePolicy().hasHeightForWidth());
        VMeanTheoL->setSizePolicy(sizePolicy3);
        VMeanTheoL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(VMeanTheoL, 2, 0, 1, 2);

        label_20 = new QLabel(frame_3);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_6->addWidget(label_20, 3, 0, 1, 1);

        VMedianTheoL = new QLabel(frame_3);
        VMedianTheoL->setObjectName(QStringLiteral("VMedianTheoL"));
        VMedianTheoL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(VMedianTheoL, 4, 0, 1, 1);


        gridLayout->addWidget(frame_3, 2, 0, 1, 1);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy4);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_4);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        VChiSquareL = new QLabel(frame_4);
        VChiSquareL->setObjectName(QStringLiteral("VChiSquareL"));
        sizePolicy3.setHeightForWidth(VChiSquareL->sizePolicy().hasHeightForWidth());
        VChiSquareL->setSizePolicy(sizePolicy3);
        VChiSquareL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(VChiSquareL, 2, 2, 1, 1);

        VStudentTestL = new QLabel(frame_4);
        VStudentTestL->setObjectName(QStringLiteral("VStudentTestL"));
        VStudentTestL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(VStudentTestL, 1, 2, 1, 1);

        label_22 = new QLabel(frame_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy1.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_22, 2, 1, 1, 1);

        label_23 = new QLabel(frame_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy1.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_23, 0, 1, 1, 2);

        label_21 = new QLabel(frame_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_21, 1, 1, 1, 1);

        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_7->addWidget(label_2, 3, 1, 1, 1);

        KFredomDegreeL = new QLabel(frame_4);
        KFredomDegreeL->setObjectName(QStringLiteral("KFredomDegreeL"));
        KFredomDegreeL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(KFredomDegreeL, 3, 2, 1, 1);


        gridLayout->addWidget(frame_4, 3, 0, 1, 1);

        VAnalyzeBtn = new QPushButton(centralwidget);
        VAnalyzeBtn->setObjectName(QStringLiteral("VAnalyzeBtn"));

        gridLayout->addWidget(VAnalyzeBtn, 6, 0, 1, 1);

        XAxisLogScalChb = new QCheckBox(centralwidget);
        XAxisLogScalChb->setObjectName(QStringLiteral("XAxisLogScalChb"));

        gridLayout->addWidget(XAxisLogScalChb, 4, 0, 1, 1);

        YAxisLogScalChb = new QCheckBox(centralwidget);
        YAxisLogScalChb->setObjectName(QStringLiteral("YAxisLogScalChb"));

        gridLayout->addWidget(YAxisLogScalChb, 5, 0, 1, 1);

        KHistogramWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(KHistogramWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        KHistogramWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(KHistogramWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        KHistogramWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave_as);

        retranslateUi(KHistogramWindow);

        QMetaObject::connectSlotsByName(KHistogramWindow);
    } // setupUi

    void retranslateUi(QMainWindow *KHistogramWindow)
    {
        KHistogramWindow->setWindowTitle(QApplication::translate("KHistogramWindow", "MainWindow", 0));
        actionSave_as->setText(QApplication::translate("KHistogramWindow", "Save as...", 0));
        VAverageKL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        label_25->setText(QApplication::translate("KHistogramWindow", "<html><head/><body><p>Standard deviation :</p></body></html>", 0));
        label_26->setText(QApplication::translate("KHistogramWindow", "Median :", 0));
        label_27->setText(QApplication::translate("KHistogramWindow", "<html><head/><body><p>Mean :</p></body></html>", 0));
        VMedianKL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        label->setText(QApplication::translate("KHistogramWindow", "Vertex Results :", 0));
        VStandDevKL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        label_15->setText(QApplication::translate("KHistogramWindow", "<html><head/><body><p>Standard deviation :</p></body></html>", 0));
        label_16->setText(QApplication::translate("KHistogramWindow", "<html><head/><body><p>Mean :</p></body></html>", 0));
        label_18->setText(QApplication::translate("KHistogramWindow", "Theoretical Values :", 0));
        VStandDevTheoL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        VMeanTheoL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        label_20->setText(QApplication::translate("KHistogramWindow", "Median :", 0));
        VMedianTheoL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        VChiSquareL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        VStudentTestL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        label_22->setText(QApplication::translate("KHistogramWindow", "<html><head/><body><p>\316\247<span style=\" vertical-align:super;\">2 </span>= </p></body></html>", 0));
        label_23->setText(QApplication::translate("KHistogramWindow", "Statistic Tests Result:", 0));
        label_21->setText(QApplication::translate("KHistogramWindow", "t-Student", 0));
        label_2->setText(QApplication::translate("KHistogramWindow", "d=", 0));
        KFredomDegreeL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        VAnalyzeBtn->setText(QApplication::translate("KHistogramWindow", "Analyze ", 0));
        XAxisLogScalChb->setText(QApplication::translate("KHistogramWindow", "x axis log scal", 0));
        YAxisLogScalChb->setText(QApplication::translate("KHistogramWindow", "y Axis log scal", 0));
        menuFile->setTitle(QApplication::translate("KHistogramWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class KHistogramWindow: public Ui_KHistogramWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KHISTOGRAMWINDOW_H
