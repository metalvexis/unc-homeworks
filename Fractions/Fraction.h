#include <string>

#ifndef FRACTION_H
#define FRACTION_H


class Fraction
{
    protected:
    private:
        int whole;
        int numerator;
        int denominator;
        static int getGCD(int, int);
        static int getLCM(int, int);
    public:
        Fraction(int, int); // numerator, denominator
        Fraction( int, int, int); // whole number, numerator, denominator
        
        void testPassByRef ( Fraction& );
        void testPassByVal ( Fraction );
    

    
};

#endif // FRACTION_H
