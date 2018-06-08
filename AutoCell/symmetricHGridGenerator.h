#ifndef SYMMETRICHGRIDGENERATOR_H_INCLUDED
#define SYMMETRICHGRIDGENERATOR_H_INCLUDED

///
/// \file symmetricHGridGenerator.h
/// \brief Initialisation symétrique horizontale d'une grille.
/// \author Loïc
///

#include "GridGenerator.h"
/// \class SymmetricHGridGenerator
/// \brief Classe initialisant une grille symétrique horizontalement.
///
/// Initialise une grille aléatoirement en respectant une symétrie horizontale.
///
class SymmetricHGridGenerator final : public GridGenerator
{
    public:
        /// \brief Génération d'une grille symétrique horizontalement.
        ///
        /// Génère une grille aléatoirement en respectant une symétrie horizontale.
        ///
        /// \param grid : une grille.
        void generateGrid(Grid &grid) override;
};

#endif // SYMMETRICHGRIDGENERATOR_H_INCLUDED
