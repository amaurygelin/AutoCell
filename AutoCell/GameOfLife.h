#ifndef GAMEOFLIFE_H_INCLUDED
#define GAMEOFLIFE_H_INCLUDED

///
/// \file GameOfLife.h
/// \brief Automate jeu de la vie.
/// \author Amaury
///

#include "AbstractGameOfLife.h"

/// \class GameOfLife
/// \brief Classe gérant un automate jeu de la vie.
///
/// Modèle pour les automates jeu de la vie.
class GameOfLife final: public AbstractGameOfLife{
    private:

        /// \brief Règles de transitions.
        ///
        /// Détermine les évolutions des cellules à partir des règles du jeu de la vie.
        /// \param src : grille contenant l'état actuel de l'automate.
        /// \param dest : grille qui contiendra l'état suivant de l'automate.
        /// \param i : ligne de la cellule.
        /// \param j : colonne de la cellule.
        void lifeManager(const Grid& src, Grid& dest, int i, int j) const;
    public:
        /// \brief Constructeur.
        ///
        /// Construit l'automate jeu de la vie.
        GameOfLife(unsigned int nb_n, unsigned int min_n, unsigned int max_n) : AbstractGameOfLife(2, 2, nb_n, min_n, max_n) {}
        /// \brief Acceptation d'un visiteur.
        ///
        /// Permet à la classe SaveManager de visiter cette classe. Implémentation du patron de conception visiteur.
        /// \param db : la classe SaveManager qui permet la sauvegarde.
        void accept(SaveManager &db) const override
        {
            db.saveAutomaton(*this);
        }
};

#endif // GAMEOFLIFE_H_INCLUDED
