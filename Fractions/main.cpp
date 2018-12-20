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
void testAdd( Fraction, Fraction);     // test plus method
void testMultiply(Fraction, Fraction);// test multipliedBy method
void testLessThan(Fraction, Fraction); // test isLessThan
void testGreaterThan(Fraction, Fraction); // test isGreaterThan
void testFraction(Fraction);          // test Fraction object's data member and methods
void showDataMembers(Fraction);       // display data members of Fraction param
void testMethods(Fraction);           // test all member methods of Fraction param

int main()
{
    testInputMixed( 2, 0, 0 );
    testInput( 2, 0 );
    testInput( 0, 2 );

    Fraction testFraction1(1,2);
    Fraction testFraction2(3,4);
    
    Fraction testFraction3(0,1,2);
    Fraction testFraction4(1,1,2);
    Fraction testFraction5(2,1,2);
    
    Fraction testFraction6(0,3,2);
    Fraction testFraction7(1,3,2);
    Fraction testFraction8(2,3,2);

    testAdd( testFraction1, testFraction2 );
    testAdd( testFraction3, testFraction4 );
    
    testMultiply( testFraction1, testFraction2 );
    testMultiply( testFraction3, testFraction4 );
    
    testLessThan( testFraction1, testFraction2 );
    testLessThan( testFraction3, testFraction4 );
    
    testGreaterThan( testFraction1, testFraction2 );
    testGreaterThan( testFraction3, testFraction4 );

    

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

    printf("%8s + %-8s == %-8s\n",
        fraction1.toString().c_str(),
        fraction2.toString().c_str(),
        sum.toString().c_str() );
        
//    cout << fraction1.toString() << " + " << fraction2.toString() << " = " << sum.toString() << endl;

//    showDataMembers(sum);
//    testMethods(sum);
}

void testMultiply( Fraction fraction1, Fraction fraction2 ){

    Fraction product = fraction1.multipliedBy( fraction2 );
    
    printf("%8s x %-8s == %-8s\n",
        fraction1.toString().c_str(),
        fraction2.toString().c_str(),
        product.toString().c_str() );

//    cout << fraction1.toString() << " x " << fraction2.toString() << " = " << product.toString() << endl;

//    showDataMembers(product);
//    testMethods(product);
}

void testLessThan( Fraction fraction1, Fraction fraction2 ){
    printf("%8s < %-8s == %-8s\n",
        fraction1.toString().c_str(),
        fraction2.toString().c_str(),
        fraction1.isLessThan(fraction2)?"true":"false");
}

void testGreaterThan( Fraction fraction1, Fraction fraction2 ){
    printf("%8s > %-8s == %-8s\n",
        fraction1.toString().c_str(),
        fraction2.toString().c_str(),
        fraction1.isGreaterThan(fraction2)?"true":"false");
}

void testFraction( Fraction fraction ){
    showDataMembers( fraction );

    testMethods( fraction );
}

void showDataMembers( Fraction fraction ) {
    printf("Whole: %d | Numerator: %d | Denominator: %d\n",
        fraction.getWhole(),
        fraction.getNumerator(),
        fraction.getDenominator()
    );
}

void testMethods( Fraction fraction ){

    cout << fixed << setprecision(3);
    cout << boolalpha; // booleans to text
    
    printf("%12s %-12s \n","isValid ", 
        fraction.isValid()?"true":"false");
        
    printf("%12s %-12s \n","isProper ", 
        fraction.isProper()?"true":"false");
    
    printf("%12s %-12s \n","isMixed ", 
        fraction.isMixed()?"true":"false");
        
    printf("%12s %-12.4f \n","toDecimal ", 
        fraction.toDecimal() );
        
    printf("%12s %-12s \n","toString ", 
        fraction.toString().c_str() );
        
    printf("%12s %-12s \n","simplify ", 
        fraction.simplify().toString().c_str() );
        
    printf("%12s %-12s \n","reduce ", 
        fraction.reduce().toString().c_str() );
        
    printf("%12s %-12s \n","convert ", 
        fraction.convert().toString().c_str() );

    cout << endl;
}
