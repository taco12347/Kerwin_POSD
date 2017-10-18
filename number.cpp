#include "number.h"

string Number::value(){
    return _value;
}

string Number::symbol(){
    return _symbol;
}

bool Number::match(Atom *atom){
     return false;
}

bool Number::match(Variable *variable){
     if(variable->getAssignable()){
         variable->setValue(this);
         variable->setAssignable(false);
         return true;
     }
     else{
        return value() == variable->value();
     }
}

bool Number::match(Number *number){
    return value() == number->value();
}

