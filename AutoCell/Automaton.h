#ifndef AUTOMATON_H_INCLUDED
#define AUTOMATON_H_INCLUDED

#include <iostream>
#include "Grid.h"

class Automaton {
    private:
    protected:
        unsigned int dimension;
        unsigned int nb_states;
    public:
        Automaton(unsigned int dim, unsigned int nb_s): dimension(dim), nb_states(nb_s) {}
        virtual void transition(const Grid& src, Grid& dest) const = 0;
        virtual std::ostream& display(std::ostream& f = std::cout) const; //is abstract but has a definition
        unsigned int getDim() const{return dimension;}
};

std::ostream& operator<<(std::ostream& f, Automaton const& a);

#endif // AUTOMATON_H_INCLUDED
