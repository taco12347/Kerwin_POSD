#include "variable.h"
#include "atom.h"

string Variable::value(){return _value;}

bool Variable::match(Atom atom){
    bool ret = _assignable;
    if(_assignable){
      _value = atom._symbol;
      _assignable = false;
    }
    else{
        if(_value == atom.value()){
            ret = true;
        }
    }
    return ret;
}

bool Variable::match(Number number){
    bool ret = _assignable;
    if(_assignable){
        _value = number.value();
        _assignable = false;
    }
    else{
        if(_value == number.value()){
            ret = true;
        }
    }
    return ret;
}

bool Variable::getAssignable(){
    return _assignable;
}

void Variable::setValue(string value){
    _value = value;
}

void Variable::setAssignable(bool assignable){
    _assignable = assignable;
}

