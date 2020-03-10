// initialisation list in class

#include<bits/stdc++.h>
using namespace std;

class student{
public:
    const int rollno;
    int age;
    int &x;
    student(int r, int age): rollno(r), age(age), x(this -> age){
        // there are 2 age variables...we want to give the object's age to x.
    }
	// now for different objects we can assign them different rollno.
};

int main(){
    student s1(100, 23);
    cout << s1.rollno << ' ' << s1.age << ' ' << s1.x;
}

// output is:
// 100 23 23

// for constant variables and reference variables, we have to initialise also at the time of declaration..
// but oops removes this problem.