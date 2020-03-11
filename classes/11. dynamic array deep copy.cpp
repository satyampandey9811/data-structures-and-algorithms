// dynamic array with deep copy concept.

#include<bits/stdc++.h>
using namespace std;

class dynamicarray{
    int *data;
    int nextindex;
    int capacity;
public:
    dynamicarray(){
        data = new int[5];
        nextindex = 0;
        capacity = 5;
    }

    dynamicarray(dynamicarray const &d){
        this -> data = new int[d.capacity];
        for(int i = 0; i < d.nextindex; i++)
            this -> data[i] = d.data[i];
        this -> nextindex = d.nextindex;
        this -> capacity = d.capacity;
    }

    void operator=(dynamicarray const &d){
        this -> data = new int[d.capacity];
        for(int i = 0; i < d.nextindex; i++)
            this -> data[i] = d.data[i];
        this -> nextindex = d.nextindex;
        this -> capacity = d.capacity;
    }

    void add(int element){
        if(nextindex == capacity){
            int *newdata = new int[2 * capacity];
            for(int i = 0; i < capacity; i++)
                newdata[i] = data[i];
            delete [] data;
            data = newdata;
            capacity *= 2;
        }
        data[nextindex] = element;
        nextindex++;
    }

    void addelement(int i, int element){
        if(i < nextindex)
            data[i] = element;
        else if(i == nextindex)
            add(element);
        else return;
    }

    void print(){
        for(int i = 0; i < nextindex; i++)
            cout << data[i] << ' ';
        cout << endl;
    }
};

int main(){
    dynamicarray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();

    // now for illustrating the concept of deep copy, we have
    // created copy constructors and assignment operator overloading

    dynamicarray d2(d1);
    d2.print();

    d1.addelement(0, 100);
    d1.print();
    d2.print();

    dynamicarray d3;
    d3.print();                             // shows total blankness.
    d1.addelement(0, 10);

    /*
    without using the assignment operator overloading,

    d3 = d1;
    d1.addelement(0, 100);
    d1.print();                             prints 100 20 30 40 50 60
    d3.print();                             prints 100 20 30 40 50 60

    these two show the same output bcoz this is inbuilt copy
    assignment operator and it uses shallow copy.
    */

    // now after using the assignment operator overloading,

    d3 = d1;
    d1.addelement(0, 100);
    d1.print();                            // prints 100 20 30 40 50 60
    d3.print();                            // prints 10 20 30 40 50 60

    // these three different outputs as they point to the different dynamic arrays.
    // that's why it is called the deep copy
    // because one variable of these objects point to the different data
    // and new memories are created.
}

// output is :
10 20 30 40 50 60
10 20 30 40 50 60
100 20 30 40 50 60
10 20 30 40 50 60

100 20 30 40 50 60
10 20 30 40 50 60
