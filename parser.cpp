#include "parser.h"
#include <iostream>

Term* Parser::createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
        return new Variable(symtable[_scanner.tokenValue()].first);
    }
    else if(token == NUMBER){
        return new Number(_scanner.tokenValue());
    }
    else if(token == ATOM || token == ATOMSC){
        Atom* tempAtom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '('){
            _scanner.nextToken();
            vector<Term*> terms = getArgs();
            if(_currentToken == ')'){
                return new Struct(*tempAtom, terms);
            }
        }

        else
            return tempAtom;
    }
    else if(token == '['){
        vector<Term*> finalTerm = getArgs();
        if(_currentToken == ')') throw(std::string("unexpected token"));
        if(_currentToken == ']' || _currentToken == 0){
            List* l = new List(finalTerm);
            return l;
        }
    }
        //else std::cout << " Now Char = " << _scanner.currentChar() << std::endl;
    return nullptr;
}

vector<Term*> Parser::getArgs()
{
    Term* term = createTerm();
    vector<Term*> args = {};
    if(term){
      args.push_back(term);
    }
    if((_currentToken == ']' || _currentToken == ')') && term == nullptr){
        return args;
    }
    while((_currentToken = _scanner.nextToken()) == ',') {
            args.push_back(createTerm());
    }
    return args;
}
