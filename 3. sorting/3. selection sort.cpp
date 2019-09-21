// selectionsort
// time complexity
	// worst case : n^2
	// average case : n^2
	// best case : n^2
// space comp : O(1)
	
#include <bits/stdc++.h>
using namespace std;

void selectionsort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = min_element(a+i, a + n)-a; 
		swap(a[i], a[j]);					   
	}
}

void main() {

	int a[5] = { 2,1,5,4,3 };
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	
	selectionsort(a,5);
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	system("pause");
}	