#include <iostream>
#include "GameOfLife.h"

using namespace std;

void GameOfLife::lifeManager(const Grid& src, Grid& dest, int i, int j) const
{
    int nb_neighbours_alive = countNeighboursAlive(src,i,j,1);
    if(src.getCell(i,j)==1) //if the current cell is alive
    {
        if(nb_neighbours_alive>=min_neighbours_to_stay_alive && nb_neighbours_alive<=max_neighbours_to_stay_alive)
            //stay alive
            dest.setCell(i,j,1);
        else
            //die
            dest.setCell(i,j,0);
    }
    else
    {
        if(nb_neighbours_alive==nb_neighbours_to_born)
            //born
            dest.setCell(i,j,1);
        else
            //stay dead
            dest.setCell(i,j,0);
    }
}
