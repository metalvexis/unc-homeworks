/*
    Name: James Paulo J. Saballegue
*/
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <ios>
#include "Fraction.h"
using namespace std;

int main()
{
    Fraction testFraction1(1,2);
    Fraction testFraction2(3,4);
    Fraction testFraction3(0,1,2);
    Fraction testFraction4(1,1,2);
    
    testFraction1.testPassByRef( testFraction2 );
    testFraction3.testPassByVal( testFraction4 );

    return 0;
}