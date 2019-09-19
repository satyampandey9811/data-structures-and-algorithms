// stack
// string reversal using stack
// time complexity = O(n)
// space complexity = O(n)

#include<bits/stdc++.h>
#include<stack>					// stack from STL
using namespace std;

/*class Stack{
	private:
		char a[101];
		int top;
	public:						// no need of writing this
		void push(int x);		// stack stl library will do that work
		void pop();
		int Top();
		bool isEmpty();
};*/

void reverse(char c[], int n){		// or char *c
	stack<char> s;
	// loop for push
	for(int i=0;i<n;i++)
		s.push(c[i]);
	// loop for pop
	for(int i=0;i<n;i++){
		c[i]=s.top();			// overwrite the character at index i
		s.pop();				// perform pop
	}	
}

int main(){
	char c[51];
	cout<<"Enter a string : ";
	gets(c);
	reverse(c,strlen(c));
	cout<<"output = "<<c;
	return 0;
}