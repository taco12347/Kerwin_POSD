#include "structIterator.h"

template<class T>
void StructIterator<T>::first(){
    _index = 0;
}

template<class T>
Term* StructIterator<T>::currentItem() const{
    return _s->args(_index);
}

template<class T>
bool StructIterator<T>::isDone() const{
    return _index >= _s->arity();
}

template<class T>
void StructIterator<T>::next(){
    _index++;
}

template class StructIterator<Term>;
template class StructIterator<Term*>;
