#ifndef QUADLIFE_H_INCLUDED
#define QUADLIFE_H_INCLUDED

///
/// \file QuadLife.h
/// \brief Automate quadlife.
/// \author Loïc
///
#include "AbstractGameOfLife.h"

/// \class QuadLife
/// \brief Classe gérant un automate quadlife.
///
/// Modèle pour les automates QuadLife.
class QuadLife final: public AbstractGameOfLife{
    private:
        /// \brief Règles de transitions.
        ///
        /// Détermine les évolutions des cellules à partir des règles de QuadLife.
        /// \param src : grille contenant l'état actuel de l'automate.
        /// \param dest : grille qui contiendra l'état suivant de l'automate.
        /// \param i : ligne de la cellule.
        /// \param j : colonne de la cellule.
        void lifeManager(const Grid& src, Grid& dest, int i, int j) const;
    public:
        /// \brief Constructeur.
        ///
        /// Construit l'automate quadife.
        QuadLife(unsigned int nb_n, unsigned int min_n, unsigned int max_n) : AbstractGameOfLife(2, 5, nb_n, min_n, max_n) {}
        /// \brief Acceptation d'un visiteur.
        ///
        /// Permet à la classe SaveManager de visiter cette classe. Implémentation du patron de conception visiteur.
        /// \param db : la classe SaveManager qui permet la sauvegarde.
        void accept(SaveManager &db) const override
        {
            db.saveAutomaton(*this);
        }

};

#endif // QUADLIFE_H_INCLUDED
