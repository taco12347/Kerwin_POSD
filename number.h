#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "variable.h"
#include "atom.h"
#include "term.h"
#include "iterator.h"
#include "nullIterator.h"

class Atom;
class Variable;
template <class T>
class Iterator;
template <class T>
class NullIterator;

class Number : public Term {
    public:
        Number(double value):_value(std::to_string(value)) {
             _value.erase(_value.find_last_not_of('0') + 1, std::string::npos);
             _value.erase(_value.find_last_not_of('.') + 1, std::string::npos);
             _symbol = _value;
        }
        bool match(Variable &variable);
        bool match(Term &term);
        string value();
        string symbol();
        Iterator<Term*>* createIterator();
    private:
        string _value;
        string _symbol;
};

#endif
