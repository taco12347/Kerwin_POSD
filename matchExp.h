#ifndef MATCHEXP_H
#define MATCHEXP_H

#include "exp.h"
#include "term.h"

class MatchExp : public Exp{
    public:
        MatchExp(Term *left, Term *right): _left(left), _right(right){}
        bool evaluate();
        string getDiscription();
    private:
        Term *_left;
        Term *_right;
};

#endif