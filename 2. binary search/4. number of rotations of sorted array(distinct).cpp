
// finding how many times is a sorted array rotated 
// there should be no duplicates in the array
// this is a circular sorted array
// examples for this problem are 1. {15,10} and 2. {5,10,2}
// array is rotated anti clockwise

#include<bits/stdc++.h>
using namespace std;

int findRotationCount(vector<int> nums,int n){
	int ans = 0;
	int low = 0, high = n - 1, mid;
	while(low <= high){
		mid = low + (high - low) / 2;            
		if(nums[mid] >= nums[0])
			low = mid + 1;
		else {
			if(mid < 1) break;
			if(nums[mid] > nums[mid - 1])
				high = mid - 1;
			else{
				ans = mid;
				break;
			}
		}
	}
	return ans;
}

int main(){
	vector<int> a{15,22,23,28,31,38,5,6,8,10,12};
	int count=findRotationCount(a,11);
	cout<<"The array is rotated "<<count<<" times";
}