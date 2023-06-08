public class Main {
    public static void main(String args[]) {
        Fraction f1 = new Fraction();
        Fraction f2 = new Fraction(5,8);
        Fraction f3 = new Fraction(3, 4);
        Fraction f4 = new Fraction(1, 0);

        f3.setNumerator(5);
        f3.setDenominator(8);
        f1 = f2.add(f3);
        f4.setDenominator(88);
        f2 = f1.sub(f1);
        f3 = f1.mul(f1);
        f4 = f4.div(f3);

        System.out.println("f1: " + f1.toString());
        System.out.println("f2: " + f2.toString());
        System.out.println("f3: " + f3.toString());
        System.out.println("f4: " + f4.toString());
    }
}