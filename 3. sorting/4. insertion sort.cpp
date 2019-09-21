// insertionsort
// time complexity
	// worst case : n^2
	// average case : n^2
	// best case : n
// space comp : O(1)
	
#include <bits/stdc++.h>
using namespace std;

void insertionsort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int value= a[i];
		int pos=i;
		while(pos>0 and a[pos-1]>value){	   
			a[pos]=a[pos-1];				   
			pos--;
		}
		a[pos]=value;
	}
}

void main() {

	int a[5] = { 2,1,5,4,3 };
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;

	insertionsort(a, 5);
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	system("pause");
}