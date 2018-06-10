#ifndef AUTOCELLQUAD_H
#define AUTOCELLQUAD_H

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
#include <QRect>
#include <QComboBox>
#include <QString>

class AutoCellQuad : public QWidget{
Q_OBJECT
    QSpinBox* nb_n;
    QSpinBox* min_n;
    QSpinBox* max_n;
    QSpinBox* dim1;
    QSpinBox* dim2;
    QSpinBox* nb_step;
    QLabel* namel;
    QLabel* nb_nl;
    QLabel* min_nl;
    QLabel* max_nl;
    QLabel* dim1l;
    QLabel* dim2l;
    QLabel* nb_stepl;
    QVBoxLayout* numc;
    QHBoxLayout* numeroc;
    QTableWidget* depart;
    QPushButton* grid;
    QComboBox* choiceGrid;
    QVBoxLayout* couche;
    QPushButton* simulation;


public:
    explicit AutoCellQuad(QWidget* parent = nullptr);
private slots:
    void cellActivation(const QModelIndex& index);
    void launchSimulation();
    void choiceGridChanged(const QString &s);
    void newGrid();
    void symmetricDGrid();
    void symmetricHGrid();
    void symmetricVGrid();
    void randomGrid();
};


#endif // AUTOCELLQUAD_H
