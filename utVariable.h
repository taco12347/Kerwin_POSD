#ifndef UTVARIABLE_H
#define UTVARIABLE_H

#include <vector>
#include "variable.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "term.h"

TEST(Variable, constructor){
  Variable X("X");
  ASSERT_EQ("X", X._symbol);
}

TEST(Variable , matching){
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_EQ( "tom", X.value());
}

TEST (Variable , haveValue){
  Atom tom ("tom");
  Atom jerry ("jerry");
  Variable X("X");
  ASSERT_TRUE(X.match(tom));
  ASSERT_FALSE(X.match(jerry));
}

// ?- X=2.7182.
// X=2.7182
TEST(Variable , numE_to_varX){
    Variable X("X");
    Number number1(2.7182);
    ASSERT_TRUE(X.match(number1));
}

// ?- X=Y, X=1.
// Y=1
TEST (Variable, varY_to_varX_and_num1_to_varX) {
    Variable X("X");
    Variable Y("Y");
    Number number1(1);
    X.match(Y);
    ASSERT_TRUE(X.match(number1));
    ASSERT_EQ("1.000000", Y.value());
}

// ?- X=Y, Y=1.
// X=1
TEST (Variable, varY_to_varX_and_num1_to_varY) {
    Variable X("X");
    Variable Y("Y");
    Number number1(1);
    X.match(Y);
    ASSERT_TRUE(Y.match(number1));
    ASSERT_EQ("1.000000", X.value());
}

// ?- X=X, X=1.
// X=1
TEST (Variable, varX_match_varX_and_num1_to_varX) {
    Variable X("X");
    X.match(X);
    Number number1(1);
    ASSERT_TRUE(X.match(number1));
    ASSERT_EQ("1.000000", X.value());
}

// ?- Y=1, X=Y.
// X=1
TEST (Variable, num1_to_varY_and_varX_match_varY) {
    Variable X("X");
    Variable Y("Y");
    Number number1(1);
    ASSERT_TRUE(Y.match(number1));
    X.match(Y);
    ASSERT_EQ("1.000000", X.value());
}

// ?- X=Y, Y=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varY_to_varX) {
    Variable X("X");
    Variable Y("Y");
    Variable Z("Z");
    Number number1(1);
    X.match(Y);
    Y.match(Z);
    ASSERT_TRUE(Z.match(number1));
    ASSERT_EQ("1.000000", X.value());
    ASSERT_EQ("1.000000", Y.value());
    ASSERT_EQ("1.000000", Z.value());
}

// ?- X=Y, X=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varX_and_varY_to_varX) {
    Variable X("X");
    Variable Y("Y");
    Variable Z("Z");
    Number number1(1);
    X.match(Y);
    X.match(Z);
    ASSERT_TRUE(Z.match(number1));
    ASSERT_EQ("1.000000", X.value());
    ASSERT_EQ("1.000000", Y.value());
    ASSERT_EQ("1.000000", Z.value());
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(X)"
TEST (Variable, Struct1) {
    Variable X("X");
    std::vector<Term *> v = {&X};
    Struct s(Atom("s"), v);
    Variable Y("Y");
    Y.match(s);
    ASSERT_EQ("Y", Y.symbol());
    ASSERT_EQ("s(X)", Y.value());
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// And X matches Atom "teddy"
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(teddy)"
TEST (Variable, Struct2) {
    Variable X("X");
    std::vector<Term *> v = {&X};
    Struct s(Atom("s"), v);
    Variable Y("Y");
    Y.match(s);
    Atom atom1("teddy");
    X.match(atom1);
    ASSERT_EQ("Y", Y.symbol());
    ASSERT_EQ("s(teddy)", Y.value());
}

#endif
