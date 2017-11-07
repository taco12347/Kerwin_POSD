#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "atom.h"
#include "variable.h"
#include "scanner.h"
#include "struct.h"
#include "term.h"
#include "list.h"

using std::string;

class Parser{
    public:
        Parser(Scanner scanner) : _scanner(scanner){}
        Term* createTerm();
        vector<Term*> getArgs();
    private:
        Scanner _scanner;
        int _currentToken;
};
#endif
