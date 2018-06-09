#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

///
/// \file grid.h
/// \brief Grille contenant les différentes cellules de l'automate.
/// \author Waël
///

#include <iostream>
#include <vector>

class GridGenerator; // Forward declaration

/// \class Grid
/// \brief Classe gérant la grille.
///
/// La grille continent les différentes cellules de l'automate.
class Grid{
private:
    unsigned int nb_rows; ///<Nombre de lignes.
    unsigned int nb_columns; ///<Nombre de colonnes.
    unsigned int nb_possible_states; ///<Nombre d'états possibles.
    std::vector<std::vector<int>> value; ///<Matrice contenant les valeurs de toutes les cellules.
public:
    /// \brief Constructeur.
    ///
    /// Construit la grille à partir du nombre de lignes, de colonnes et d'états possibles.
    Grid(unsigned int nb_r, unsigned int nb_c, unsigned int nb_s):nb_rows(nb_r),nb_columns(nb_c),value(nb_rows,std::vector<int>(nb_columns)),nb_possible_states(nb_s){}
    /// \brief Constructeur.
    ///
    /// Construit une grille vide à partir du modèle d'une autre grille.
    Grid(const Grid& g):nb_rows(g.nb_rows),nb_columns(g.nb_columns),value(g.value),nb_possible_states(g.nb_possible_states){}
    /// \brief Recopie.
    ///
    /// Redéfinition de l'opérateur de recopie.
    Grid& operator=(const Grid & g);
    /// \brief Initilisation de la grille.
    ///
    /// Initialise la grille à partir d'un patron de conception stratégie grâce à la classe GridGenerator.
    /// \param generation_strategy : une classe GridGenerator.
    void executeGridGenerator(GridGenerator& generation_strategy);
    /// \brief Récupération du nombre de lignes.
    /// \return Le nombre de lignes.
    unsigned int getNbRow() const { return nb_rows; }
    /// \brief Récupération du nombre de colonnes.
    /// \return Le nombre de colonnes.
    unsigned int getNbCol() const { return nb_columns; }
    /// \brief Récupération du nombre d'états possibles.
    /// \return Le nombre d'états possibles.
    unsigned int getNbPossibleStates() const { return nb_possible_states; }
    /// \brief Change l'état d'une cellule.
    /// \param i : la ligne de la cellule.
    /// \param j : la colonne de la cellule.
    /// \param val : la valeur de l'état désiré.
    void setCell(unsigned int i,unsigned int j,int val);
    /// \brief Récupére l'état d'une cellule.
    /// \param i : la ligne de la cellule.
    /// \param j : la colonne de la cellule.
    /// \return L'état de la cellule.
    unsigned int getCell(unsigned int i,unsigned int j) const;
};

#endif // GRID_H_INCLUDED

/// \brief Redéfinition de l'opérateur <<.
///
/// Affiche la grille.
/// \param f : flux ostream.
/// \param g : la grille.
std::ostream & operator<<(std::ostream & f,const Grid & g);
