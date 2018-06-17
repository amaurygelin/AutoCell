#ifndef AUTOCELLGOL_H
#define AUTOCELLGOL_H

///
/// \file autocellGol.h
/// \brief Fenêtre d'un automate jeu de la vie.
/// \author Waël
///

#include "autocellabstractgol.h"

/// \class AutoCellGol
/// \brief Classe gérant une fenêtre d'un automate jeu de la vie.
///
/// Permet de générer la fenêtre graphique d'un automate jeu de la vie.
class AutoCellGol final : public QWidget, public AutoCellAbstractGol{
Q_OBJECT
public:
    /// \brief Constructeur de la fenêtre.
    explicit AutoCellGol(QWidget* parent = nullptr);
private slots:
    /// \brief Met en pause le jeu.
    void pause() override;

    /// \brief Crée une nouvelle grille.
    void newGrid() override;
    /// \brief Modifie les attributs en fonction de l'automate choisi.
    void choiceAutomChanged() override;
    /// \brief Modifie la couleur et la valeur d'une cellule dans la grille graphique.
    /// \param index : la case du tableau qui doît être modifiée.
    void cellActivation(const QModelIndex& index) override;
    /// \brief Lance la simulation complète.
    void launchSimulation() override;
    /// \brief Lance la simulation par étapes.
    void launchSimulationStep() override;
    /// \brief Initialisation d'une grille le générateur SymmetricDGrid.
    void symmetricDGrid() override;
    /// \brief Initialisation d'une grille le générateur SymmetricHGrid.
    void symmetricHGrid() override;
    /// \brief Initialisation d'une grille le générateur SymmetricVGrid.
    void symmetricVGrid() override;
    /// \brief Initialisation d'une grille le générateur RandomGrid.
    void randomGrid() override;
    /// \brief Sauvegarde le contexte.
    void saveSettings() override;
    /// \brief Charge le contexte.
    void loadSettings() override;
    /// \brief Sauvegarde l'automate.
    void saveAutom() override;
    /// \brief Charge l'automate.
    void loadAutomList() override;
    /// \brief Gestion de l'initiation d'une grille après choix d'un générateur.
    /// \param s : le texte associé dans le menu déroulant.
    void choiceGridChanged(const QString &s) override;
};

#endif // AUTOCELLGOL_H
