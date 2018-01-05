#ifndef DISJEXP_H
#define DISJEXP_H

#include "exp.h"

class DisjExp : public Exp{
    public:
        DisjExp(Exp *left, Exp *right):_left(left), _right(right){}
        bool evaluate();
        string getDiscription();
    private:
        Exp *_left;
        Exp *_right;
};

#endif