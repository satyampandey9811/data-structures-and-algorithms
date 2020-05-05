// dp-1
// staircase using dp-1

#include<bits/stdc++.h>
using namespace std;

long staircase(int n){
    long long int a[n + 1] = {0};
    a[0] = 1, a[1] = 1, a[2] = 2;
    for(int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    return a[n];
}

int main(){
  int n; 
  cin >> n ;
  cout << staircase(n) << endl;
}