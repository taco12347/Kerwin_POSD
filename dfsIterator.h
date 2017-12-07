#ifndef DFSITERATOR_H
#define DFSITERATOR_H

#include "iterator.h"
#include "list.h"
#include "struct.h"
#include "term.h"
#include <vector>

using std::vector;

template<class T>
class DFSIterator: public Iterator<T>{
    public:
        DFSIterator(T term):_index(0), _originalTerm(term) {}
        void first();
        void next();
        Term* currentItem() const;
        bool isDone() const;
        void extractTermByDFS(T term);

    private:
        vector<T> _dfsTerms;
        T _originalTerm;
        int _index;
};

#endif