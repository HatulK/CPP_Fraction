#include "sources/Fraction.hpp"
#include "doctest.h"
namespace ariel{
TEST_CASE("test1") {
    //Check that the fraction is legal
    CHECK_NOTHROW(Fraction(0, 1));
    CHECK_THROWS(Fraction(0, 0));
    CHECK_THROWS(Fraction(1, 0));

    Fraction f1(1, 1);// 1
    Fraction f12(1,2);// 1/2
    Fraction f2(1, 2);// 1/2
    CHECK(((f1+f2)==1.5));//Plus operation
    CHECK((1.5==(f2+f1)));//Plus operation
    CHECK((0.5==f1-f2));//Minus operation
    CHECK((-0.5==f2-f1));//Minus operation
    CHECK((0.5==(f1*f2)));//Multiplication operation
    CHECK((0.5==f2*f1));//Multiplication operation
    CHECK((0.5==f1/f2));//Divide operation
    CHECK((2==f2/f1));//Divide operation

    CHECK((f12==f2));// == operation
    CHECK((!(f1==f2)));// == operation
    CHECK(((f1!=f2)));// != operation
    CHECK(!((f1!=f12)));// != operation

    CHECK((f2<f1));// < operation
    CHECK(!(f1<f2)); // < operation
    CHECK((f1>f2));// > operation
    CHECK(!(f2>f1)); // > operation
    CHECK((f2<=f1));// <= operation
    CHECK(!(f1<=f2)); // <= operation
    CHECK((f1<=f1));// <= operation
    CHECK((f1>=f2));// >= operation
    CHECK(!(f2>=f1)); // >= operation
    CHECK((f1>=f1));// >= operation

    CHECK((1.5==(f1+=f2)));// += operation
    CHECK((0.5==(f1-=f2)));// -= operation
    CHECK(((1/4)==(f1*=f1)));// *= operation
    CHECK(((1/2)==(f2/=f1)));// /= operation

    CHECK((2==f1++));
    CHECK((0==f1--));

    CHECK_THROWS((f1/0.0));
    CHECK_THROWS((f1/=0.0));

}
}