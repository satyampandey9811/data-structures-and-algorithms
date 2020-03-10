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
    fraction& operator++(){
        numerator += denominator;
        simplify();
        return *this;
    }
	//funtion is returned as reference to make the object f1 act as the buffer memory.
	// otherwise a new buffer memory would have been created and then its value would 
	// have been copied into the object f2.
	// but now no new memory will be created.
	// whenever we pass a variable by reference as an argument or return by reference,
	// then no new memory is created..instead it points to the same memory.
	
	// nesting is allowed.
};

int main(){
    fraction f1(10, 2);    
	f1.print();
    fraction f2 = ++f1;
    f1.print();
    f2.print();
}

// output is :
10/2
6/1
6/1