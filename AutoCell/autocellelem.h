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
#include <QTimer>


class AutoCellElem : public QWidget{
friend class MainWindow;
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
    QPushButton* saveAutomaton;
    QLabel* loadAutomatonl;
    QComboBox* loadAutomaton;
    QComboBox* choice;

public:
    explicit AutoCellElem(QWidget* parent = nullptr);
private:
    bool playSimulation;
    bool stepSimulation;
private slots:
    void synchronizeSimSteps(int i);
    void synchronizeNumToNumBit(int i);
    void synchronizeNumBitToNum(const QString& s);
    void cellActivation(const QModelIndex& index);
    void launchSimulation();
    void launchSimulationStep();
    void choiceChanged(const QString& s);
    void choiceAutomChanged();
    void newGrid();
    void symmetricVGrid();
    void randomGrid();
    void saveSettings();
    void loadSettings();
    void saveAutom();
    void loadAutomList();
};

#endif // AUTOCELL_H
