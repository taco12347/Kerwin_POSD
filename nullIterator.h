#ifndef NULLITERATOR_H
#define NULLITERATOR_H

#include "iterator.h"
#include "term.h"

class Term;

template<class T>
class NullIterator: public Iterator<T>{
    public:
        NullIterator(T term): _term(term){}
        void first();
        void next();
        Term* currentItem() const;
        bool isDone() const;
    private:
        T _term;
};

#endif