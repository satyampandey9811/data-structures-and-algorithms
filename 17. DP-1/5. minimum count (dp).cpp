// dp-1
// minimum count
// dp

#include<bits/stdc++.h>
using namespace std;

int minCount(int n){
    vector<int> a(n + 1);
    a[1] = 1;    
    
    for(int i = 2; i <= n; i++) {
        int c, ans = INT_MAX;
        for(int j = 1; j * j <= i; j++) {
        	c = 1 + a[i - j * j];            
        	ans = min(ans, c);
    	}
        a[i] = ans;
    }
    return a[n];
}

int main(){
    int num;
    cin >> num;
    cout << minCount(num);   
}