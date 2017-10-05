#include "atom.h"
#include "variable.h"

string Atom::value(){
    return _value;
}

bool Atom::match(Atom atom){
    return _symbol == atom._symbol;
}

bool Atom::match(Variable &variable){
    if(variable.getAssignable()){
        variable.setValue(value());
        variable.setAssignable(false);
        return true;
    }
    else{
        return value() == variable.value();
    }
}

bool Atom::match(Number number){
    return false;
}

