// inbuilt sorting
// time complexity : O(n log n)

#include <bits/stdc++.h>
using namespace std;

void main() {

	int a[5] = { 2,1,5,4,3 };
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	
	sort(a, a + 5);
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	system("pause");
}

	