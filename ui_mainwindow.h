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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelNumberOfVertices;
    QSpinBox *boxNumberOfVertices;
    QLabel *labelSizeOfHyperedge;
    QSpinBox *boxSizeOfHyperedge;
    QPushButton *pushButton;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_2;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *graphicsView;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *WykresK;
    QCustomPlot *WykresP;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(976, 699);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelNumberOfVertices = new QLabel(frame_4);
        labelNumberOfVertices->setObjectName(QStringLiteral("labelNumberOfVertices"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelNumberOfVertices->sizePolicy().hasHeightForWidth());
        labelNumberOfVertices->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(labelNumberOfVertices);

        boxNumberOfVertices = new QSpinBox(frame_4);
        boxNumberOfVertices->setObjectName(QStringLiteral("boxNumberOfVertices"));
        boxNumberOfVertices->setMaximum(999999999);
        boxNumberOfVertices->setValue(10);

        verticalLayout_4->addWidget(boxNumberOfVertices);

        labelSizeOfHyperedge = new QLabel(frame_4);
        labelSizeOfHyperedge->setObjectName(QStringLiteral("labelSizeOfHyperedge"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelSizeOfHyperedge->sizePolicy().hasHeightForWidth());
        labelSizeOfHyperedge->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(labelSizeOfHyperedge);

        boxSizeOfHyperedge = new QSpinBox(frame_4);
        boxSizeOfHyperedge->setObjectName(QStringLiteral("boxSizeOfHyperedge"));
        boxSizeOfHyperedge->setMinimum(1);
        boxSizeOfHyperedge->setMaximum(999999999);
        boxSizeOfHyperedge->setValue(3);

        verticalLayout_4->addWidget(boxSizeOfHyperedge);

        pushButton = new QPushButton(frame_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_4->addWidget(pushButton);


        verticalLayout->addWidget(frame_4);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_2 = new QPushButton(frame_5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(true);

        verticalLayout_5->addWidget(pushButton_2);


        verticalLayout->addWidget(frame_5);


        horizontalLayout->addWidget(frame);

        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        graphicsView = new QGraphicsView(frame_3);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(graphicsView);


        horizontalLayout->addWidget(frame_3);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        WykresK = new QCustomPlot(frame_2);
        WykresK->setObjectName(QStringLiteral("WykresK"));

        verticalLayout_2->addWidget(WykresK);

        WykresP = new QCustomPlot(frame_2);
        WykresP->setObjectName(QStringLiteral("WykresP"));

        verticalLayout_2->addWidget(WykresP);


        horizontalLayout->addWidget(frame_2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labelNumberOfVertices->setText(QApplication::translate("MainWindow", "Number of Vertices", 0));
        labelSizeOfHyperedge->setText(QApplication::translate("MainWindow", "Degree of HyperEdge", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Losuj Hipergraf", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Zapisz Do pliku", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
