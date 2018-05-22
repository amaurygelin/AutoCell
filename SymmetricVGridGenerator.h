#ifndef SYMMETRICVGRIDGENERATOR_H_INCLUDED
#define SYMMETRICVGRIDGENERATOR_H_INCLUDED

#include "GridGenerator.h"

class SymmetricVGridGenerator final : GridGenerator
{
    public:
        void generateGrid(Grid &grid) override;
};

#endif // SYMMETRICVGRIDGENERATOR_H_INCLUDED
