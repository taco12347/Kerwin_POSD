#include "matchExp.h"
#include <iostream>

bool MatchExp::evaluate(){
    return _left->match(*_right);
}

string MatchExp::getDiscription(){
    if(evaluate() && (_left->symbol() == _right->symbol())){
        return _trueDiscription;
    }
    else if (!evaluate())
        return _falseDiscription;
    else
        return _left->symbol() + " = " + _right->value();
}