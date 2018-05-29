#include "gridGenerator.h"

void Grid::setCell(unsigned int i,unsigned int j,int val){
    if(i>=nb_rows || j>=nb_columns){
        throw "Error: cell's row or col value greater than grid's";
    }
    if(val<0 || val>=nb_possible_states){
        throw "Error: cell's row or col value greater than grid's";
    }
    value[i][j]=val;
}

unsigned int Grid::getCell(unsigned int i,unsigned int j) const{
    if(i>=nb_rows || j>=nb_columns){
        throw "Error: cell's row or col value greater than grid's";
    }
    return value[i][j];
}

std::ostream & operator<<(std::ostream & f,const Grid & g){
    for(unsigned int i=0; i<g.getNbRow();i++){
        for(unsigned int j=0; j<g.getNbCol();j++){
            f << g.getCell(i,j) << " ";
        }
        f << std::endl;
    }
    return f;
}

void Grid::executeGridGenerator(GridGenerator& generation_strategy)
{
        generation_strategy.generateGrid(*this);
}
