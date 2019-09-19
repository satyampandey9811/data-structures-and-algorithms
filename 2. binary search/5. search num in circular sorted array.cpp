// search element in a circular sorted array 
// elements should be distinct

#include<bits/stdc++.h>
using namespace std;
 
int circularArraySearch(vector<int> a, int n, int x){
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(a[mid]==x)                        // case 1 : found x
			return mid;
		if(a[mid]<=a[high]){				 // case 2 : right half is sorted 
			if(a[mid]<x and x <=a[high])
				low=mid+1;					 	// go search in right sorted half
			else
				high=mid-1;					 	// go search in left half
		}
		else {								 // case 3 : left half is sorted
			if(a[low]<=x and x <a[mid])
				high=mid-1;						// go search in left sorted half 
			else
				low=mid+1;						// go search in right half
		}
	}
	return -1;
}
int main(){
	vector<int> a{12,14,18,21,3,6,8,9};
	int x;
	cout<<"Enter any number : ";
	cin>>x;
	int index=circularArraySearch(a,8,x);
	if(index==-1)
		cout<<x<<" not found in the array";
	else
		cout<<x<<" was found at index "<<index;
}