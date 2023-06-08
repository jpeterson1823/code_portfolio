#include <string>
using namespace std;

class Fraction {
    private:
    int num;
    int den;

    public:
    Fraction(int num, int den);
    int getNumerator();
    int getDenominator();
    void reduce();
    string toString();
    Fraction operator + (Fraction);
    Fraction operator - (Fraction);
    Fraction operator * (Fraction);
    Fraction operator / (Fraction);
    Fraction operator += (Fraction);
    Fraction operator -= (Fraction);
    Fraction operator *= (Fraction);
    Fraction operator /= (Fraction);
    bool operator == (Fraction);
    bool operator <= (Fraction);
    bool operator >= (Fraction);
};