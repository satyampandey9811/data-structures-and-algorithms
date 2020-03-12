// polynomial class with deep copy concept.

#include<bits/stdc++.h>
using namespace std;

class polynomial{
    int *degcoeff;
    int capacity;
public:
    polynomial(){                       // default constructor
        degcoeff = new int[10];
        capacity = 10;
        for(int i = 0; i < capacity; i++)
            degcoeff[i] = 0;
    }

    polynomial(polynomial const &p){                // copy constructor
        this -> degcoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++)
            this -> degcoeff[i] = p.degcoeff[i];
        this -> capacity = p.capacity;
    }

    void operator=(polynomial const &p){            // copy assignment operator
        this -> degcoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++)
            this -> degcoeff[i] = p.degcoeff[i];
        this -> capacity = p.capacity;
    }

    void print(){                                   // print function
        int c = 0;
        for(int i = 0; i < capacity; i++){
            if(degcoeff[i] == 0)
                continue;
            if(c != 0 and degcoeff[i] > 0)
                cout << "+ ";
            if(i == 0)
                cout << degcoeff[i] << ' ';
            else
                cout << degcoeff[i] << "x^" << i << ' ';
            c++;
        }
        cout << endl;
    }

    void setcoeff(int coeff, int deg){              // setting coefficient function
        if(deg >= capacity){
            int size = 2 * capacity;
            while(size <= deg)
                size *= 2;
            int *newdc = new int[size];
            for(int i = 0; i < size; i++)
                newdc[i] = 0;
            for(int i = 0; i < capacity; i++)
                newdc[i] = degcoeff[i];
            delete [] degcoeff;
            degcoeff = newdc;
            capacity = size;
        }
        degcoeff[deg] = coeff;
    }
    // addition operator overloading - adding two polynomials
    polynomial operator+(polynomial const &p) const{
        polynomial pnew;
        int size = max(this -> capacity, p.capacity);
        int *newdc = new int[size];
        pnew.capacity = size;
        for(int i = 0; i < size; i++)
            newdc[i] = 0;
        int i = 0;
        while(i < this -> capacity and i < p.capacity) {
            newdc[i] = this -> degcoeff[i] + p.degcoeff[i];
            i++;
        }
        while(i < this -> capacity){
            newdc[i] = this -> degcoeff[i];
            i++;
        }
        while(i < p.capacity){
            newdc[i] = p.degcoeff[i];
            i++;
        }
        delete [] pnew.degcoeff;
        pnew.degcoeff = newdc;
        return pnew;
    }
    // subtraction operator overloading - subtracting two polynomials
    polynomial operator-(polynomial const &p) const{
        polynomial pnew;
        int size = max(this -> capacity, p.capacity);
        int *newdc = new int[size];
        pnew.capacity = size;
        for(int i = 0; i < size; i++)
            newdc[i] = 0;
        int i = 0;
        while(i < this -> capacity and i < p.capacity) {
            newdc[i] = this -> degcoeff[i] - p.degcoeff[i];
            i++;
        }
        while(i < this -> capacity){
            newdc[i] = this -> degcoeff[i];
            i++;
        }
        while(i < p.capacity){
            newdc[i] = 0 - p.degcoeff[i];
            i++;
        }
        delete [] pnew.degcoeff;
        pnew.degcoeff = newdc;
        return pnew;
    }
    // mulitplication operator overloading - multiplying two polynomials
    polynomial operator*(polynomial const &p) const{
        polynomial pnew;
        int size = this -> capacity + p.capacity;
        int *newdc = new int[size];
        pnew.capacity = size;
        for(int i = 0; i < size; i++)
            newdc[i] = 0;
        for(int i = 0; i < this -> capacity; i++){
            if(this -> degcoeff[i] == 0)
                continue;
            for(int j = 0; j < p.capacity; j++){
                if(p.degcoeff[j] == 0)
                    continue;
                newdc[i + j] += this -> degcoeff[i] * p.degcoeff[j];
            }
        }
        delete [] pnew.degcoeff;
        pnew.degcoeff = newdc;
        return pnew;
    }
};

int main(){
    polynomial p1;
    p1.setcoeff(3, 2);
    p1.setcoeff(4, 5);
    p1.setcoeff(-1, 7);
    p1.print();
    polynomial p2(p1);
    p2.print();
    p1.setcoeff(5, 2);
    p1.print();
    p2.print();

    p1.setcoeff(3, 2);
    polynomial p3;
    p3 = p1;
    p3.print();
    p1.setcoeff(5, 2);
    p1.print();
    p3.print();

    p1.setcoeff(3, 2);

    polynomial p4;
    p4.setcoeff(2, 1);
    p4.setcoeff(6, 2);
    p4.setcoeff(6, 5);
    p4.print();

    polynomial p5 = p1 + p4;
    p5.print();

    polynomial p6 = p1 - p4;
    p6.print();

    polynomial p7 = p1 * p4;
    p7.print();
}

// output is :
3x^2 + 4x^5 -1x^7
3x^2 + 4x^5 -1x^7
5x^2 + 4x^5 -1x^7
3x^2 + 4x^5 -1x^7
3x^2 + 4x^5 -1x^7
5x^2 + 4x^5 -1x^7
3x^2 + 4x^5 -1x^7
2x^1 + 6x^2 + 6x^5
2x^1 + 9x^2 + 10x^5 -1x^7
-2x^1 -3x^2 -2x^5 -1x^7
6x^3 + 18x^4 + 8x^6 + 42x^7 -2x^8 -6x^9 + 24x^10 -6x^12