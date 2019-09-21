// bubblesort
// time complexity
	// worst case : n^2
	// average case : n^2
	// best case : n
// space comp : O(1)
	
#include <bits/stdc++.h>
using namespace std;

void bubblesort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int flag=0;
		for (int j = 0; j < n - 1 - i; j++) {  
			if (a[j] > a[j + 1]){              
				swap(a[j], a[j + 1]);
				flag=1;
			}
		}
		if(flag==0) break;
	}	
}

void main() {

	int a[5] = { 2,1,5,4,3 };
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	
	bubblesort(a,5);
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	system("pause");
}