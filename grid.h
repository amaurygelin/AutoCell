#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <iostream>
#include <vector>

class Grid{
    unsigned int nb_rows;
    unsigned int nb_columns;
    std::vector<std::vector<int>> value;
    const GridGenerator& generation_strategy;
    unsigned int nb_possible_states;
public:
    Grid(unsigned int nb_r, unsigned int nb_c, unsigned int nb_s):nb_rows(nb_r),nb_columns(nb_c),value(nb_rows,std::vector<int>(nb_columns)),nb_possible_states(nb_s){}
    Grid(const Grid& g):nb_rows(g.nb_rows),nb_columns(g.nb_columns),value(nb_rows,std::vector<int>(nb_columns)),nb_possible_states(g.nb_possible_states){}
    void generateGrid(){
        generation_strategy.generateGrid(*this);
    }
    unsigned int getNbRow() const { return nb_rows; }
    unsigned int getNbCol() const { return nb_columns; }
    unsigned int getNbPossibleStates() const { return nb_possible_states; }
    void setCell(unsigned int i,unsigned int j,int val);
    unsigned int getCell(unsigned int i,unsigned int j) const;
};

#endif // GRID_H_INCLUDED


std::ostream & operator<<(std::ostream & f,const Grid & g);


