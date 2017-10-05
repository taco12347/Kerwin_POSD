#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "variable.h"
#include "number.h"

using std::string;

class Atom;
class Number;
class Variable{
    public:
        string const _symbol;
        Variable(string s):_symbol(s){}

        string value();
        bool match(Atom atom);
        bool match(Number number);
        bool getAssignable();
        void setValue(string value);
        void setAssignable(bool assignable);

    private:
        string _value;
        bool _assignable = true;
};

#endif
