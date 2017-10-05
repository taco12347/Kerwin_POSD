#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "number.h"
#include "atom.h"

using std::string;

class Atom;
class Number;
class Variable{
    public:
        string const _symbol;
        Variable(string s):_symbol(s){}

        string value();
        bool match(Atom atom);

 /* bool match( Atom atom ){
    bool ret = _assignable;
    if(_assignable){
      _value = atom._symbol ;
      _assignable = false;
    }
    else{
        if(_value == atom.value()){
            ret = true;
        }
    }
    return ret;
  }*/


    private:
        string _value;
        bool _assignable = true;
};

#endif
