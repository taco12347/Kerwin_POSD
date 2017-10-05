#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "number.h"
#include "variable.h"

using std::string;

class Variable;
class Number;

class Atom {
public:
    string _symbol;
    Atom (string s, string value):_symbol(s),_value(value) {}
    bool match(Atom atom);
    bool match(Variable &variable);
    bool match(Number number);
    string value();

private:
    string _value;
};

#endif
