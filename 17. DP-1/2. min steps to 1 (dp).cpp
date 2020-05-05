// dp-1
// min steps to 1
// dp - bottom up approach

#include<bits/stdc++.h>
using namespace std;

int countStepsTo1(int n){
 	vector<int> ans(n + 1);
    int a, b, c;
    for(int i = 2; i <= n; i++) {        
        a = i % 2 ?1e9 :ans[i/2];
        b = i % 3 ?1e9 :ans[i/3];
        c = ans[i-1];
        ans[i] = 1 + min({a,b,c});
    }
    return ans[n];
}

int main(){
  int n;
  cin  >> n;
  cout << countStepsTo1(n) << endl;
}