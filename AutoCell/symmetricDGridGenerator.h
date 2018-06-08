#ifndef SYMMETRICDGRIDGENERATOR_H_INCLUDED
#define SYMMETRICDGRIDGENERATOR_H_INCLUDED

///
/// \file symmetricDGridGenerator.h
/// \brief Initialisation symétrique en diagonale d'une grille.
/// \author Loïc
///

#include "GridGenerator.h"

/// \class SymmetricDGridGenerator
/// \brief Classe initialisant une grille symétrique diagonalement.
///
/// Initialise une grille aléatoirement en respectant une symétrie diagonale.
///
class SymmetricDGridGenerator final : public GridGenerator
{
    public:
        /// \brief Génération d'une grille symétrique diagonalement.
        ///
        /// Génère une grille aléatoirement en respectant une symétrie diagonale.
        /// La méthode retournera une exception si la grille n'est pas carrée
        ///
        /// \param grid : une grille.
        void generateGrid(Grid &grid) override;
};

#endif // SYMMETRICDGRIDGENERATOR_H_INCLUDED
