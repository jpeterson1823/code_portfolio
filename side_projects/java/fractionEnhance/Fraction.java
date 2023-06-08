import java.lang.Math;

public class Fraction {
    private int num;
    private int den;

    public Fraction() {
        this.num = 0;
        this.den = 1;
    }

    public Fraction(int num, int den) {
        this.num = num;
        this.den = den;
        this.reduce();
    }

    public void setNumerator(int value) {
        this.num = value;
    }

    public int getNumerator() {
        return this.num;
    }

    public void setDenominator(int value) {
        this.den = value;
    }

    public int getDenominator() {
        return this.den;
    }
    
    private void reduce() {
        int gcd = 1;
        int minimum = Math.min(Math.abs(this.num), Math.abs(this.den));
        for (int i = 2; i < minimum + 1; i++) {
            if (this.num % i == 0 && this.den % i == 0)
                gcd = i;
        }
        this.num /= gcd;
        this.den /= gcd;

        if (this.num == 0)
            this.den = 1;
    }

    public double getReal() {
        return (double)this.num / (double)this.den;
    }

    public Fraction add(Fraction f) {
        int num = (this.num * f.getDenominator()) + (f.getNumerator() * this.den);
        int den = (this.den * f.getDenominator());
        return new Fraction(num, den);
    }

    public Fraction sub(Fraction f) {
        int num = (this.num * f.getDenominator()) - (f.getNumerator() * this.den);
        int den = (this.den * f.getDenominator());
        return new Fraction(num, den);
    }

    public Fraction mul(Fraction f) {
        int num = this.num * f.getNumerator();
        int den = this.den * f.getDenominator();
        return new Fraction(num, den);
    }

    public Fraction div(Fraction f) {
        int num = this.num * f.getDenominator();
        int den = this.den * f.getNumerator();
        return new Fraction(num, den);
    }

    public String toString() {
        return this.num + "/" + this.den + " (" + this.getReal() + ")";
    }
}