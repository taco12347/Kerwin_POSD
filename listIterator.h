#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "term.h"
#include "list.h"
#include "iterator.h"

class List;

template<class T>
class ListIterator :public Iterator<T>{
    public:
        ListIterator(List *list): _index(0), _list(list) {}
        void first();
        Term* currentItem() const;
        bool isDone() const;
        void next();
    private:
        int _index;
        List* _list;
};

#endif