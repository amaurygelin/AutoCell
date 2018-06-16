#ifndef AUTOMATON_H_INCLUDED
#define AUTOMATON_H_INCLUDED

///
/// \file Automaton.h
/// \brief Automate cellulaire.
/// \author Amaury
///

#include "Grid.h"
#include "saveManager.h"

/// \class Automaton
/// \brief Classe gérant un automate.
///
/// Modèle de base d'un automate.

class Automaton {
    private:
    protected:
        unsigned int dimension; ///<Les dimensions de l'automate, ici un ou deux.
        unsigned int nb_states; ///<Le nombre d'états possible de l'automate.
    public:
        /// \brief Constructeur.
        ///
        /// Construit l'automate.
        Automaton(unsigned int dim, unsigned int nb_s): dimension(dim), nb_states(nb_s) {}
        /// \brief Transition d'un état à un autre.
        ///
        /// Détermine à partir de règles l'état suivant d'un automate.
        /// \param src : grille contenant l'état actuel de l'automate.
        /// \param dest : grille qui contiendra l'état suivant de l'automate.
        virtual void transition(const Grid& src, Grid& dest) const = 0;
        /// \brief Affichage des informations de l'automate.
        ///
        /// Permet d'afficher les attributs de l'automate.
        /// \param f : flux ostream.
        virtual std::ostream& display(std::ostream& f = std::cout) const; //is abstract but has a definition
        /// \brief Récupération de la dimension.
        ///
        /// \return La dimension.
        unsigned int getDim() const{return dimension;}
        /// \brief Acceptation d'un visiteur.
        ///
        /// Permet à la classe SaveManager de visiter cette classe. Implémentation du patron de conception visiteur.
        /// \param db : la classe SaveManager qui permet la sauvegarde.
        virtual void accept(SaveManager &db)const =0;
};

/// \brief Redéfinition de l'opérateur <<.
///
/// Affiche les paramètres de l'automate.
/// \param f : flux ostream.
/// \param a : la classe Automate.
std::ostream& operator<<(std::ostream& f, Automaton const& a);

#endif // AUTOMATON_H_INCLUDED
