// static functions in class
// static functions dont have this keyword.

#include<bits/stdc++.h>
using namespace std;

class student{
    static int totalstudents;
public:
    int rollno;   // by default they are non static.
    int age;
    student(){
        totalstudents++;
    }
    static int gettotalstudents(){
        return totalstudents;
    }
	
	// static functions can only contain static data members and function calls for static functions.
	// they show error if non static data member is used or non static function is called.
	// it will show compilation error.
};

int student :: totalstudents = 0;

int main(){
    student s1, s2, s3, s4, s5;
    
	cout << student :: totalstudents << endl; // ERROR
	// cant do this bcoz totalstudents variable is a private data member of the class.
	
	cout << student :: gettotalstudents() << endl;
	
	
}

// output is :
5