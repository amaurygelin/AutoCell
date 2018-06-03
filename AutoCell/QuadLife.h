#ifndef QUADLIFE_H_INCLUDED
#define QUADLIFE_H_INCLUDED

#include "AbstractGameOfLife.h"

class QuadLife final: public AbstractGameOfLife{
    private:
        //bool cellAlive(int i, int j) const override;
    public:
        QuadLife(unsigned int nb_n, unsigned int min_n, unsigned int max_n) : AbstractGameOfLife(2, 5, nb_n, min_n, max_n) {}
        void transition(const Grid& src, Grid& dest) const override;
};

#endif // QUADLIFE_H_INCLUDED
