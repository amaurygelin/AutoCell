#ifndef GAMEOFLIFE_H_INCLUDED
#define GAMEOFLIFE_H_INCLUDED

#include "AbstractGameOfLife.h"

class GameOfLife final: public AbstractGameOfLife{
    private:
        void born(Grid& g, int i, int j) const;
    public:
        GameOfLife(unsigned int nb_n, unsigned int min_n, unsigned int max_n) : AbstractGameOfLife(2, 2, nb_n, min_n, max_n) {}
};

#endif // GAMEOFLIFE_H_INCLUDED
