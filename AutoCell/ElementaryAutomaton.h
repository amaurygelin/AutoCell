#ifndef ELEMENTARYAUTOMATON_H_INCLUDED
#define ELEMENTARYAUTOMATON_H_INCLUDED

///
/// \file ElementaryAutomaton.h
/// \brief Automate élémentaire.
/// \author Amaury
///
#include <string>
#include "Automaton.h"

//Extern services
/// \brief Convertion bits en nombre.
///
/// Transforme une chaîne de caractère représentant des bits en un nombre entier.
/// \param bits : la chaîne de cractères représentant des bits.
/// \return Le nombre entier.
short unsigned int bits2num(const std::string& bits);
/// \brief Convertion nombre en bits.
///
/// Transforme un nombre entier en une chaîne de caractère représentant des bits.
/// \param num : le nombre entier.
/// \return La chaîne de cractères représentant des bits.
std::string num2bits(short unsigned int num);
//End extern services

/// \class ElementaryAutomaton
/// \brief Classe gérant un automate élémentaire.
///
/// Modèle pour les automates élémentaire.
class ElementaryAutomaton final: public Automaton{
    private:
        short unsigned int rule_num; ///<La règle sous la forme d'un nombre entier
        std::string rule_bits; ///<La règle sous la forme d'une chaîne de caractères (bits).
    public:
        /// \brief Constructeur nombre.
        ///
        /// Construit l'automate à partir de la règle sous la forme d'un nombre.
        ElementaryAutomaton(short unsigned int r_num): Automaton(1,2), rule_num(r_num), rule_bits(num2bits(r_num)) {}
        /// \brief Constructeur bits.
        ///
        /// Construit l'automate à partir de la règle sous la forme d'une chaîne de caractères (bits).
        ElementaryAutomaton(std::string r_bits): Automaton(1,2), rule_num(bits2num(r_bits)), rule_bits(r_bits) {}
        /// \brief Récupération de la règle sous forme d'un nombre.
        ///
        /// \return La règle sous forme d'un nombre
        short unsigned int getRuleNum() const {return rule_num;}
        /// \brief Récupération de la règle sous la forme d'une chaîne de caractères (bits).
        ///
        /// \return La règle sous forme d'une chaîne de caractères (bits)
        std::string getRuleBits() const {return rule_bits;}
        /// \brief Transition d'un état à un autre.
        ///
        /// Détermine à partir de règles l'état suivant d'un automate.
        /// \param src : grille contenant l'état actuel de l'automate.
        /// \param dest : grille qui contiendra l'état suivant de l'automate.
        void transition(const Grid& src, Grid& dest) const override;
        /// \brief Affichage des informations de l'automate.
        ///
        /// Permet d'afficher les attributs de l'automate.
        /// \param f : flux ostream.
        std::ostream& display(std::ostream& f = std::cout) const override;
        /// \brief Acceptation d'un visiteur.
        ///
        /// Permet à la classe SaveManager de visiter cette classe. Implémentation du patron de conception visiteur.
        /// \param db : la classe SaveManager qui permet la sauvegarde.
        void accept(SaveManager &db) const override
        {
            db.saveAutomaton(*this);
        }
};

#endif // ELEMENTARYAUTOMATON_H_INCLUDED
