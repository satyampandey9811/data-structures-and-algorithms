// dp-1
// minimum count 
// memoization

#include<bits/stdc++.h>
using namespace std;

vector<int> a;

int helper(int n) {
    if(n == 1) 
        return 1;
    if(a[n] != -1)
        return a[n];
    int c, ans = INT_MAX;
  	for(int i = 1; i * i <= n; i++) {
        c = 1 + helper(n - i * i);
        ans = min(ans, c);
    }  
    a[n] = ans;
    return a[n];
}

int minCount(int n){
    a.resize(n + 1, -1);
    a[0] = 0, a[1] = 1;
    return helper(n);
}

int main(){
    int num;
    cin >> num;
    cout << minCount(num);   
}