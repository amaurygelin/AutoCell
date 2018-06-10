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
    QComboBox* choice;

public:
    explicit AutoCellElem(QWidget* parent = nullptr);
private slots:
    void synchronizeNumToNumBit(int i);
    void synchronizeNumBitToNum(const QString& s);
    void cellActivation(const QModelIndex& index);
    void launchSimulation();
    void choiceChanged(const QString& s);
    void newGrid();
    void symmetricVGrid();
    void randomGrid();
};

#endif // AUTOCELL_H
