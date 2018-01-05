#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "atom.h"
#include "variable.h"
#include "scanner.h"
#include "struct.h"
#include "term.h"
#include "list.h"
#include "exp.h"
#include "conjExp.h"
#include "matchExp.h"
#include "disjExp.h"
#include <stack>

using std::string;

class Parser{
    public:
        Parser(Scanner scanner) : _scanner(scanner){}
        Term* createTerm();
        vector<Term*> getArgs();
        Term* finding(Term*);
        Term* findStruct(Struct*,Term*);
        Term* findList(List*, Term*);
        Exp* expressionTree();
        void createTerms();
        vector<Term*> &getTerms();
        void buildExpression();
        void restDisjunctionMatch();
        void disjunctionMatch();
        void restConjunctionMatch();
        void conjunctionMatch();
    private:
        Scanner _scanner;
        int _currentToken;
        Exp * _expressionTree;
        std::stack<Exp*> _expStack;
        int isCOMMA = 0;
        vector<Term *> _terms;
        int _newStartIndex = 0;
};
#endif
