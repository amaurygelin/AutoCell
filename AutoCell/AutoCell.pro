QT += widgets
QT += sql

QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

SOURCES += \
    AbstractGameOfLife.cpp \
    Automaton.cpp \
    dbManager.cpp \
    ElementaryAutomaton.cpp \
    GameOfLife.cpp \
    grid.cpp \
    main.cpp \
    QuadLife.cpp \
    randomGridGenerator.cpp \
    saveManager.cpp \
    simulator.cpp \
    symmetricDGridGenerator.cpp \
    symmetricHGridGenerator.cpp \
    symmetricVGridGenerator.cpp


HEADERS += \
    AbstractGameOfLife.h \
    Automaton.h \
    dbManager.h \
    ElementaryAutomaton.h \
    GameOfLife.h \
    grid.h \
    gridGenerator.h \
    QuadLife.h \
    randomGridGenerator.h \
    saveManager.h \
    simulator.h \
    symmetricDGridGenerator.h \
    symmetricHGridGenerator.h \
    symmetricVGridGenerator.h


DISTFILES +=
