#ifndef SIMULATOR_H_INCLUDED
#define SIMULATOR_H_INCLUDED

///
/// \file simulator.h
/// \brief Simulateur.
/// \author Waël
///
#include "Automaton.h"

/// \class Simulator
/// \brief Simulateur.
///
/// Simulateur qui permet de gérer les grilles et les états successifs d'un automate.
class Simulator{
private:
    static Simulator* uniqueSim;///<Simulateur uniquer implanté dans le cadre d'un patron de conception singleton.
    const Automaton& automaton;///<Automate utilisé par le simulateur.
    const Grid* initial_grid;///<Grille initiale utilisé par le simulateur.
    unsigned int max_grids;///<Nombre maxmimum de grilles dans la mémoire tampon.
    std::vector<Grid*> grids;///<Mémoire tampon contenant les grilles sucessives des états.
    unsigned int cur_rank;///<Permet de connaître le nombre d'étapes déjà écoulées.
    /// \brief Destructeur.
    ///
    /// Détruit tout ce qui a été construit par le simulateur.
    virtual ~Simulator();
    /// \brief Allocation interdite.
    void operator=(const Simulator&)=delete;
    /// \brief Recopie interdite.
    Simulator(const Simulator& s)=delete;
    /// \brief Constructeur.
    ///
    /// Construit le simulateur sans grille initiale. Appellé dans le cadre du patron de conception singleton.
    Simulator(const Automaton& autom, unsigned int max_g=2);
    /// \brief Constructeur.
    ///
    /// Construit le simulateur avec une grille initiale. Appellé dans le cadre du patron de conception singleton.
    Simulator(const Automaton& autom, const Grid& initial_g,unsigned int max_g=2);
public:
    /// \brief Ajoute une grille initiale.
    ///
    /// \param grid : la grille initiale.
    void setInitialGrid(const Grid& grid);
    /// \brief Génère une nouvelle grille.
    /// \param c : l'emplacement dans la mémoire tampon.
    void build(unsigned int c);
    /// \brief Génère l'état suivant de l'automate.
    void next();
    /// \brief Génère un nombre défini d'états suivants de l'automate.
    /// \param nbSteps : le nombre d'états à générer.
    void run(unsigned int nbSteps);
    /// \brief Revient à la grille initiale.
    void reset();
    /// \brief Récupère la dernière grille.
    /// \return La dernière grille
    const Grid& last() const;
    /// \brief Récupération du rang actuel.
    /// \return Le range actuel.
    unsigned int getCurRank() const{return cur_rank;}
    /// \brief Récupération de la taille de la mémoire tampon.
    /// \return La taille du mémoire tampon.
    unsigned int getMaxGrids() const{return max_grids;}
    /// \brief Affiche les grilles dans la mémoire tampon.
    void displayGrids();
    /// \brief Libère le simulateur.
    ///
    /// Supprime le simulateur dans le cadre d'un patron de conception singleton.
    static void freeInstance();
    /// \brief Genère un simulateur.
    ///
    /// Genère le simulateur avec une grille initiale dans le cadre du patron de conception singleton.
    ///
    /// \return Un simulateur.
    static Simulator& getSimulator(const Automaton& autom, const Grid& initial_g, unsigned int max_g);
    /// \brief Genère un simulateur.
    ///
    /// Genère le simulateur sans une grille initiale dans le cadre du patron de conception singleton.
    ///
    /// \return Un simulateur.
    static Simulator& getSimulator(const Automaton& autom, unsigned int max_g);
    /// \brief Sauvegarde l'automaton.
    ///
    /// Implanté dans le cadre d'un patron de conception visiteur.
    ///
    /// \param s : une classe SaveManager
    void save(SaveManager &s)
    {
        automaton.accept(s);
    }
};

#endif // SIMULATOR_H_INCLUDED
