#include "Fraction.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Fraction::Fraction(int whole, int num, int den){
    setFraction( whole, num, den );
}

Fraction::Fraction(int num, int den){
    setFraction( 0, num, den );
}

void Fraction::testPassByRef( Fraction& fraction ) {
    fraction.whole = 9999;
    fraction.numerator = 9999;
    fraction.denominator = 9999;
    cout << "Testing Pass by REF : " << fraction.whole << ", " << fraction.numerator << ", " << fraction.denominator << endl;
}

void Fraction::testPassByVal( Fraction fraction ) {
    fraction.whole = 9999;
    fraction.numerator = 9999;
    fraction.denominator = 9999;
    cout << "Testing Pass by VAL : " << fraction.whole << ", " << fraction.numerator << ", " << fraction.denominator << endl;
}
