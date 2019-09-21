// merge sort
// time complexity
	// worst case : n.log n
	// average case :
	// best case :
// space comp : O(n)	
	
#include <bits/stdc++.h>
using namespace std;

void merge(int left[],int right[],int a[]){
	int i=0,j=0,k=0;
	int nl=left.size(),nr=right.size();
	while(i<nl and j<nr){
		if(left[i]<=right[j])
			a[k++]=left[i++];
		else
			a[k++]=right[j++];
	}
	while(i<nl)
		a[k++]=left[i++];
	while(j<nr)
		a[k++]=right[j++];
}

void mergesort(int a[]){
	int n=a.size();
	if(n<2)
		return;
	int mid=n/2;
	int left[mid],right[n-mid];
	for(int i=0;i<mid;i++) left[i]=a[i];       
	for(int i=mid;i<n;i++) right[i-mid]=a[i];  
	mergesort(left);
	mergesort(right);
	merge(left,right,a);
}

void main() {

	int a[5] = { 2,1,5,4,3 };
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	
	mergesort(a);
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	system("pause");
}