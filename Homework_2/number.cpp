#include "number.h"

string Number::value(){return this._value;}

bool Number::match(Atom atom){
     return false;
}

bool Number::match(Variable variable){
     return this._symbol == variable.value();
}


