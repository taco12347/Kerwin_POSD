#include "disjExp.h"

bool DisjExp::evaluate(){
    return (_left->evaluate() || _right->evaluate());
}

string DisjExp::getDiscription(){
    evaluate();
    if( _left->getDiscription() == _falseDiscription)
        return _right->getDiscription();
    else if ( _right->getDiscription() == _falseDiscription)
        return _left->getDiscription();
    else
        return _left->getDiscription() + "; " + _right->getDiscription();
}