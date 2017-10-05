#include "number.h"
#include "variable.h"
#include "atom.h"

string Number::value(){
    return _value;
}

bool Number::match(Atom atom){
     return false;
}

bool Number::match(Variable &variable){
     if(variable.getAssignable()){
         variable.setValue(value());
         variable.setAssignable(false);
         return true;
     }
     else{
        return value() == variable.value();
     }
}

bool Number::match(Number number){
    return value() == number.value();
}

