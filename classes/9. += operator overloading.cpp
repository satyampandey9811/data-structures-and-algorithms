// += operator overloading

// pre increment operator overloading

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
	// here const function can't be used bcoz we are changing the values of the object.
    fraction& operator+=(fraction const &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = numerator * x + ( y * f2.numerator);
        numerator = num;
        denominator = lcm;
        simplify();
        return *this;
    }
	// here if we dont return by reference then the output of 
	// (f1 += f2) += f2 shows as 35/6 instead of 25/3.
};

int main(){
    fraction f1(10, 3);
    fraction f2(5, 2);
    f1.print();
    f2.print();
    (f1 += f2) += f2;   // nesting is done.
    f1.print();
    f2.print();
}

// output is :
10/3
5/2
25/3
5/2