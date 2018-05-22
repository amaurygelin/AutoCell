#ifndef RANDOMGRIDGENERATOR_H_INCLUDED
#define RANDOMGRIDGENERATOR_H_INCLUDED

#include "GridGenerator.h"

class RandomGridGenerator final : GridGenerator
{
    public:
        void generateGrid(Grid &grid) override;
};

#endif // RANDOMGRIDGENERATOR_H_INCLUDED
