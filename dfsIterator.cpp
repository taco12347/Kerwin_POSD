#include "dfsIterator.h"
#include <iostream>

template<class T>
void DFSIterator<T>::first(){
    _dfsTerms.empty();
    _index = 1;
    extractTermByDFS(_originalTerm);
}

template<class T>
void DFSIterator<T>::next(){
    _index++;
}

template<class T>
Term* DFSIterator<T>::currentItem() const{
    if(isDone() == false || _index == _dfsTerms.size() - 1)
        return _dfsTerms[_index];
}

template<class T>
bool DFSIterator<T>::isDone() const{
    return _index >= _dfsTerms.size() - 1;
}

template<class T>
void DFSIterator<T>::extractTermByDFS(T term){
    _dfsTerms.push_back(term);
    Struct *tempS = dynamic_cast<Struct*>(term);
    List *tempL = dynamic_cast<List*>(term);
    if(tempS != nullptr){
        for(int index = 0; index < tempS->arity(); index++) extractTermByDFS(tempS->args(index));
    }
    if(tempL != nullptr){
        for(int index = 0; index < tempL->arity(); index++) extractTermByDFS(tempL->args(index));
    }  
}

template class DFSIterator<Term*>;