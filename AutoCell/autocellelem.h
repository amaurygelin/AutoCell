#ifndef AUTOCELL_H
#define AUTOCELL_H

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QComboBox>
#include <QString>
#include "grid.h"

class AutoCellElem : public QWidget{
Q_OBJECT
    QSpinBox* num; // numéro
    QSpinBox* nb_step;
    QLineEdit* numeroBit[8]; // un QLineEdit par bit
    QLabel* numl;
    QLabel* numeroBitl[8];
    QVBoxLayout* numc;
    QVBoxLayout* bitc[8];
    QHBoxLayout* numeroc;
    QHBoxLayout* simLayout;
    QIntValidator* zeroOneValidator;
    QTableWidget* depart;
    QSpinBox* dimension;
    QVBoxLayout* couche;
    QLabel* namel;
    QLabel* dimensionl;
    QLabel* nb_stepl;
    QTableWidget* grids;
    QPushButton* grid;
    QPushButton* simulation;
    QPushButton* simulationStep;
    QComboBox* choice;

public:
    explicit AutoCellElem(QWidget* parent = nullptr);
private:
    unsigned int cur_step;
    bool playSimulation;
    bool stepSimulation;
private slots:
    void synchronizeNumToNumBit(int i);
    void synchronizeNumBitToNum(const QString& s);
    void cellActivation(const QModelIndex& index);
    void launchSimulation();
    void launchSimulationStep();
    void choiceChanged(const QString& s);
    void newGrid();
    void symmetricVGrid();
    void randomGrid();
};

#endif // AUTOCELL_H
