#include "bfsIterator.h"

template<class T>
void BFSIterator<T>::first(){
    _bfsTerms.empty();
    _index = 1;
    extractTermByBFS(_originalTerm);
}

template<class T>
void BFSIterator<T>::next(){
    _index++;
}

template<class T>
Term* BFSIterator<T>::currentItem() const{
    if(isDone() == false || _index == _bfsTerms.size() - 1)
        return _bfsTerms[_index];
}

template<class T>
bool BFSIterator<T>::isDone() const{
    return _index >= _bfsTerms.size() - 1;
}

template<class T>
void BFSIterator<T>::extractTermByBFS(T term){
    std::queue<T> tempQueue;
    tempQueue.push(term);
    while(tempQueue.empty() == false){
        T tempTerm = tempQueue.front();
        tempQueue.pop();
        _bfsTerms.push_back(tempTerm);
        Struct* tempS = dynamic_cast<Struct*>(tempTerm);
        List* tempL = dynamic_cast<List*>(tempTerm);
        if(tempS != nullptr){
            for(int index = 0; index < tempS->arity(); index++) tempQueue.push(tempS->args(index));
        }
        if(tempL != nullptr){
            for(int index = 0; index < tempL->arity(); index++) tempQueue.push(tempL->args(index));
        }
    }
}

template class BFSIterator<Term*>;