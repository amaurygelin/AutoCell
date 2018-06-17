QT += widgets
QT += sql

QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

SOURCES += \
    AbstractGameOfLife.cpp \
    autocellelem.cpp \
    autocellGol.cpp \
    autocellquad.cpp \
    Automaton.cpp \
    dbManager.cpp \
    ElementaryAutomaton.cpp \
    GameOfLife.cpp \
    grid.cpp \
    main.cpp \
    mainWindow.cpp \
    QuadLife.cpp \
    randomGridGenerator.cpp \
    saveManager.cpp \
    saveuicontext.cpp \
    simulator.cpp \
    symmetricDGridGenerator.cpp \
    symmetricHGridGenerator.cpp \
    symmetricVGridGenerator.cpp

HEADERS += \
    AbstractGameOfLife.h \
    autocell.h \
    autocellabstractgol.h \
    autocellelem.h \
    autocellGol.h \
    autocellquad.h \
    Automaton.h \
    dbManager.h \
    ElementaryAutomaton.h \
    GameOfLife.h \
    grid.h \
    gridGenerator.h \
    mainWindow.h \
    QuadLife.h \
    randomGridGenerator.h \
    saveManager.h \
    saveuicontext.h \
    simulator.h \
    symmetricDGridGenerator.h \
    symmetricHGridGenerator.h \
    symmetricVGridGenerator.h
