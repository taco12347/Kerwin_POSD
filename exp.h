#ifndef EXP_H
#define EXP_H

#include "variable.h"
#include "term.h"
enum Operators {SEMICOLON, COMMA, EQUALITY, TERM};

class Exp {
    public:
        virtual bool evaluate() = 0;
        virtual string getDiscription() = 0;
        const string _trueDiscription = "true";
        const string _falseDiscription = "false";
};
#endif
