#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QSettings>
#include "autocellelem.h"
#include "autocellGol.h"
#include "autocellquad.h"

class MainWindow : public QWidget{
Q_OBJECT
    QPushButton* elemButton;
    QPushButton* golButton;
    QPushButton* quadButton;
    QVBoxLayout* couche;
    QLabel* choix;
    AutoCellElem* fenetreAutomElem;
    AutoCellGol* fenetreAutomGol;
    AutoCellQuad* fenetreAutomQl;
    //QSettings* settingsFile;
public:
        explicit MainWindow(QWidget* parent = nullptr);
        void initGui();
private slots:
    void openAutoElem();
    void openAutoGol();
    void openAutoQuad();
};

#endif // MAINWINDOW_H_INCLUDED
