#ifndef ABSTRACTGAMEOFLIFE_H_INCLUDED
#define ABSTRACTGAMEOFLIFE_H_INCLUDED

#include "Automaton.h"

class AbstractGameOfLife: public Automaton{
    protected:
        unsigned int nb_neighbours_to_born;
        unsigned int min_neighbours_to_stay_alive;
        unsigned int max_neighbours_to_stay_alive;

        virtual void born(Grid& g, int i, int j) const =0; //internal implementation method
    public:
        AbstractGameOfLife(unsigned int dim, unsigned int nb_s, unsigned int nb_n, unsigned int min_n, unsigned int max_n);
        void transition(const Grid& src, Grid& dest) const override; //template method
        std::ostream& display(std::ostream& f = std::cout) const override;
        void setMaxNeighbours(unsigned int max_n) { max_neighbours_to_stay_alive = max_n; }
        void setMinNeighbours(unsigned int min_n) { min_neighbours_to_stay_alive = min_n; }
        virtual void accept(SaveManager &db) const override=0;
        virtual unsigned int getNbNeighboursToBorn() const {return nb_neighbours_to_born;}
        virtual unsigned int getMinNeighboursToStayAlive() const {return min_neighbours_to_stay_alive;}
        virtual unsigned int getMaxNeighboursToStayAlive() const {return max_neighbours_to_stay_alive;}
};

unsigned int countNeighboursAlive(const Grid& g, int i, int j);

#endif // ABSTRACTGAMEOFLIFE_H_INCLUDED
