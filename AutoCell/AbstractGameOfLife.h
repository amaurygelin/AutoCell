#ifndef ABSTRACTGAMEOFLIFE_H_INCLUDED
#define ABSTRACTGAMEOFLIFE_H_INCLUDED

#include "Automaton.h"

class AbstractGameOfLife: public Automaton{
    protected:
        unsigned int nb_neighbours_to_born;
        unsigned int min_neighbours_to_stay_alive;
        unsigned int max_neighbours_to_stay_alive;

        //virtual bool cellAlive(unsigned int i, unsigned int j) const = 0;
        //unsigned int countNeighboursAlive(unsigned int i, unsigned int j) const;
    public:
        AbstractGameOfLife(unsigned int dim, unsigned int nb_s, unsigned int nb_n, unsigned int min_n, unsigned int max_n);
        //void transition(const Grid& src, Grid& dest) const = 0; //still abstract but with a definition
        std::ostream& display(std::ostream& f = std::cout) const override;
        void setMaxNeighbours(unsigned int max_n) { max_neighbours_to_stay_alive = max_n; }
        void setMinNeighbours(unsigned int min_n) { min_neighbours_to_stay_alive = min_n; }
};

#endif // ABSTRACTGAMEOFLIFE_H_INCLUDED
