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
    Atom (string s):_symbol(s){ _value = s;}
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
