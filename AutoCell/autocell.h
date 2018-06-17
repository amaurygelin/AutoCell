#ifndef AUTOCELL_H
#define AUTOCELL_H

///
/// \file autocell.h
/// \brief Fenêtre abstraite d'un automate.
/// \author Loïc
///

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
#include <QRect>
#include <QTimer>
#include <QVector>

/// \class AutoCell
/// \brief Classe gérant une fenêtre abstraite d'un automate.
///
/// Modèle pour toutes les fenêtres d'automate.

class AutoCell{
protected:
    QSpinBox* nb_step; ///<Fenêtre de saisie du nombre d'étapes.
    QPushButton* grid; ///<Bouton pour générer une grille.
    QPushButton* simulation; ///<Bouton pour simuler toutes les générations.
    QPushButton* simulationStep; ///<Bouton pour simuler les générations une par une.
    QLabel* loadAutomatonl; ///<Texte qui indique qu'on peut choisir un automate à charger.
    QComboBox* loadAutomaton; ///<Liste déroulante des automates sauvegardés.
    QPushButton* saveAutomaton; ///<Boutton pour sauvegarder l'automate.
    QVBoxLayout* numc; ///<Alligne verticalement.
    QHBoxLayout* numeroc; ///<Alligne horizontalement.
    QLabel* namel; ///<Texte indiquant le type d'automate.
    QVBoxLayout* couche; ///<Alligne verticalement.
    QHBoxLayout* simLayout; ///<Alligne horizontalement.
    QTableWidget* depart; ///<Tableau représentant la grille d'un automate.
    QComboBox* choiceGrid; ///<Liste déroulante pour générer la grille.

    bool playSimulation; ///<Active la simulation d'un coup.
    bool stepSimulation; ///<Active la simulation par étape.

protected slots:

    /// \brief Crée une nouvelle grille.
    virtual void newGrid()=0;
    /// \brief Modifie les attributs en fonction de l'automate choisi.
    virtual void choiceAutomChanged()=0;
    /// \brief Modifie la couleur et la valeur d'une cellule dans la grille graphique.
    /// \param index : la case du tableau qui doît être modifiée.
    virtual void cellActivation(const QModelIndex& index)=0;
    /// \brief Lance la simulation complète.
    virtual void launchSimulation()=0;
    /// \brief Lance la simulation par étapes.
    virtual void launchSimulationStep()=0;
    /// \brief Initialisation d'une grille le générateur SymmetricDGrid.
    virtual void symmetricDGrid() =0;
    /// \brief Initialisation d'une grille le générateur SymmetricHGrid.
    virtual void symmetricHGrid() =0;
    /// \brief Initialisation d'une grille le générateur SymmetricVGrid.
    virtual void symmetricVGrid() =0;
    /// \brief Initialisation d'une grille le générateur RandomGrid.
    virtual void randomGrid() =0;
    /// \brief Sauvegarde le contexte.
    virtual void saveSettings()=0;
    /// \brief Charge le contexte.
    virtual void loadSettings()=0;
    /// \brief Sauvegarde l'automate.
    virtual void saveAutom()=0;
    /// \brief Charge l'automate.
    virtual void loadAutomList()=0;
    /// \brief Gestion de l'initiation d'une grille après choix d'un générateur.
    /// \param s : le texte associé dans le menu déroulant.
    virtual void choiceGridChanged(const QString &s)=0;
};

#endif // AUTOCELL_H
