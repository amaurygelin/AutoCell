#include "Simulator.h"



Simulator::Simulator(const Automaton& autom, unsigned int max_g):automaton(autom),max_grids(max_g),grids(max_grids,0){
    for (std::vector<Grid*>::iterator it = grids.begin() ; it != grids.end(); ++it){
        *it = nullptr;
    }
}

Simulator::Simulator(const Automaton& autom, const Grid& initial_g,unsigned int max_g):automaton(autom),initial_grid(&initial_g),max_grids(max_g),grids(max_grids,0),cur_rank(0){
    for (std::vector<Grid*>::iterator it = grids.begin() ; it != grids.end(); ++it){
        *it = nullptr;
    }
    grids.front() = new Grid(initial_g);
}


void Simulator::next(){
    if(initial_grid==nullptr) throw "Initial grid not defined";
    cur_rank++;
    build(cur_rank%max_grids);
    automaton.transition(*grids.at((cur_rank-1)%max_grids),*grids.at((cur_rank)%max_grids));
}

void Simulator::run(unsigned int nbSteps){
    for(unsigned int i=0;i<nbSteps;i++){
        next();
    }
}


void Simulator::reset(){
    if(initial_grid==nullptr) throw "Initial grid not defined";
    if(grids.front()==nullptr)
        grids.front()=new Grid(*initial_grid);
    *grids.front() = *initial_grid;
    cur_rank=0;
}

void Simulator::setInitialGrid(const Grid& grid){
    initial_grid=&grid;
    reset();
}

const Grid& Simulator::last() const{
    return *grids.at(cur_rank%max_grids);
}

Simulator::~Simulator(){
    for (std::vector<Grid*>::iterator it = grids.begin() ; it != grids.end(); ++it){
        delete *it;
    }
}

void Simulator::build(unsigned int c){
    if(c>=max_grids) throw "Error max size reached";
    if(grids.at(c)==nullptr) {
            Grid* g = grids.at(c-1);
            grids.at(c)= new Grid(g->getNbRow(),g->getNbCol(),g->getNbPossibleStates());
    }
}

void Simulator::displayGrids(){
    for (unsigned int i=0; i<=getCurRank() && i<getMaxGrids(); i++){ //loop until cur_rank in case max_grids not reached
        std::cout << *grids[i] << std::endl;
    }
}

