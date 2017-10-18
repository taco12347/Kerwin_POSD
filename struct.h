#ifndef STRUCT_H
#define STRUCT_H

#include <string>
#include "term.h"
#include "atom.h"
#include "variable.h"
#include "number.h"
#include <vector>

class Struct : public Term{
    public:
        Struct(Atom atom, std::vector<Term *> term): _name(atom), _term(term){}
        std::string symbol();
        std::string value();
        bool match(Number *number){};
        bool match(Atom *atom);
        bool match(Term *term);
        Atom name();
        Term* args(int index);
        int getTermSize();
    private:
        std::vector<Term *> _term;
        Atom _name;
};


#endif
