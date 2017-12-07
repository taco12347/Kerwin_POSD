#ifndef ITERATOR_H
#define ITERATOR_H

#include "term.h"

class Term;
template<class T>
class Iterator {
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual Term* currentItem() const = 0;
    virtual bool isDone() const = 0;
};

#endif
