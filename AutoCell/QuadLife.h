#ifndef QUADLIFE_H_INCLUDED
#define QUADLIFE_H_INCLUDED

#include "AbstractGameOfLife.h"

class QuadLife final: public AbstractGameOfLife{
    private:
        void born(Grid& g, int i, int j) const;
    public:
        QuadLife(unsigned int nb_n, unsigned int min_n, unsigned int max_n) : AbstractGameOfLife(2, 5, nb_n, min_n, max_n) {}
        void accept(SaveManager &db) const override
        {
            db.saveAutomaton(*this);
        }

};

#endif // QUADLIFE_H_INCLUDED
