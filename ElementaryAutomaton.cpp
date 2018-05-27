#include <iostream>
#include "ElementaryAutomaton.h"

using namespace std;

short unsigned int bits2num(const string& bits)
{
    if (bits.size() != 8) throw string("Undefined Automaton Rule Number");
    int power = 1;
    short unsigned int num = 0;
    for (int i = 7; i >= 0; i--)
    {
        if (bits[i] == '1') num += power;
        else if (bits[i] != '0') throw string("Undefined Automaton Rule Number");
        power *= 2;
    }
    return num;
}

string num2bits(short unsigned int num)
{
    string bits;
    if (num > 256) throw string("Undefined Automaton Rule Number");
    unsigned short int p = 128;
    int i = 7;
    while (i >= 0)
    {
        if (num >= p)
        {
            bits.push_back('1');
            num -= p;
        }
        else
        {
            bits.push_back('0');
        }
        i--;
        p = p / 2;
    }
    return bits;
}

ostream& ElementaryAutomaton::display(ostream& f) const
{
    Automaton::display(f);
    f << "############ ELEMENTARY AUTOMATON" << endl;
    f << "Rule number : " << rule_num << endl;
    f << "Rule bits : " << rule_bits << endl;
    return f;
}
