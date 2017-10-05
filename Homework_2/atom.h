#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "variable.h"
#include "number.h"

using std::string;

class Number;
class Variable;
class Atom {
public:
    string _symbol;
    Atom (string s):_symbol(s) {}
    bool match(Atom atom);
    bool match(Variable variable);
    string value();

private:
    string _value;
};

#endif
