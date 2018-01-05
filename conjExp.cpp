#include "conjExp.h"
#include <iostream>

bool ConjExp::evaluate(){
    bool tempLeftEvaluate = _left->evaluate();
    bool tempRightEvaluate = _right->evaluate();
    
    return (tempLeftEvaluate && tempRightEvaluate);
}

string ConjExp::getDiscription(){
    evaluate();
    if(_right->getDiscription() == _trueDiscription && _left->getDiscription() == _trueDiscription)
        return _trueDiscription;
    else if(_right->getDiscription() == _falseDiscription || _left->getDiscription() == _falseDiscription )
        return _falseDiscription;
    else if(_left->getDiscription() == _trueDiscription)
        return _right->getDiscription();
    else if(_right->getDiscription() == _trueDiscription)
        return _left->getDiscription();
    else if(_left->getDiscription().find(_right->getDiscription()) != string::npos)
        return _left->getDiscription();
    else 
        return _left->getDiscription() + ", " + _right->getDiscription();
}