#ifndef SYMMETRICHGRIDGENERATOR_H_INCLUDED
#define SYMMETRICHGRIDGENERATOR_H_INCLUDED

#include "GridGenerator.h"

class SymmetricHGridGenerator final : public GridGenerator
{
    public:
        void generateGrid(Grid &grid) override;
};

#endif // SYMMETRICHGRIDGENERATOR_H_INCLUDED
