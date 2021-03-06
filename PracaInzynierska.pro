#-------------------------------------------------
#
# Project created by QtCreator 2017-07-11T14:44:00
#
#-------------------------------------------------


QT  += core gui printsupport

CONFIG+= strict_c++ c++1z

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += /usr/include/boost
LIBS += -L/usr/include/boost -lboost_system -lboost_chrono -lboost_thread -lboost_timer


TARGET = AdamSzczepanskiPracaInzynierska
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
    QCustomPlot/qcustomplot.cpp \
    GUI/guihyperedge.cpp \
    GUI/guivertex.cpp \
    GUI/mainwindow.cpp \
    Tests/guitest.cpp \
    Distributions/distribution.cpp \
    Distributions/uniform.cpp \
    Distributions/poisson.cpp \
    Distributions/geometric.cpp \
    Distributions/constant.cpp \
    GUI/hypergraphdrawdialog.cpp \
    Patterns/Statistics.cpp \
    GUI/KHistogramWindow.cpp \
    GUI/PHistogramWindow.cpp \
    Patterns/Data.cpp \
    Patterns/RandomSystem.cpp \
    Distributions/powerlaw.cpp \
    HyperGraph/HyperGraph.cpp \
    HyperGraph/HyperGraphFabric.cpp \
    HyperGraph/HyperGraphManager.cpp \
    Patterns/Utils.cpp \
    Patterns/fileoperation.cpp

HEADERS  +=  QCustomPlot/qcustomplot.h \
    GUI/guihyperedge.h \
    GUI/guivertex.h \
    GUI/mainwindow.h \
    Tests/guitest.h \
    ui_mainwindow.h \
    Distributions/distribution.h \
    Distributions/uniform.h \
    Distributions/poisson.h \
    Distributions/geometric.h \
    Distributions/constant.h \
    GUI/hypergraphdrawdialog.h \
    Patterns/Statistics.h \
    GUI/KHistogramWindow.h \
    GUI/PHistogramWindow.h \
    Patterns/Data.h \
    Patterns/RandomSystem.h \
    Distributions/powerlaw.h \
    GUI/ui_hypergraphdrawdialog.h \
    GUI/ui_KHistogramWindow.h \
    GUI/ui_PHistogramWindow.h \
    HyperGraph/HyperGraph.h \
    HyperGraph/HyperGraphManager.h \
    HyperGraph/HyperGraphFabric.h \
    Patterns/Utils.h \
    Patterns/fileoperation.h

FORMS    += mainwindow.ui \
    GUI/hypergraphdrawdialog.ui \
    GUI/KHistogramWindow.ui \
    GUI/PHistogramWindow.ui
