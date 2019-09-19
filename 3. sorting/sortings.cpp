//  All 5 sortings 

#include <bits/stdc++.h>
using namespace std;
// bubblesort
void bubblesort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int flag=0;
		for (int j = 0; j < n - 1 - i; j++) {  // time comp : O(n^2)
			if (a[j] > a[j + 1]){              // space comp : O(1)
				swap(a[j], a[j + 1]);
				flag=1;
			}
		}
		if(flag==0) break;
	}	
}
// selectionsort
void selectionsort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = min_element(a+i, a + n)-a;     // time comp : O(n^2)
		swap(a[i], a[j]);					   // space comp : O(1)
	}
}
// insertionsort
void insertionsort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int value= a[i];
		int pos=i;
		while(pos>0 and a[pos-1]>value){	   // time comp : O(n^2)
			a[pos]=a[pos-1];				   // space comp : O(1)
			pos--;
		}
		a[pos]=value;
	}
}
// merge sort
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
	for(int i=0;i<mid;i++) left[i]=a[i];       // time comp : O(n.logn)
	for(int i=mid;i<n;i++) right[i-mid]=a[i];  // space comp : O(n)
	mergesort(left);
	mergesort(right);
	merge(left,right,a);
}

//quicksort
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
	int pindex=randomizedPartition(a,start,end);  	// time comp : O(n.logn)
	quicksort(a,start,pindex-1);					// space comp : average case : O(log n)
	quicksort(a,pindex+1,end);						// 				worst case : O(n)  which's probability is zero though
}

void main() {

	int a[5] = { 2,1,5,4,3 };
	
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	// bubblesort(a,5);
	// selectionsort(a,5);
	// insertionsort(a, 5);
	// mergesort(a);
	// quicksort(a,0,5);
	// sort(a, a + 5);
	for (auto x : a)
		cout << x << ' ';
	cout << endl;
	system("pause");
}

/* time complexity
	
selection sort ( same for all )
	worst case : n^2
	average case : n^2
	best case : n^2

bubble sort
	worst case : n^2
	average case : n^2
	best case : n
	
insertion sort
	worst case : n^2
	average case : n^2
	best case : n
	
merge sort
	worst case : n.log n
	average case :
	best case :
	
quick sort
	worst case : n^2 ( negligible )
	average case : n.log n
	best case :
	