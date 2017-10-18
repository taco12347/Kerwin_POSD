#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "number.h"
#include "term.h"
#include <vector>

using std::string;

class Variable : public Term {
    public:
        string const _symbol;
        Variable(string s):_symbol(s), _value(NULL){}
        string symbol();
        string value();
        bool match(Atom *atom);
        bool match(Number *number);
        bool match(Variable *variable);
        bool match(Term *term);
        bool getAssignable();
        void setValue(Term *value);
        void setAssignable(bool assignable);
        string getConnectTerm(int index);
        void setConnectTerm(Term* term);
    private:
        Term* _value;
        bool _assignable = true;
        std::vector<Term *> _connectVar;
};

#endif
