#ifndef GRIDGENERATOR_H_INCLUDED
#define GRIDGENERATOR_H_INCLUDED

#include "grid.h"

class GridGenerator
{
    public:
        virtual void generateGrid(Grid &grid) =0;
};


#endif // GRIDGENERATOR_H_INCLUDED
