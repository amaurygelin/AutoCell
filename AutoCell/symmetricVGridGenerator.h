#ifndef SYMMETRICVGRIDGENERATOR_H_INCLUDED
#define SYMMETRICVGRIDGENERATOR_H_INCLUDED

///
/// \file symmetricVGridGenerator.h
/// \brief Initialisation symétrique verticale d'une grille.
/// \author Loïc
///

#include "GridGenerator.h"
/// \class SymmetricVGridGenerator
/// \brief Classe initialisant une grille symétrique verticalement.
///
/// Initialise une grille aléatoirement en respectant une symétrie verticalement.
///
class SymmetricVGridGenerator final : public GridGenerator
{
    public:
        /// \brief Génération d'une grille symétrique verticalement.
        ///
        /// Génère une grille aléatoirement en respectant une symétrie verticale.
        ///
        /// \param grid : une grille.
        void generateGrid(Grid &grid) override;
};

#endif // SYMMETRICVGRIDGENERATOR_H_INCLUDED
