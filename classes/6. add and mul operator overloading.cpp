// addition and mulitplication operator overloading

#include<bits/stdc++.h>
using namespace std;

class fraction{
    int numerator, denominator;
public:
    fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void print(){
        cout << numerator << "/" << denominator << endl;
    }

    void simplify(){
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    fraction operator+(fraction const &f2) const{
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + (y * f2.numerator);
        fraction fnew(num, lcm);
        fnew.simplify();
        return fnew;
    }
    // these are constant functions that means they can't change
    // the values of the data stored in the object.
    fraction operator*(fraction const &f2) const{
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }
};

int main(){
    fraction f1(10, 2);
    fraction f2(15, 4);
    f1.print();
    f2.print();
    fraction f3 = f1 + f2;	// here f1 is this and f2 is argument.
    f3.print();
    fraction f4 = f1 * f2;
    f4.print();	
}

// output is :
10/2
15/4
35/4
75/4