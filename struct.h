#ifndef STRUCT_H
#define STRUCT_H

#include <string>
#include "term.h"
#include "atom.h"
#include "variable.h"
#include "number.h"
#include <vector>
#include "structIterator.h"
#include "dfsIterator.h"
#include "bfsIterator.h"

template <class T>
class Iterator;
template <class T>
class StructIterator;
template <class T>
class DFSIterator;

class Struct : public Term{
    public:
        Struct(Atom atom, std::vector<Term *> term): _name(atom), _term(term){}
        std::string symbol();
        std::string value();
        bool match(Term &term);
        Atom name();
        Term* args(int index);
        int getTermSize();
        int arity();
        Iterator<Term*>* createIterator();
        Iterator<Term*>* createDFSIterator();
        Iterator<Term*>* createBFSIterator();
        
    private:
        std::vector<Term *> _term;
        Atom _name;
};


#endif
