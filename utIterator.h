#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "iterator.h"
#include "structIterator.h"
#include "listIterator.h"
#include "nullIterator.h"
#include "parser.h"
#include "scanner.h"
#include <iostream>

TEST(iterator, first) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    //StructIterator it(&s);
    Iterator<Term*>* itStruct = s.createIterator();
    //Iterator &itStruct = it;
    //ASSERT_EQ(it.first()->symbol());
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, nested_iterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });
  StructIterator<Term*> it(&s);
  it.first();
  it.next();
  Struct *s2 = dynamic_cast<Struct *>(it.currentItem());

  StructIterator<Term*> it2(s2);
  it2.first();
  ASSERT_EQ("X", it2.currentItem()->symbol());
  ASSERT_FALSE(it2.isDone());
  it2.next();
  ASSERT_EQ("2", it2.currentItem()->symbol());
  ASSERT_FALSE(it2.isDone());
  it2.next();
  ASSERT_TRUE(it2.isDone());
}


TEST(iterator, firstList) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    Iterator<Term*>* itList = l.createIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

TEST(iterator, NullIterator){
  Number one(1);
  Iterator<Term*>* it = one.createIterator();
  it->first();
  ASSERT_TRUE(it->isDone());
}

// s(1, w(X, 5), Y)
TEST(iterator, structDFSIteratorForFirst){
  Scanner scanner("s(1, w(X, 5), Y)");
    Parser parser(scanner);
    Struct *s = dynamic_cast<Struct*>(parser.createTerm());
    Iterator<Term*>* it = s->createDFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    ASSERT_FALSE(it->isDone());
}
// s(1, w(X, 5), Y)
TEST(iterator, structDFSIteratorForTotal){
    Scanner scanner("s(1, w(X, 5), Y)");
    Parser parser(scanner);
    Struct *s = dynamic_cast<Struct*>(parser.createTerm());
    Iterator<Term*>* it = s->createDFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("w(X, 5)", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("X", it->currentItem()->symbol());
    it->next();
    it->next();
    ASSERT_EQ("Y", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

// s(1, w(X, 5), Y)
TEST(iterator, stuctBFSIteratorForFirst){
    Scanner scanner("s(1, w(X, 5), Y)");
    Parser parser(scanner);
    Struct *s = dynamic_cast<Struct*>(parser.createTerm());
    Iterator<Term*>* it = s->createBFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    ASSERT_FALSE(it->isDone());
}

// s(1, w(X, 5), Y)
TEST(iterator, stuctBFSIteratorForTotal){
    Scanner scanner("s(1, w(X, 5), Y)");
    Parser parser(scanner);
    Struct *s = dynamic_cast<Struct*>(parser.createTerm());
    Iterator<Term*>* it = s->createBFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("w(X, 5)", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("Y", it->currentItem()->symbol());
    it->next();
    it->next();
    ASSERT_EQ("5", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

// [1, w(X, 5), Y]
TEST(iterator, listDFSIteratorForFirst){
    Scanner scanner("[1, w(X, 5), Y]");
    Parser parser(scanner);
    List *l = dynamic_cast<List*>(parser.createTerm());
    Iterator<Term*>* it = l->createDFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    ASSERT_FALSE(it->isDone());
}

// [1, w(X, 5), Y]
TEST(iterator, listDFSIteratorForTotal){
    Scanner scanner("[1, w(X, 5), Y]");
    Parser parser(scanner);
    List *l = dynamic_cast<List*>(parser.createTerm());
    Iterator<Term*>* it = l->createDFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("w(X, 5)", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("X", it->currentItem()->symbol());
    it->next();
    it->next();
    ASSERT_EQ("Y", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}

// [1, w(X, 5), Y]
TEST(iterator, listBFSIteratorForFirst){
    Scanner scanner("[1, w(X, 5), Y]");
    Parser parser(scanner);
    List *l = dynamic_cast<List*>(parser.createTerm());
    Iterator<Term*>* it = l->createBFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    ASSERT_FALSE(it->isDone());
}

// [1, w(X, 5), Y]
TEST(iterator, listBFSIteratorForTotal){
    Scanner scanner("[1, w(X, 5), Y]");
    Parser parser(scanner);
    List *l = dynamic_cast<List*>(parser.createTerm());
    Iterator<Term*>* it = l->createBFSIterator();
    it->first();
    ASSERT_EQ("1", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("w(X, 5)", it->currentItem()->symbol());
    it->next();
    ASSERT_EQ("Y", it->currentItem()->symbol());
    it->next();
    it->next();
    ASSERT_EQ("5", it->currentItem()->symbol());
    ASSERT_TRUE(it->isDone());
}


#endif
