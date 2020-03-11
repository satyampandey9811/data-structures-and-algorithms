// dynamic array with shallow copy concept.

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

    // now for illustrating the concept of shallow copy,
    // we have to use the concept of copy constructor
    // or we can say copy assignment operator.
    // bcoz both use shallow copy

    dynamicarray d2(d1);
    d2.print();
    dynamicarray d3;
    d3 = d1;
    d3.print();
    // Copy constructor is called when a new object is created from an
    // existing object, as a copy of the existing object And
    // assignment operator is called when an already initialized object
    // is assigned a new value from another existing object.

    d1.addelement(0, 100);
    d1.print();
    d2.print();
    d3.print();

    // these three show the same output as they point to the same dynamic array.
    // that's why it is called the shallow copy
    // because one variable of these objects point to the same data
    // and no new memory is created.

    // but in the case of deep copy, new memory is created while
    // using the concept of copy constructor.
}

// output is :
10 20 30 40 50 60
10 20 30 40 50 60
10 20 30 40 50 60
100 20 30 40 50 60
100 20 30 40 50 60
100 20 30 40 50 60