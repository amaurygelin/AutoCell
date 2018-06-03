#include "randomGridGenerator.h"
#include "stdlib.h"
#include <time.h>

void RandomGridGenerator::generateGrid(Grid &grid)
{
    srand(time(NULL));
    for (unsigned int i=0; i<grid.getNbRow(); ++i)
    {
        for (unsigned int j=0; j<grid.getNbCol(); j++)
        {
            grid.setCell(i,j,rand()% grid.getNbPossibleStates());
        }
    }
}
