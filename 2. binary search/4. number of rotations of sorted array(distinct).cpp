
// finding how many times is a sorted array rotated 
// there should be no duplicates in the array
// this is a circular sorted array
// examples for this problem are 1. {15,10} and 2. {5,10,2}
// array is rotated anti clockwise

#include<bits/stdc++.h>
using namespace std;

int findRotationCount(vector<int> a,int n){
	int low=0,high=n-1;
	while(low<=high){
		if(a[low]<=a[high])   // case 1
			return low;
		int mid=low+(high-low)/2;
		int next=(mid+1)%n , prev=(mid-1+n)%n;
		if(a[mid]<=a[next] and a[mid]<=a[prev])   // case 2
			return mid;
		else if(a[mid]<=a[high])   // case 3
			high=mid-1;
		else if(a[mid]>=a[low])   // case 4
			low=mid+1;
	}
	return -1;
}

int main(){
	vector<int> a{15,22,23,28,31,38,5,6,8,10,12};
	int count=findRotationCount(a,11);
	cout<<"The array is rotated "<<count<<" times";
}