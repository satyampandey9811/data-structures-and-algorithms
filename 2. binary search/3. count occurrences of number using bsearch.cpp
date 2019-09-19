
// count occurrences of a number in a sorted array with duplicates using binary search
// array is increasingly sorted 

#include<bits/stdc++.h>
using namespace std;

int bsearch(vector<int> a,int n,int x,bool flag){

	int low=0,high=n-1;
	int result=-1;
	while(low<=high){
		int mid=low + (high-low)/2;
		if(a[mid]==x){
			result=mid;
			if(flag)
				high=mid-1;
			else
				low=mid+1;
		}
		else if(a[mid]<x)
			low=mid+1;
		else
			high=mid-1;
	}
	return result;
}

int main(){
	vector<int> a{1,1,3,3,5,5,5,5,5,9,9,11};
	int x;
	cout<<"enter a number to find its count : ";
	cin>>x;
	int firstindex=bsearch(a,12,x,true);
	if(firstindex==-1){
		cout<<"count of "<<x<<" is 0";
	}
	else{
		int lastindex=bsearch(a,12,x,false);
		cout<<"count of "<<x<<" is "<<lastindex-firstindex+1;
	}
}
	