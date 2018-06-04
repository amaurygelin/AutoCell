#include <iostream>
#include "GameOfLife.h"

using namespace std;

/*bool GameOfLife::cellAlive(unsigned int i, unsigned int j) const
{
    if(getCell(i, j))
        return true;
    else
        return false;
}*/

void GameOfLife::transition(const Grid& src, Grid& dest) const
{
    unsigned int nb_neighbours_alive(0);
    if( (src.getNbRow() != dest.getNbRow()) || (src.getNbCol() != dest.getNbCol()) )
    {
        throw "Grids with different number of columns and/or number of rows";
    }
    for(int i(0); i<src.getNbRow(); i++)
    {
        for(int j(0); j<src.getNbCol(); j++)
        {
            //counting the number of neighbours alive

            if(j-1>=0) //if there is a neighbour on the left
                if(src.getCell(i,j-1)) //if he is alive
                    nb_neighbours_alive++;
            if(j+1<=src.getNbCol()-1)
                if(src.getCell(i,j+1)) //right
                    nb_neighbours_alive++;
            if(i-1>=0)
                if(src.getCell(i-1,j)) //top
                    nb_neighbours_alive++;
            if(i+1<=src.getNbRow()-1)
                if(src.getCell(i+1,j)) //bottom
                    nb_neighbours_alive++;
            if(i-1>=0 && j-1>=0)
                if(src.getCell(i-1,j-1)) //top left corner
                    nb_neighbours_alive++;
            if(i-1>=0 && j+1<=src.getNbCol()-1)
                if(src.getCell(i-1,j+1)) //top right corner
                    nb_neighbours_alive++;
            if(i+1<=src.getNbRow()-1 && j-1>=0)
                if(src.getCell(i+1,j-1)) //bottom left corner
                    nb_neighbours_alive++;
            if(i+1<=src.getNbRow()-1 && j+1<=src.getNbCol()-1)
                if(src.getCell(i+1,j+1)) //bottom right corner
                    nb_neighbours_alive++;

            if(src.getCell(i,j)) //if the current cell is alive
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
            nb_neighbours_alive = 0;
        }
    }
}


