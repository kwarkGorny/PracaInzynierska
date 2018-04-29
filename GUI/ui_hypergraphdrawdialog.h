/********************************************************************************
** Form generated from reading UI file 'hypergraphdrawdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HYPERGRAPHDRAWDIALOG_H
#define UI_HYPERGRAPHDRAWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HyperGraphDrawDialog
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *HypergraphView;
    QPushButton *HypergraphDrawButton;

    void setupUi(QDialog *HyperGraphDrawDialog)
    {
        if (HyperGraphDrawDialog->objectName().isEmpty())
            HyperGraphDrawDialog->setObjectName(QStringLiteral("HyperGraphDrawDialog"));
        HyperGraphDrawDialog->resize(684, 579);
        gridLayout = new QGridLayout(HyperGraphDrawDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        HypergraphView = new QGraphicsView(HyperGraphDrawDialog);
        HypergraphView->setObjectName(QStringLiteral("HypergraphView"));

        gridLayout->addWidget(HypergraphView, 0, 0, 1, 1);

        HypergraphDrawButton = new QPushButton(HyperGraphDrawDialog);
        HypergraphDrawButton->setObjectName(QStringLiteral("HypergraphDrawButton"));

        gridLayout->addWidget(HypergraphDrawButton, 1, 0, 1, 1);


        retranslateUi(HyperGraphDrawDialog);

        QMetaObject::connectSlotsByName(HyperGraphDrawDialog);
    } // setupUi

    void retranslateUi(QDialog *HyperGraphDrawDialog)
    {
        HyperGraphDrawDialog->setWindowTitle(QApplication::translate("HyperGraphDrawDialog", "Dialog", 0));
        HypergraphDrawButton->setText(QApplication::translate("HyperGraphDrawDialog", "Draw HyperGraph", 0));
    } // retranslateUi

};

namespace Ui {
    class HyperGraphDrawDialog: public Ui_HyperGraphDrawDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HYPERGRAPHDRAWDIALOG_H
