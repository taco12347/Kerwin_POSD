#include "nullIterator.h"

template<class T>
void NullIterator<T>::first() {}

template<class T>
void NullIterator<T>::next() {}

template<class T>
Term* NullIterator<T>::currentItem() const{
    return nullptr;
}

template<class T>
bool NullIterator<T>::isDone() const{ return true; }

template class NullIterator<Term*>;