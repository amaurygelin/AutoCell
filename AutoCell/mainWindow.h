#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

///
/// \file mainWindow.h
/// \brief Fenêtre principale.
/// \author Waël
///

#include "autocellelem.h"
#include "autocellGol.h"
#include "autocellquad.h"

/// \class MainWindow
/// \brief Classe gérant la fenêtre principale.
///
/// Permet le choix entre les différents types d'automates.
class MainWindow : public QWidget{
Q_OBJECT
    QPushButton* elemButton;///<Bouton pour choisir un automate élémentaire.
    QPushButton* golButton;///<Bouton pour choisir un automate jeu de la vie.
    QPushButton* quadButton;///<Bouton pour choisir un automate quadlife.
    QVBoxLayout* couche;///<Alligne verticallement.
    QLabel* choix;///<Texte indiquant le choix d'automate.
    AutoCellElem* fenetreAutomElem;///<Fenêtre d'un automate élémentaire.
    AutoCellGol* fenetreAutomGol;///<Fenêtre d'un automate jeu de la vie.
    AutoCellQuad* fenetreAutomQl;///<Fenêtre d'un automate quadlife.
    //QSettings* settingsFile;
public:
    /// \brief Constructeur de la fenêtre.
    explicit MainWindow(QWidget* parent = nullptr);
private slots:
    /// \brief Ouvre la fenêtre d'un automate élémentaire.
    void openAutoElem();
    /// \brief Ouvre la fenêtre d'un automate jeu de la vie.
    void openAutoGol();
    /// \brief Ouvre la fenêtre d'un automate quadlife.
    void openAutoQuad();
};

#endif // MAINWINDOW_H_INCLUDED
