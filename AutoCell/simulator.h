#ifndef SIMULATOR_H_INCLUDED
#define SIMULATOR_H_INCLUDED

#include "Grid.h"
#include "Automaton.h"
#include "saveManager.h"

class Simulator{
    static Simulator* uniqueSim;
    const Automaton& automaton;
    const Grid* initial_grid;
    unsigned int max_grids;
    std::vector<Grid*> grids;
    unsigned int cur_rank;
    Simulator(const Automaton& autom, unsigned int max_g=2);
    Simulator(const Automaton& autom, const Grid& initial_g,unsigned int max_g=2);
    virtual ~Simulator();
    void operator=(const Simulator&);
public:
    void setInitialGrid(const Grid& grid);
    void next();
    void run(unsigned int nbSteps);
    void reset();
    const Grid& last() const;
    unsigned int getCurRank() const{return cur_rank;}
    unsigned int getMaxGrids() const{return max_grids;}
    void build(unsigned int c);
    void displayGrids();
    static Simulator& getSimulator(const Automaton& autom, const Grid& initial_g, unsigned int max_g);
    static Simulator& getSimulator(const Automaton& autom, unsigned int max_g);
    static void freeInstance();
    void save(SaveManager &s)
    {
        automaton.accept(s);
    }

};

std::ostream & operator<<(std::ostream & f,const Simulator & s);



#endif // SIMULATOR_H_INCLUDED
