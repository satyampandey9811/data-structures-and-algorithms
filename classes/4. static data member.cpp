// static data member of class

#include<bits/stdc++.h>
using namespace std;

class student{
public:
    int rollno;
    int age;
    static int totalstudents;
	// copies of memory of static data members for different objects are not created.
	// only class template contains the memory for static data members.
	// objects of class doesn't contain memory for static data members.
};

int student :: totalstudents = 0;

int main(){
    student s1;
    cout << s1.rollno << ' ' << s1.age << endl;
    cout << s1.totalstudents << endl;
    cout << student :: totalstudents << endl;
    s1.totalstudents = 20; // no error 
	// on changing the value of static data member using any object, the change appears in the class template. 
    student s2;
    cout << s1.totalstudents << endl; // same value
    cout << s2.totalstudents << endl; // same value
    cout << student :: totalstudents << endl; // same value.
}

// output is :
garbage garbage
0
0
20
20
20