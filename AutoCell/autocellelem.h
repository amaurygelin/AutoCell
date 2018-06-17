#ifndef AUTOCELLELEM_H
#define AUTOCELLELEM_H

///
/// \file autocellelem.h
/// \brief Fenêtre d'un automate élémentaire.
/// \author Waël
///

#include "autocell.h"

/// \class AutoCellElem
/// \brief Classe gérant une fenêtre d'un automate élémentaire.
///
/// Permet de générer la fenêtre graphique d'un automate élémentaire.
class AutoCellElem final : public QWidget, public AutoCell{
friend class MainWindow;
Q_OBJECT
    QSpinBox* num; ///<Liste déroulante pour choisir la règle.
    QLineEdit* numeroBit[8]; ///<Editeur de texte d'une ligne qui permet ici d'afficher les 8 cases permettant de choisir la règle sous la forme d'une chaîne de bits.
    QLabel* numl;///<Texte indiquant le numéro de la règle
    QLabel* numeroBitl[8];///<Texte affichant la règle de voisinage pour chaque bit.
    QVBoxLayout* bitc[8];///<Alligne verticallemnt la règle de voisinage et le choix du bit.
    QIntValidator* zeroOneValidator;///<Vérifie que le choix du bit est bien un ou zéro.
    QSpinBox* dimension;///<Liste déroulante pour choisir le nombre de colonnes.
    QLabel* dimensionl;///<Texte affichant le nombre de colonnes.
    QLabel* nb_stepl;///<Texte affichant le nombre d'étapes.
    QTableWidget* grids;///<Table contenant toutes les grilles.

public:
    /// \brief Constructeur de la fenêtre.
    explicit AutoCellElem(QWidget* parent = nullptr);
private:
private slots:
    /// \brief Synchronise le nombre d'étapes entre dans toute la fenêtre.
    /// \param i : le nombre d'étapes.
    void synchronizeSimSteps(int i);
    /// \brief Synchronise la règle avec les bits.
    /// \param i : la règle.
    void synchronizeNumToNumBit(int i);
    /// \brief Synchronise les bits avec la règle.
    /// \param s : le chaîne de bits.
    void synchronizeNumBitToNum(const QString& s);

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
    /// Non disponible dans cet automate.
    void symmetricDGrid() override {}
    /// \brief Initialisation d'une grille le générateur SymmetricHGrid.
    /// /// Non disponible dans cet automate.
    void symmetricHGrid() override {}
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

#endif // AUTOCELLELEM_H
