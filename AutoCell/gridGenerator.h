#ifndef GRIDGENERATOR_H_INCLUDED
#define GRIDGENERATOR_H_INCLUDED

///
/// \file gridGenerator.h
/// \brief Initialisation d'une grille.
/// \author Loïc
///

#include "grid.h"

/// \class GridGenerator
/// \brief Classe initialisant une grille.
///
/// Initialise une grille selon différentes méthodes.
/// Permet d'implanter le patron de conception stratégie et donc d'avoir plusieurs algorithmes d'initialisation répartis dans différentes classes.
///
class GridGenerator
{
    public:
        /// \brief Génération d'une grille.
        ///
        /// Génère une grille.
        ///
        /// \param grid : une grille.
        virtual void generateGrid(Grid &grid) =0;
};


#endif // GRIDGENERATOR_H_INCLUDED
