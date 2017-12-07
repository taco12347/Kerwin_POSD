#ifndef BFSITERATOR_H
#define BFSITERATOR_H

#include "iterator.h"
#include <vector>
#include "struct.h"
#include "list.h"
#include "term.h"
#include <queue>
#include <iostream>

using std::vector;
template<class T>
class BFSIterator: public Iterator<T>{
    public:
        BFSIterator(T term): _index(0), _originalTerm(term) {}
        void first();
        void next();
        Term* currentItem() const;
        bool isDone() const;
        void extractTermByBFS(T term);
    private:
        int _index;
        T _originalTerm;
        vector<T> _bfsTerms;
        
};

#endif