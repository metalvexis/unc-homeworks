#include "Fraction.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
Fraction::Fraction(int whole, int numerator, int denominator){
    this->whole = whole;
    this->setFraction( numerator, denominator );
}

Fraction::Fraction(int numerator, int denominator){
    this->whole = 0;
    this->setFraction( numerator, denominator );
}

int Fraction::getGCD(int a, int b){
    if (a == 0) return b;
    return Fraction::getGCD(b % a, a);
}

void Fraction::setFraction(int num, int den){
    this->setNumerator( abs(num) );
    this->setDenominator( abs(den) );
}

void Fraction::setWhole(int val){
    this->whole = val;
}

void Fraction::setNumerator(int val){
    this->numerator = val;
}

void Fraction::setDenominator(int val){
    this->denominator = val;
}

double Fraction::toDecimal(){
    double decimal = 0;

    decimal = this->whole;

    if(this->isValid()){
        decimal += (double)this->numerator / (double)this->denominator;
    }

    return decimal;
}

bool Fraction::isValid(){
    bool isValid = this->denominator != 0;
    return isValid;
}

bool Fraction::isProper(){
    return this->denominator > this->numerator;
}

std::string Fraction::toString(){
    std::string strFraction = std::to_string(this->numerator) + "/" +
                            std::to_string(this->denominator);

    if(this->whole > 0){
        strFraction = std::to_string(this->whole) + " " + strFraction;
    }
    return strFraction;
}

Fraction& Fraction::reduce(){
    for (int i = this->denominator * this->numerator; i > 1; i--) {
        if ((this->denominator % i == 0) && (this->numerator % i == 0)) {
            this->denominator /= i;
            this->numerator /= i;
        }
    }
    return *this;
}

Fraction& Fraction::simplify(){
    int gcd = Fraction::getGCD(this->numerator, this->denominator);

    this->denominator /= gcd;
    this->numerator /= gcd;

    return *this;
}


Fraction& Fraction::convert(){
    if( this->whole > 0 ){
        this->numerator += (this->whole * this->denominator);
        this->whole = 0;
        return *this;
    }

    if( !this->isProper() ){
        int rem = this->numerator / this->denominator;

        this->whole = rem;
        this->numerator -= this->numerator % this->denominator;

        return *this;
    }
    return *this;
}

Fraction Fraction::plus( Fraction fraction ){

    // create new Fractions to avoid side effect
    Fraction addendFraction1(this->getWhole(), this->getNumerator(), this->getDenominator());
    Fraction addendFraction2(fraction.getWhole(), fraction.getNumerator(), fraction.getDenominator());

    int gcd = Fraction::getGCD(addendFraction1.getDenominator() ,  addendFraction2.getDenominator());
    int lcm = (addendFraction1.getDenominator() * addendFraction2.getDenominator()) / gcd;

    int sumWhole = addendFraction1.getWhole() + addendFraction2.getWhole();
    int sumNum = ( addendFraction1.getNumerator() * (lcm / addendFraction1.getDenominator()) ) +
                ( addendFraction2.getNumerator() * (lcm / addendFraction2.getDenominator()) );

    if(lcm<sumNum){
        sumWhole += sumNum / lcm;
        sumNum = sumNum%lcm;
    }

    return Fraction(sumWhole, sumNum, lcm);
}

Fraction Fraction::multipliedBy( Fraction fraction ){
    Fraction fraction1(this->getWhole(), this->getNumerator(), this->getDenominator());
    Fraction fraction2(fraction.getWhole(), fraction.getNumerator(), fraction.getDenominator());

    // ensure the fractions are not in Mixed form
    if(fraction1.getWhole()>0){
        fraction1.convert();
    }
    if(fraction2.getWhole()>0){
        fraction2.convert();
    }

    int newNum = fraction1.getNumerator() * fraction2.getNumerator();
    int newDen = fraction1.getDenominator() * fraction2.getDenominator();

    Fraction newFraction( newNum, newDen );

    return newFraction.simplify();
}

bool Fraction::isLessThan( Fraction fraction ){
    Fraction fraction1(this->getWhole(), this->getNumerator(), this->getDenominator());
    Fraction fraction2(fraction.getWhole(), fraction.getNumerator(), fraction.getDenominator());

    int leftOperator = fraction1.toDecimal();
    int rightOperator = fraction2.toDecimal();

    return leftOperator < rightOperator;
}
