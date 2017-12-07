#include "listIterator.h"

template<class T>
void ListIterator<T>::first(){
    _index = 0;
}

template<class T>
Term* ListIterator<T>::currentItem() const{
    return _list->args(_index);
}

template<class T>
bool ListIterator<T>::isDone() const{
    return _index >= _list->arity();
}

template<class T>
void ListIterator<T>::next(){
    _index++;
}

template class ListIterator<Term*>;