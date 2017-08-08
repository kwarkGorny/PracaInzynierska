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
    GUI/guihyperedge.cpp \
    GUI/guivertex.cpp \
    GUI/mainwindow.cpp \
    HGStruct/hyperedge.cpp \
    HGStruct/hypergraph.cpp \
    HGStruct/vertex.cpp \
    Matrix/adjacencylist.cpp \
    Matrix/hypergraphmatrix.cpp \
    Matrix/ihypergraph.cpp \
    Matrix/incidencymatrix.cpp \
    Patterns/hypergraphfabric.cpp \
    Patterns/hypergraphmanager.cpp \
    QCustomPlot/qcustomplot.cpp

HEADERS  += GUI/guihyperedge.h \
    GUI/guivertex.h \
    GUI/mainwindow.h \
    HGStruct/hyperedge.h \
    HGStruct/hypergraph.h \
    HGStruct/vertex.h \
    Matrix/adjacencylist.h \
    Matrix/hypergraphmatrix.h \
    Matrix/ihypergraph.h \
    Matrix/incidencymatrix.h \
    Patterns/hypergraphfabric.h \
    Patterns/hypergraphmanager.h \
    QCustomPlot/qcustomplot.h

FORMS    += mainwindow.ui
