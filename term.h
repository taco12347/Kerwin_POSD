#ifndef TERM_H
#define TERM_H

#include <string>
using std::string;

class Atom;
class Variable;
class Number;

class Term {
    public:
        virtual string symbol() = 0;
        virtual string value() = 0;
        virtual bool match(Number *number) =0;
        virtual bool match(Atom *atom) =0;
        virtual bool match(Term * term) = 0;
};

#endif
