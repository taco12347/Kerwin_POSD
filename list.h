#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <vector>
#include <string>

using std::vector;

class List : public Term {
    public:
        List(): _elements() {}
        List(vector<Term *> const & elements):_elements(elements){}
        string symbol();
        string value();
        bool match(Term & term);
        Term * head() const;
        List * tail() const;
        Term &getElement(int index);
        //void setElement(Term *element);

    private:
        vector<Term *> _elements;
};

#endif
