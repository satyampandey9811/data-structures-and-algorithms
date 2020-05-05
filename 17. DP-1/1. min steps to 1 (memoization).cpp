// dp-1
// min steps to 1
// memoization - top down approach

#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

int helper(int n){
    if(n == 1) return 0;
    if(ans[n] != -1) return ans[n];
    
    int a = 1e9, b = 1e9, c;
    
    if(n % 2 == 0) a = helper(n / 2);
    if(n % 3 == 0) b = helper(n / 3);
    c = helper(n - 1);
    
    ans[n] = 1 + min({a, b, c});
    return ans[n];
}

int countStepsTo1(int n){
 	ans.resize(n + 1, -1);
    return helper(n);
}

int main(){
  int n;
  cin  >> n;
  cout << countStepsTo1(n) << endl;
}