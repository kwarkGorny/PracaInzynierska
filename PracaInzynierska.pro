#-------------------------------------------------
#
# Project created by QtCreator 2017-07-11T14:44:00
#
#-------------------------------------------------


QT  += core gui printsupport
CONFIG += c++1z
QMAKE_CXXFLAGS += -O3 -Wall -pedantic -Wno-sign-conversion
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FullGUI
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
    HGStruct/hyperedge.cpp \
    HGStruct/hypergraph.cpp \
    HGStruct/vertex.cpp \
    Matrix/adjacencylist.cpp \
    Matrix/hypergraphmatrix.cpp \
    Matrix/ihypergraph.cpp \
    Matrix/incidencymatrix.cpp \
    Patterns/hypergraphfabric.cpp \
    Patterns/hypergraphmanager.cpp \
    QCustomPlot/qcustomplot.cpp \
    Patterns/randomnumber.cpp\
    GUI/guihyperedge.cpp \
    GUI/guivertex.cpp \
    GUI/mainwindow.cpp \
    Patterns/adjacencylistfabric.cpp

HEADERS  +=     HGStruct/hyperedge.h \
    HGStruct/hypergraph.h \
    HGStruct/vertex.h \
    Matrix/adjacencylist.h \
    Matrix/hypergraphmatrix.h \
    Matrix/ihypergraph.h \
    Matrix/incidencymatrix.h \
    Patterns/hypergraphfabric.h \
    Patterns/hypergraphmanager.h \
    QCustomPlot/qcustomplot.h \
    Patterns/enums.h \
    Patterns/randomnumber.h\
    GUI/guihyperedge.h \
    GUI/guivertex.h \
    GUI/mainwindow.h \
    Patterns/adjacencylistfabric.h

FORMS    += mainwindow.ui
