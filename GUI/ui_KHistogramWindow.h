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
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QLabel *VStandDevKL;
    QLabel *VAverageKL;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QPushButton *VAnalyzeBtn;
    QLabel *VChiSquareL;
    QCustomPlot *kPlotWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *KHistogramWindow)
    {
        if (KHistogramWindow->objectName().isEmpty())
            KHistogramWindow->setObjectName(QStringLiteral("KHistogramWindow"));
        KHistogramWindow->resize(800, 600);
        actionSave_as = new QAction(KHistogramWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        centralwidget = new QWidget(KHistogramWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_9, 6, 0, 1, 1);

        VStandDevKL = new QLabel(frame);
        VStandDevKL->setObjectName(QStringLiteral("VStandDevKL"));
        VStandDevKL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(VStandDevKL, 4, 1, 1, 1);

        VAverageKL = new QLabel(frame);
        VAverageKL->setObjectName(QStringLiteral("VAverageKL"));
        VAverageKL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(VAverageKL, 2, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label, 1, 0, 1, 2);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        VAnalyzeBtn = new QPushButton(frame);
        VAnalyzeBtn->setObjectName(QStringLiteral("VAnalyzeBtn"));

        gridLayout_2->addWidget(VAnalyzeBtn, 0, 0, 1, 2);

        VChiSquareL = new QLabel(frame);
        VChiSquareL->setObjectName(QStringLiteral("VChiSquareL"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(VChiSquareL->sizePolicy().hasHeightForWidth());
        VChiSquareL->setSizePolicy(sizePolicy1);
        VChiSquareL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(VChiSquareL, 6, 1, 1, 1);

        label->raise();
        VAnalyzeBtn->raise();
        VAverageKL->raise();
        VAverageKL->raise();
        VStandDevKL->raise();
        VChiSquareL->raise();
        label_3->raise();
        label_4->raise();
        label_9->raise();

        gridLayout->addWidget(frame, 0, 0, 1, 1);

        kPlotWidget = new QCustomPlot(centralwidget);
        kPlotWidget->setObjectName(QStringLiteral("kPlotWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(kPlotWidget->sizePolicy().hasHeightForWidth());
        kPlotWidget->setSizePolicy(sizePolicy2);
        frame->raise();

        gridLayout->addWidget(kPlotWidget, 0, 1, 1, 1);

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
        label_9->setText(QApplication::translate("KHistogramWindow", "<html><head/><body><p>\316\247<span style=\" vertical-align:super;\">2</span> = </p></body></html>", 0));
        VStandDevKL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        VAverageKL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        label_3->setText(QApplication::translate("KHistogramWindow", "<html><head/><body><p>\316\274(k) =</p></body></html>", 0));
        label->setText(QApplication::translate("KHistogramWindow", "Vertex Results :", 0));
        label_4->setText(QApplication::translate("KHistogramWindow", "<html><head/><body><p>\317\203<span style=\" vertical-align:sub;\">k</span> =</p></body></html>", 0));
        VAnalyzeBtn->setText(QApplication::translate("KHistogramWindow", "Analyze ", 0));
        VChiSquareL->setText(QApplication::translate("KHistogramWindow", "0", 0));
        menuFile->setTitle(QApplication::translate("KHistogramWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class KHistogramWindow: public Ui_KHistogramWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KHISTOGRAMWINDOW_H
