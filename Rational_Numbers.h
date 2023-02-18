#include <iostream>
#include <algorithm>
using namespace std;
class Rational
{
public:
    long long int Numerator;
    long long int Denominator;
    Rational()
    {
    }
    Rational(long long int Num, long long int Denom = 1)
    {
        Numerator = Num;
        Denominator = Denom;
    }
    /*
    Brings the Rational number to the lowest and simpest form
    */
    void simplify()
    {
        long long int gcd = __gcd(Numerator, Denominator);
        while (gcd > 1)
        {
            Numerator = Numerator / gcd;
            Denominator = Denominator / gcd;
            gcd = __gcd(Numerator, Denominator);
        }
    }
    Rational operator+(Rational r2)
    {
        Rational r3(0, 1);
        r3.Numerator = this->Numerator * r2.Denominator + this->Denominator * r2.Numerator;
        r3.Denominator = this->Denominator * r2.Denominator;
        r3.simplify();
        return r3;
    }
    Rational operator*(Rational r2)
    {
        Rational r3(0, 1);
        r3.Numerator = this->Numerator * r2.Numerator;
        r3.Denominator = this->Denominator * r2.Denominator;
        r3.simplify();
        return r3;
    }
    Rational operator-(Rational r2)
    {
        Rational r3(0, 1);
        r3.Numerator = this->Numerator * r2.Denominator - this->Denominator * r2.Numerator;
        r3.Denominator = this->Denominator * r2.Denominator;
        r3.simplify();
        return r3;
    }
    Rational operator/(Rational r2)
    {

        try
        {
            if (r2.Denominator != 0 && this->Denominator != 0)
            {
                Rational r3(0, 1);
                r3.Numerator = this->Numerator * r2.Denominator;
                r3.Denominator = this->Denominator * r2.Numerator;
                r3.simplify();
                return r3;
            }
            else
            {
                throw(0);
            }
        }
        catch (int zero)
        {
            cout << "Not Defined";
            Rational r3(0, 0);
            return r3;
        }
    }
    void print()
    {
        if (Denominator == 1)
        {
            cout << Numerator << endl;
            return;
        }
        cout << Numerator << "/" << Denominator << endl;
    }
};