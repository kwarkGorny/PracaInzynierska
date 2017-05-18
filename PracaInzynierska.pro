
QT       += core gui
CONFIG += c++14
QMAKE_CXXFLAGS += -O3 -Wall -pedantic -g
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PracaInzynierska
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS





SOURCES += main.cpp\
    GUI/mainwindow.cpp \
    HGStruct/hyperedge.cpp \
    HGStruct/hypergraph.cpp \
    HGStruct/vertex.cpp \
    Matrix/hypergraphmatrix.cpp \
    Matrix/incidencymatrix.cpp \
    Patterns/hypergraphfabric.cpp \
    Patterns/hypergraphmanager.cpp \
    Tests/incidencymatrixtests.cpp \
    Tests/guitest.cpp \
    GUI/guivertex.cpp \
    GUI/guihyperedge.cpp

HEADERS  +=  GUI/mainwindow.h \
    HGStruct/hyperedge.h \
    HGStruct/hypergraph.h \
    HGStruct/vertex.h \
    Matrix/hypergraphmatrix.h \
    Matrix/incidencymatrix.h \
    Patterns/hypergraphfabric.h \
    Patterns/hypergraphmanager.h \
    Tests/guitest.h \
    Tests/incidencymatrixtests.h \
    GUI/guivertex.h \
    GUI/guihyperedge.h

FORMS    += mainwindow.ui

DISTFILES += \
    Source/TODO
