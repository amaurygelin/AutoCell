#ifndef ABSTRACTGAMEOFLIFE_H_INCLUDED
#define ABSTRACTGAMEOFLIFE_H_INCLUDED

///
/// \file AbstractGameOfLife.h
/// \brief Automate similaire au jeu de la vie.
/// \author Amaury
///

#include "Automaton.h"

/// \class AbstractGameOfLife
/// \brief Classe gérant un automate similaire au jeu de la vie.
///
/// Modèle pour les automates qui sont le jeu de la vie ou ses variantes.

class AbstractGameOfLife: public Automaton{
    protected:
        unsigned int nb_neighbours_to_born; ///<Le nombre de voisins vivants nécéssaire pour qu'une celulle naisse.
        unsigned int min_neighbours_to_stay_alive; ///<Le nombre minimum de voisins vivants pour qu'une celulle survive.
        unsigned int max_neighbours_to_stay_alive; ///<Le nombre maximum de voisins vivants pour qu'une celulle survive.

        /// \brief Règles de transitions.
        ///
        /// Détermine les évolutions des cellules à partir de règles.
        /// \param src : grille contenant l'état actuel de l'automate.
        /// \param dest : grille qui contiendra l'état suivant de l'automate.
        /// \param i : ligne de la cellule.
        /// \param j : colonne de la cellule.
        virtual void lifeManager(const Grid& src, Grid& dest, int i, int j) const =0; //internal implementation method
    public:
        /// \brief Constructeur.
        ///
        /// Construit l'automate.
        AbstractGameOfLife(unsigned int dim, unsigned int nb_s, unsigned int nb_n, unsigned int min_n, unsigned int max_n);
        /// \brief Transition d'un état à un autre.
        ///
        /// Prépare la transition d'un état à un autre.
        /// \param src : grille contenant l'état actuel de l'automate.
        /// \param dest : grille qui contiendra l'état suivant de l'automate.
        void transition(const Grid& src, Grid& dest) const override; //template method
        /// \brief Affichage des informations de l'automate.
        ///
        /// Permet d'afficher les attributs de l'automate.
        /// \param f : flux ostream.
        std::ostream& display(std::ostream& f = std::cout) const override;
        /// \brief Paramètrage du nombre maximum de voisins pour rester en vie.
        /// \param max_n : le nombre en question.
        void setMaxNeighbours(unsigned int max_n) { max_neighbours_to_stay_alive = max_n; }
        /// \brief Paramètrage du nombre minimum de voisins pour rester en vie.
        /// \param min_n : le nombre en question.
        void setMinNeighbours(unsigned int min_n) { min_neighbours_to_stay_alive = min_n; }
        /// \brief Récupération du nombre de voisins vivants nécéssaires pour naître.
        /// \return Le nombre en question.
        virtual unsigned int getNbNeighboursToBorn() const {return nb_neighbours_to_born;}
        /// \brief Récupération du nombre de voisins vivants minimum pour rester en vie.
        /// \return Le nombre en question.
        virtual unsigned int getMinNeighboursToStayAlive() const {return min_neighbours_to_stay_alive;}
        /// \brief Récupération du nombre de voisins vivants maximum pour rester en vie.
        /// \return Le nombre en question.
        virtual unsigned int getMaxNeighboursToStayAlive() const {return max_neighbours_to_stay_alive;}
        /// \brief Acceptation d'un visiteur.
        ///
        /// Permet à la classe SaveManager de visiter cette classe. Implémentation du patron de conception visiteur.
        /// \param db : la classe SaveManager qui permet la sauvegarde.
        virtual void accept(SaveManager &db) const override=0;
};
/// \brief Calcul de nombre de voisins.
///
/// Permet de calculer le nombre de voisins dans un état en particulier d'une cellule d'une grille.
/// \param g : la grille contenant l'état de l'automate.
/// \param i : la ligne de la cellule.
/// \param j : la colonne de la cellule.
/// \param state : état recherché.
/// \return Le nombre de voisins
unsigned int countNeighboursAlive(const Grid& g, int i, int j, int state);

#endif // ABSTRACTGAMEOFLIFE_H_INCLUDED
