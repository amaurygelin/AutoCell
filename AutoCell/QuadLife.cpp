#include <iostream>
#include "QuadLife.h"

using namespace std;

void QuadLife::lifeManager(const Grid& src, Grid& dest, int i, int j) const
{
    int nb_neighbours_alive[4]; //Contains the 4 different alive states (1, 2 and 3)
    int sum_neighbours_alive=0; //Number of alive cells
    int current_state = src.getCell(i,j); //Current state of the cell

    nb_neighbours_alive[0]=countNeighboursAlive(src,i,j,1);
    nb_neighbours_alive[1]=countNeighboursAlive(src,i,j,2);
    nb_neighbours_alive[2]=countNeighboursAlive(src,i,j,3);
    nb_neighbours_alive[3]=countNeighboursAlive(src,i,j,4);

    for(unsigned int k=0; k<4; ++k)
    {
        sum_neighbours_alive = sum_neighbours_alive + nb_neighbours_alive[k];
    }
    if(current_state != 0) //if the current cell is alive
    {
        if(sum_neighbours_alive>=min_neighbours_to_stay_alive && sum_neighbours_alive<=max_neighbours_to_stay_alive)
            //stay alive
            dest.setCell(i,j,current_state);
        else
            //die
            dest.setCell(i,j,0);
    }
    else
    {
            if(sum_neighbours_alive==nb_neighbours_to_born)
            {
                if((nb_neighbours_alive[0] >= 1) && (nb_neighbours_alive[1] >= 1) && (nb_neighbours_alive[2] >= 1) && (nb_neighbours_alive[3] >= 1)) //Each neighbour has a different state
                {
                    for(unsigned int k=0; k<4; ++k)
                    {
                        if(nb_neighbours_alive[k] == 0) //The cell takes the value of the state which is not present
                        {
                            dest.setCell(i,j,k+1);
                            break;
                        }
                    }
                }
                else // Here the cell take the value of the most present state among the neighbours
                {
                    if((nb_neighbours_alive[0] > nb_neighbours_alive[1]) && (nb_neighbours_alive[0] > nb_neighbours_alive[2]) && (nb_neighbours_alive[0] > nb_neighbours_alive[3]))
                    {
                        dest.setCell(i,j,1);
                    }
                    else if((nb_neighbours_alive[1] > nb_neighbours_alive[0]) && (nb_neighbours_alive[1] > nb_neighbours_alive[2]) && (nb_neighbours_alive[1] > nb_neighbours_alive[3]))
                    {
                        dest.setCell(i,j,2);
                    }
                    else if((nb_neighbours_alive[2] > nb_neighbours_alive[0]) && (nb_neighbours_alive[2] > nb_neighbours_alive[1]) && (nb_neighbours_alive[2] > nb_neighbours_alive[3]))
                    {
                        dest.setCell(i,j,3);
                    }
                    else if((nb_neighbours_alive[3] > nb_neighbours_alive[0]) && (nb_neighbours_alive[3] > nb_neighbours_alive[1]) && (nb_neighbours_alive[3] > nb_neighbours_alive[2]))
                    {
                        dest.setCell(i,j,4);
                    }
                }
            }
            else
                //stay dead
                dest.setCell(i,j,0);
    }
}
