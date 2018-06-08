#ifndef RANDOMGRIDGENERATOR_H_INCLUDED
#define RANDOMGRIDGENERATOR_H_INCLUDED

///
/// \file randomGridGenerator.h
/// \brief Initialisation aléatoire d'une grille.
/// \author Loïc
///
#include "GridGenerator.h"

/// \class RandomGridGenerator
/// \brief Classe initialisant une grille aléatoirement.
///
/// Initialise une grille aléatoirement.
///
class RandomGridGenerator final : public GridGenerator
{
    public:
        /// \brief Génération d'une grille aléatoirement.
        ///
        /// Génère une grille aléatoirement.
        ///
        /// \param grid : une grille.
        void generateGrid(Grid &grid) override;
};

#endif // RANDOMGRIDGENERATOR_H_INCLUDED
