#include "doctest.h"
#include "sources/Fraction.cpp"
#include "sources/Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

TEST_CASE("Check Constructors"){
    Fraction f1(2,4);
    Fraction f2(7,3);

    CHECK_THROWS(Fraction(8,0));
    CHECK_NOTHROW(Fraction(0,-8));

    CHECK(f1.getNumerator() == 2);
    CHECK(f1.getDenominator() == 4);

    CHECK(f2.getNumerator() == 7);
    CHECK(f2.getDenominator() == 3); 
}

TEST_CASE("Check reduce function"){
    Fraction f1(2,4);
    Fraction f2(4,8);

    CHECK_EQ(f2.getDenominator(), 2);
    CHECK_EQ(f1.getNumerator(), 1);
    CHECK_EQ(f1.getDenominator(), f2.getDenominator());
}

TEST_CASE("Check Operators"){
    
    Fraction f1(3, 4);
    Fraction f2(1, 2);

    //check '+'
    Fraction result1 = f1 + f2;
    CHECK_EQ(result1.getNumerator(), 5);
    CHECK_EQ(result1.getDenominator(), 4);

    //check '-'
    Fraction result2 = f1 - f2;
    CHECK_EQ(result2.getNumerator(), 1);
    CHECK_EQ(result2.getDenominator(), 4);

    //check '*'
    Fraction result3 = f1 * f2;
    CHECK_EQ(result3.getNumerator(), 3);
    CHECK_EQ(result3.getDenominator(), 8);

    //check '/'
    Fraction result4 = f1 / f2;
    CHECK_EQ(result4.getNumerator(), 3);
    CHECK_EQ(result4.getDenominator(), 2);

    //check '='
    Fraction f3(6, 8);
    CHECK(f1 == f2);
    CHECK_FALSE(f1 == f3);

    //check bool operations
    Fraction f4(5, 8);
    CHECK(f1 > f2);
    CHECK_FALSE(f1 < f2);
    CHECK(f1 >= f2);
    CHECK(f2 < f4);

    //check '++' and '--'
    Fraction result5 = ++f1;
    CHECK_EQ(result5.getNumerator(), 7);
    CHECK_EQ(result5.getDenominator(), 4);

    result5 = f2++;
    CHECK_EQ(result5.getNumerator(), 1);
    CHECK_EQ(result5.getDenominator(), 2);
    
    result5 = --f1;
    CHECK_EQ(result5.getNumerator(), 5);
}