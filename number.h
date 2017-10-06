#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "variable.h"
#include "atom.h"

using std::string;

class Atom;
class Variable;

class Number {
    public:
        Number(int value):_value(std::to_string(value)) { _symbol = std::to_string(value);}
        bool match(Atom atom);
        bool match(Variable &variable);
        bool match(Number number);
        string value();
        string symbol();

    private:
        string _value;
        string _symbol;

};

#endif
