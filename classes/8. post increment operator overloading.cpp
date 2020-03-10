// post increment operator overloading

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
	// int is used in the argument to differentiate between 
	// pre increment and post increment operators.
	
	// here const function can't be used bcoz we are changing the values of the object.
    fraction operator++(int){		
        fraction fnew(numerator, denominator);
        numerator += denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }
	// here returning is not done by reference bcoz nesting is not allowed on
	// post increment operator. it shows error.so...
};

int main(){
    fraction f1(10, 2);
    f1.print();
    fraction f2 = f1++;
    f1.print();
    f2.print();
}

// output is :
10/2
6/1
5/1