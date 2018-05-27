#ifndef AUTOMATON_H_INCLUDED
#define AUTOMATON_H_INCLUDED

#include <vector>

class Automaton {
    private:
    protected:
        int dimension;
        int nb_states;
        std::vector<int> states_list;
    public:
        Automaton(int dim, int nb_s): dimension(dim), nb_states(nb_s), states_list(nb_s) {}
        //virtual void transition(const Grid& src, Grid& dest) const = 0;
        virtual std::ostream& display(std::ostream& f = std::cout) const; //is abstract but has a definition
};

std::ostream& operator<<(std::ostream& f, Automaton const& a);

#endif // AUTOMATON_H_INCLUDED
