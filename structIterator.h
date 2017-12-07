#ifndef STRUCTITERATOR_H
#define STRUCTITERATOR_H

#include "term.h"
#include "struct.h"
#include "iterator.h"

class Struct;

template<class T>
class StructIterator :public Iterator<T>{
    public:
        StructIterator(Struct* s): _index(0), _s(s){}
        void first();
        Term* currentItem() const;
        bool isDone() const;
        void next();
    private:
        int _index;
        Struct*_s;
};

#endif // STRUCTITERATOR_H
