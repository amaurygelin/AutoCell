#ifndef SYMMETRICDGRIDGENERATOR_H_INCLUDED
#define SYMMETRICDGRIDGENERATOR_H_INCLUDED

#include "GridGenerator.h"

class SymmetricDGridGenerator final : public GridGenerator
{
    public:
        void generateGrid(Grid &grid) override;
};

#endif // SYMMETRICDGRIDGENERATOR_H_INCLUDED
