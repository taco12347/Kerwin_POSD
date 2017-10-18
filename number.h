#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "variable.h"
#include "atom.h"
#include "term.h"

class Number : public Term {
    public:
        Number(double value):_value(std::to_string(value)) { _symbol = std::to_string(value);}
        bool match(Atom *atom);
        bool match(Variable *variable);
        bool match(Number *number);
        bool match(Term* term){};
        string value();
        string symbol();

    private:
        string _value;
        string _symbol;
};

#endif
