#ifndef ELEMENTARYAUTOMATON_H_INCLUDED
#define ELEMENTARYAUTOMATON_H_INCLUDED

#include <string>
#include "Automaton.h"

//Extern services
short unsigned int bits2num(const std::string& bits);
std::string num2bits(short unsigned int num);
//End extern services

class ElementaryAutomaton final: public Automaton{
    private:
        short unsigned int rule_num;
        std::string rule_bits;
    public:
        ElementaryAutomaton(short unsigned int r_num): Automaton(1,2), rule_num(r_num), rule_bits(num2bits(r_num)) {}
        ElementaryAutomaton(std::string r_bits): Automaton(1,2), rule_num(bits2num(r_bits)), rule_bits(r_bits) {}
        short unsigned int getRuleNum() const {return rule_num;}
        std::string getRuleBits() const {return rule_bits;}
        void transition(const Grid& src, Grid& dest) const override;
        std::ostream& display(std::ostream& f = std::cout) const override;
};

#endif // ELEMENTARYAUTOMATON_H_INCLUDED
