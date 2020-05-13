// dp-2
// knapsack 
// dp

#include <bits/stdc++.h>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxw) {    
    vector<int> dp(maxw + 1);    
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = maxw; j > 0; j--) {            
            int wt = weights[i];                            
            if(wt <= j)
                dp[j] = max(values[i] + dp[j-wt], dp[j]);
        }
    }
    return dp[maxw];
}

int main(){
  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];
  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }
  for(int i = 0; i < n; i++){
    cin >> values[i];
  }
  int maxWeight;
  cin >> maxWeight;
  cout << knapsack(weights, values, n, maxWeight);
}