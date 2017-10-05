#include "variable.h"

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
