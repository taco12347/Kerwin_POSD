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
        string _symbol;
        Number(string s, string value):_symbol(s), _value(value) {}
        bool match(Atom atom);
        bool match(Variable &variable);
        bool match(Number number);
        string value();

    private:
        string _value;
};

#endif
