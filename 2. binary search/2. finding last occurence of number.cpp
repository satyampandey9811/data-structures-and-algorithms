
// array is sorted in increasing order
// to find the last occurence of a number in an array 

#include<bits/stdc++.h>
using namespace std;

int bsearch(vector<int> a, int n, int x){
	int start=0,end=n-1;
	int result=-1;
	while(start<=end){
		if(a[mid]==x){
			result=mid;
			start=mid+1;
		}
		else if(a[mid]<x)
			start=mid+1;
		else
			end=mid-1;
	}
	return result;
}
int main(){
	vector<int> a{2,4,8,10,13,15,19};
	int ans=bsearch(a,7,15);
	if(ans!=-1)cout<<"it is present at index no. : "<<ans;
	else cout<<"number is not found";
}