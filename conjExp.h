#ifndef CONJEXP_H
#define CONJEXP_H

#include "exp.h"

class ConjExp : public Exp{
    public:
        ConjExp(Exp *left, Exp *right): _left(left), _right(right){}
        bool evaluate();
        string getDiscription();
    private:
        Exp *_left;
        Exp *_right;
};
#endif