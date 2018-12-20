#include <string>

#ifndef FRACTION_H
#define FRACTION_H


class Fraction
{
    public:
        Fraction(int, int); // numerator, denominator
        Fraction( int, int, int); // whole number, numerator, denominator

        void setFraction(int, int, int);
        void setFraction(int, int);

        int getWhole() { return whole; }
        int getNumerator() { return numerator; }
        int getDenominator() { return denominator; }

        void setWhole(int);
        void setNumerator(int);
        void setDenominator(int);

        double toDecimal();
        std::string toString();

        bool isValid();
        bool isProper();
        bool isMixed();
        
        Fraction& reduce();
        Fraction& simplify();
        Fraction& convert();

        Fraction plus( const Fraction );
        Fraction multipliedBy( const Fraction );
        
        bool isLessThan( const Fraction );
        bool isGreaterThan( const Fraction );
    protected:

    private:
        int whole;
        int numerator;
        int denominator;
        static int getGCD(int, int);
        static int getLCM(int, int);
};

#endif // FRACTION_H
