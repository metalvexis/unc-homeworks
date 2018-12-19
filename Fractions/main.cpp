/*
    Name: James Paulo J. Saballegue
*/
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <ios>
#include "Fraction.h"
using namespace std;

void testInputMixed(int, int, int);     // test mixed fractions input
void testInput(int, int);               // test proper/improper fractions input
void testAdd( Fraction, Fraction );     // test plus method
void testMultiply( Fraction, Fraction );// test multipliedBy method
void testCompare( Fraction, Fraction ); // test isLessTah
void testFraction( Fraction );          // test Fraction object's data member and methods
void showDataMembers( Fraction );       // display data members of Fraction param
void testMethods( Fraction );           // test all member methods of Fraction param

int main()
{
    testInput( 24 , 86 );

    testInputMixed( 3, 6, 66 );

    testAdd( Fraction(1,3,5), Fraction(2,2,25) );

    testAdd( Fraction(5,3,6), Fraction(7,3,66) );

    testMultiply( Fraction(2,3), Fraction(3,4) );

    testMultiply( Fraction(18,90), Fraction(6,36) );

    testCompare( Fraction(1,3,5), Fraction(2,2,25) );

    testCompare( Fraction(18,90), Fraction(6,36) );

    return 0;
}

void testInputMixed(int whole, int num, int den){
    Fraction fraction( whole, num, den );

    testFraction( fraction );
}

void testInput(int num, int den){
    Fraction fraction( num, den );

    testFraction( fraction );
}

void testAdd( Fraction fraction1, Fraction fraction2 ){

    Fraction sum = fraction1.plus( fraction2 );

    cout << fraction1.toString() << " + " << fraction2.toString() << " = " << sum.toString() << endl;

    showDataMembers(sum);
    testMethods(sum);
}

void testMultiply( Fraction fraction1, Fraction fraction2 ){

    Fraction product = fraction1.multipliedBy( fraction2 );

    cout << fraction1.toString() << " x " << fraction2.toString() << " = " << product.toString() << endl;

    showDataMembers(product);
    testMethods(product);
}

void testCompare( Fraction fraction1, Fraction fraction2 ){
    printf("%s is less than %s == %s\n",
           fraction1.toString().c_str(),
           fraction2.toString().c_str(),
           fraction1.isLessThan(fraction2)?"true":"false");
}

void testFraction( Fraction fraction ){
    showDataMembers( fraction );

    testMethods( fraction );
}

void showDataMembers( Fraction fraction ) {
    printf("Whole: %d | ", fraction.getWhole() );
    printf("Numerator: %d | ", fraction.getNumerator() );
    printf("Denominator: %d\n", fraction.getDenominator() );
}

void testMethods( Fraction fraction ){

    cout << fixed << setprecision(3);
    cout << boolalpha; // booleans to text
    printf("%+12s %-12s \n","isProper ", fraction.isProper()?"true":"false");
    printf("%+12s %-12s \n","isValid ", fraction.isValid()?"true":"false");
    printf("%+12s %-12.4f \n","toDecimal ", fraction.toDecimal() );
    printf("%+12s %-12s \n","toString ", fraction.toString().c_str() );

    if(fraction.getWhole()>0){
        printf("%+12s %-12s \n","simplify ", fraction.simplify().toString().c_str() );
    }else{
        printf("%+12s %-12s \n","reduce ", fraction.reduce().toString().c_str() );
    }
    printf("%+12s %-12s \n","convert ", fraction.convert().toString().c_str() );

    cout << endl;
}
