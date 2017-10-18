#include "variable.h"
#include <iostream>

string Variable::value(){
    if(_value != NULL){
        return _value->value();
    }
    else{
        return symbol();
    }
}

string Variable::symbol(){return _symbol;}

bool Variable::match(Atom *atom){
    bool ret = _assignable;
    if(_assignable){
      _value = atom;
      _assignable = false;
      if(_connectVar.size() != 0){
          for(int i=0; i<_connectVar.size(); i++){
              if(_connectVar[i] != this) _connectVar[i]->match(atom);
          }
      }
    }
    else{
        if(_value->value() == atom->value()){
            ret = true;
        }
    }
    return ret;
}

bool Variable::match(Number *number){
    bool ret = _assignable;
    if(_assignable){
        _value = number;
        _assignable = false;
        if(_connectVar.size() != 0){
          for(int i=0; i<_connectVar.size(); i++){
              if(_connectVar[i]->symbol() != this->symbol()){
                    _connectVar[i]->match(number);
              }
          }
        }
    }
    else{
        if(_value->value() == number->value()){
            ret = true;
        }
    }
    return ret;
}

bool Variable::getAssignable(){
    return _assignable;
}

void Variable::setValue(Term *value){
    _value = value;
}

void Variable::setAssignable(bool assignable){
    _assignable = assignable;
}

bool Variable::match(Variable *variable){
    bool ret = _assignable;
    if(_assignable){
        setConnectTerm(variable);
        variable->setConnectTerm(this);
        if(variable->getAssignable() != true){
            _value = variable;
        }
    }
    else{
        if(_value->value() == variable->value()){
            ret = true;
        }
        else ret = false;
    }
    return ret;
}

string Variable::getConnectTerm(int index){
    return _connectVar[index]->value();
}

void Variable::setConnectTerm(Term* term){
    _connectVar.push_back(term);
}

bool Variable::match(Term* term){
    bool ret = _assignable;
    if(_assignable){
        _value = term;
    }
    else{
        if(_value->value() == term->value()){
            ret = true;
        }
        else ret = false;
    }
    return ret;
}
