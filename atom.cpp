#include "atom.h"
#include "variable.h"
#include "number.h"


string Atom::value(){
    return _value;
}

string Atom::symbol(){
    return _symbol;
}

bool Atom::match(Atom atom){
    return symbol() == atom.symbol();
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

