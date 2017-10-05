#include "atom.h"

string Atom::value(){return this._value;}

bool Atom::match(Atom atom){
    return _symbol == atom._symbol;
}

bool Atom::match(Variable variable){
    return this._symbol == variable.value();
}


