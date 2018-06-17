#ifndef AUTOCELLABSTRACTGOL_H
#define AUTOCELLABSTRACTGOL_H

///
/// \file autocellabstractgol.h
/// \brief Fenêtre abstraite d'un automate type jeu de la vie.
/// \author Loïc
///

#include "autocell.h"

/// \class AutoCellAbstractGol
/// \brief Classe gérant une fenêtre abstraite d'un automate type jeu de la vie.
///
/// Modèle pour toutes les fenêtres d'automate type jeu de la vie.
class AutoCellAbstractGol : public AutoCell{
protected:

    QSpinBox* nb_n; ///<Fenêtre de saisie du nombre de voisins pour naître.
    QSpinBox* min_n; ///<Fenêtre de saisie du nombre de voisins minimum pour survivre.
    QSpinBox* max_n; ///<Fenêtre de saisie du nombre de voisins maximum pour survivre.
    QSpinBox* dim1; ///<Fenêtre de saisie du nombre de lignes.
    QSpinBox* dim2; ///<Fenêtre de saisie du nombre de colonnes.
    QLabel* nb_nl; ///<Texte indiquant le nombres de voisins pour naître.
    QLabel* min_nl; ///<Texte indiquant le nombres de voisins minimum pour survivre.
    QLabel* max_nl; ///<Texte indiquant le nombres de voisins maximum pour survivre.
    QLabel* dim1l; ///<Texte indiquant le nombres de lignes.
    QLabel* dim2l; ///<Texte indiquant le nombres de colonnes.
    QLabel* nb_stepl; ///<Texte indiquant le nombre d'étapes.
    QPushButton* pauseButton; ///<Bouton qui met en pause la simulation.
    QTimer* timer; ///<Minuteur pour gérer le temps entre les étapes.
    QSpinBox* speed; ///<Liste déroulante pour choisir le temps entre les étapes.
    QLabel* speedl; ///<Texte indiquant le temps entre les étapes.

    std::vector<std::vector<int>> rules; ///<Continent les attributs qui nous intéressent.
    int rankRules; ///<Le nombre d'attributs.

protected slots:
    /// \brief Met en pause le jeu.
    virtual void pause()=0;

    /// \brief Crée une nouvelle grille.
    virtual void newGrid() override=0;
    /// \brief Modifie les attributs en fonction de l'automate choisi.
    virtual void choiceAutomChanged() override=0;
    /// \brief Modifie la couleur et la valeur d'une cellule dans la grille graphique.
    /// \param index : la case du tableau qui doît être modifiée.
    virtual void cellActivation(const QModelIndex& index) override=0;
    /// \brief Lance la simulation complète.
    virtual void launchSimulation() override=0;
    /// \brief Lance la simulation par étapes.
    virtual void launchSimulationStep() override=0;
    /// \brief Initialisation d'une grille le générateur SymmetricDGrid.
    virtual void symmetricDGrid() override=0;
    /// \brief Initialisation d'une grille le générateur SymmetricHGrid.
    virtual void symmetricHGrid() override=0;
    /// \brief Initialisation d'une grille le générateur SymmetricVGrid.
    virtual void symmetricVGrid() override=0;
    /// \brief Initialisation d'une grille le générateur RandomGrid.
    virtual void randomGrid() override=0;
    /// \brief Sauvegarde le contexte.
    virtual void saveSettings() override=0;
    /// \brief Charge le contexte.
    virtual void loadSettings() override=0;
    /// \brief Sauvegarde l'automate.
    virtual void saveAutom() override=0;
    /// \brief Charge l'automate.
    virtual void loadAutomList() override=0;
    /// \brief Gestion de l'initiation d'une grille après choix d'un générateur.
    /// \param s : le texte associé dans le menu déroulant.
    virtual void choiceGridChanged(const QString &s) override=0;
};

#endif // AUTOCELLABSTRACTGOL_H
