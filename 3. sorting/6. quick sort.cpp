//quicksort
// time complexity
	// worst case : n^2 ( negligible )
	// average case : n.log n
	// best case :
// space complexity
	// average case : O(log n)	
	// worst case : O(n)  whose probability is zero though
	
#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int start, int end){
	int pivot=a[end];
	int pindex=start;				// set partition index as start initially
	for(int i=0;i<end;i++){
		if(a[i]<=pivot){
			swap(a[i],a[pindex];	// swap if element is lesser than pivot
			pindex++;
		}
	}
	swap(a[end],a[pindex]);			// swap pivot with element at pivot index
	return pindex;
}
void randomizedPartition(int a[],int start , int end){	// this function will reduce the probability of worst case to 0
	pindex=random(start,end);
	swap(a[pindex],a[end]);
	partition(a,start,end);
}
void quicksort(int a[],int start, int end){
	if(start>=end)
		return;
	int pindex=randomizedPartition(a,start,end);  	
	quicksort(a,start,pindex-1);					
	quicksort(a,pindex+1,end);						
}

void main() {

	int a[5] = { 2,1,5,4,3 };
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	
	quicksort(a,0,5);
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	system("pause");
}