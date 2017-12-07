#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "number.h"
#include "variable.h"
#include "term.h"
#include "iterator.h"

class Number;
class Variable;

class Atom : public Term {
public:
    Atom (string s):_symbol(s){ _value = s;}
    bool match(Term &term);
    bool match(Variable &variable);
    string value();
    string symbol();
    Iterator<Term*>* createIterator();
private:
    string _value;
    string _symbol;
};

#endif
