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

int Fraction::getGCD(int a, int b){
    if (a == 0) return b;
    return Fraction::getGCD(b % a, a);
}

int Fraction::getLCM(int a, int b){
    return (a * b) / Fraction::getGCD(a, b);
}

void Fraction::setFraction(int whole, int num, int den){    
    setWhole( abs(whole) );
    setNumerator( abs(num) );
    setDenominator( abs(den) );
}

void Fraction::setFraction(int num, int den){
    setNumerator( abs(num) );
    setDenominator( abs(den) );
}

void Fraction::setWhole(int val){
    whole = val;
}

void Fraction::setNumerator(int val){
    numerator = val;
}

void Fraction::setDenominator(int val){
    denominator = val;
}

double Fraction::toDecimal(){
    if(!isValid()){
        // short-circuit when invalid
        return 0;
    }
    
    double decimal = whole;
    decimal += (double)numerator / (double)denominator;
    return decimal;   
}

bool Fraction::isValid(){
    bool isValid = denominator != 0;
    return isValid;
}

bool Fraction::isProper(){
    return denominator > numerator;
}

bool Fraction::isMixed(){
    return whole > 0;
}

std::string Fraction::toString(){
    if( !isValid() ){
        // short-circuit when invalid
        return "undefined";
    }
    
    std::string strFraction = "0";
    
    if( numerator > 0 ){
        strFraction = std::to_string(numerator) + "/" +
                    std::to_string(denominator);
    }
    
    if( isMixed() ){
        strFraction = std::to_string(whole) + " " + strFraction;
    }
    
    return strFraction;
}

Fraction& Fraction::reduce(){
    if( !isValid() ){
        // short-circuit when invalid
        return *this;
    }
    
    for (int i = denominator * numerator; i > 1; i--) {
        if ((denominator % i == 0) && (numerator % i == 0)) {
            denominator /= i;
            numerator /= i;
        }
    }
    return *this;
}

Fraction& Fraction::simplify(){
    if( !isValid() ){
        // short-circuit when invalid
        return *this;
    }
    
    int gcd = Fraction::getGCD(numerator, denominator);

    denominator /= gcd;
    numerator /= gcd;

    return *this;
}


Fraction& Fraction::convert(){
    if( !isValid() ){
        // short-circuit when invalid
        return *this;
    }
    
    if( isMixed() ){
        numerator += (whole * denominator);
        whole = 0;
        return *this;
    }

    if( !isProper() ){
        int rem = numerator / denominator;

        whole = rem;
        numerator %= denominator;

        return *this;
    }
    return *this;
}

Fraction Fraction::plus( Fraction fraction ){

    // create new Fractions to avoid side effect
    Fraction addendFraction1(getWhole(), getNumerator(), getDenominator());
    Fraction addendFraction2(fraction.getWhole(), fraction.getNumerator(), fraction.getDenominator());

    int lcm = Fraction::getLCM(addendFraction1.getDenominator(), addendFraction2.getDenominator());
    
    // ensure the fractions are not in Mixed form
    if( addendFraction1.isMixed() ){
        addendFraction1.convert();
    }
    if( addendFraction2.isMixed() ){
        addendFraction2.convert();
    }
    
    int addendNum1 = ( addendFraction1.getNumerator() * (lcm / addendFraction1.getDenominator()) );
    int addendNum2 = ( addendFraction2.getNumerator() * (lcm / addendFraction2.getDenominator()) );
    
    int sumNum =  addendNum1 + addendNum2;

    Fraction newFraction(sumNum, lcm);
    
    return newFraction.simplify();
}

Fraction Fraction::multipliedBy( Fraction fraction ){
    Fraction fraction1(getWhole(), getNumerator(), getDenominator());
    Fraction fraction2(fraction.getWhole(), fraction.getNumerator(), fraction.getDenominator());

    // ensure the fractions are not in Mixed form
    if( fraction1.isMixed() ){
        fraction1.convert();
    }
    if( fraction2.isMixed() ){
        fraction2.convert();
    }

    int newNum = fraction1.getNumerator() * fraction2.getNumerator();
    int newDen = fraction1.getDenominator() * fraction2.getDenominator();

    Fraction newFraction( newNum, newDen );

    return newFraction.simplify();
}

bool Fraction::isLessThan( Fraction fraction ){
    Fraction fraction1(getWhole(), getNumerator(), getDenominator());
    Fraction fraction2(fraction.getWhole(), fraction.getNumerator(), fraction.getDenominator());

    int leftOperator = fraction1.toDecimal();
    int rightOperator = fraction2.toDecimal();

    return leftOperator < rightOperator;
}

bool Fraction::isGreaterThan( Fraction fraction ){
    Fraction fraction1(getWhole(), getNumerator(), getDenominator());
    Fraction fraction2(fraction.getWhole(), fraction.getNumerator(), fraction.getDenominator());

    int leftOperator = fraction1.toDecimal();
    int rightOperator = fraction2.toDecimal();

    return leftOperator > rightOperator;
}
