#include "struct.h"


Atom Struct::name(){return _name;}
int Struct::getTermSize(){return _term.size();}

Term* Struct::args(int index){
    return _term[index];
}

std::string Struct::symbol(){
    string description;
    description = _name.symbol() + "(";
    for(int i=0; i<_term.size(); i++){
        if(i < _term.size()-1)
            description += _term[i]->symbol() + ", ";
        else
            description += _term[i]->symbol() + ")";
    }
    return description;
}



bool Struct::match(Term *term){
    Struct *st = dynamic_cast<Struct *>(term);
    bool judgement = true;
    if(_name.symbol() != st->name().symbol()) judgement = false;
    else{
        if( getTermSize() != st->getTermSize()) judgement = false;
        else{
            for(int i=0; i<getTermSize(); i++){
                if(_term[i]->value() != st->args(i)->value()){
                    judgement = false;
                    break;
                }
            }
        }
    }
    return judgement;
}

bool Struct::match(Atom *atom){return false;}

std::string Struct::value(){
    string description;
    description = _name.symbol() + "(";
    for(int i=0; i<_term.size(); i++){
        if(i < _term.size()-1)
            description += _term[i]->value() + ", ";
        else
            description += _term[i]->value() + ")";
    }
    return description;
}
