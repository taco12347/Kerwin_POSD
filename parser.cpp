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
            else
                throw string("Unbalanced operator");
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
        else
            throw string("Unbalanced operator");
    }
    return nullptr;
}

Term* Parser::finding(Term *term){
    for(int index = _newStartIndex; index < _terms.size() ; index++){
        if(_terms[index]->symbol() == term->symbol()){
            return _terms[index];
        }
        Struct * s = dynamic_cast<Struct*>(_terms[index]);
        List *l = dynamic_cast<List*>(_terms[index]);
        if(s) {
            return findStruct(s,term);
        }
        if(l) {
            return findList(l,term);
        }
    }
    return nullptr;
}

Term* Parser::findStruct(Struct* s, Term* term){
    for(int i = 0; i < s->arity() ; i++){
        if(s->args(i)->symbol() == term->symbol()) return s->args(i);
        Struct * ss = dynamic_cast<Struct*>(s->args(i));
        List * ll = dynamic_cast<List*>(s->args(i));
        if(ss) {
            return findStruct(ss,term);
        }
        if(ll) {
            return findList(ll,term);
        }
    }
}

Term* Parser::findList(List* l, Term* term){
    for(int i = 0; i < l->arity() ; i++){
        if(l->args(i)->symbol() == term->symbol()) return l->args(i);
        Struct * ss = dynamic_cast<Struct*>(l->args(i));
        List * ll = dynamic_cast<List*>(l->args(i));
        if(ss) {
            return findStruct(ss,term);
        }
        if(ll) {
            return findList(ll,term);
        }
    }
}

Exp* Parser::expressionTree(){
    return _expStack.top();
}

void Parser::createTerms(){
    Term* term = createTerm();
    if(term!=nullptr)
    {
        _terms.push_back(term);
        while((_currentToken = _scanner.nextToken()) == ',') {
            _terms.push_back(createTerm());
        }
    }
}

vector<Term*>& Parser::getTerms(){
    return _terms;
}

vector<Term*> Parser::getArgs()
{
    Term* term = createTerm();
    vector<Term*> args = {};
    if(term){
      Variable* variable = dynamic_cast<Variable*>(term);
      if(variable != nullptr){
          for(int index = _newStartIndex; index < _terms.size(); index++){
              if(variable->symbol() == _terms[index]->symbol()) _terms[index]->match(*variable);
          }
      }
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

void Parser::buildExpression(){
    if(_scanner.getBuffer().find(";.") != string::npos)
        throw string("Unexpected ';' before '.'");
    if(_scanner.getBuffer().find(",.") != string::npos)
        throw string("Unexpected ',' before '.'");
    disjunctionMatch();
    restDisjunctionMatch();
    if(createTerm() != nullptr || _currentToken != '.')
        throw string("Missing token '.'");
}

void Parser::restDisjunctionMatch(){
    if(_scanner.currentChar() == ';'){
        isCOMMA = 0;
        _newStartIndex = _expStack.size();
        createTerm();
        disjunctionMatch();
        Exp *right = _expStack.top();
        _expStack.pop();
        Exp *left = _expStack.top();
        _expStack.pop();
        _expStack.push(new DisjExp(left, right));
        restDisjunctionMatch();
    }
}

void Parser::disjunctionMatch(){
    conjunctionMatch();
    restConjunctionMatch();
}

void Parser:: restConjunctionMatch(){
    if(_scanner.currentChar() == ','){
        isCOMMA = 1;
        createTerm();
        conjunctionMatch();
        Exp *right = _expStack.top();
        _expStack.pop();
        Exp *left = _expStack.top();
        _expStack.pop();
        _expStack.push(new ConjExp(left, right));
        restConjunctionMatch();
    }
}

void Parser::conjunctionMatch(){
    Term *left = createTerm();
    if(isCOMMA == 1 && left != nullptr){
        Term *findTerm = finding(left);
        if(findTerm != nullptr){
            left->match(*findTerm);
        }
    }
    _terms.push_back(left);
    if(createTerm() == nullptr && _currentToken == '='){
        isCOMMA = 0;
        Term *right = createTerm();
        _terms.push_back(right);
        _expStack.push(new MatchExp(left, right));
    }
    else
        throw string(left->symbol() + " does never get assignment");
}
