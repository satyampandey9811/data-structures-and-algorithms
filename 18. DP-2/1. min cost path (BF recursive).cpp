// dp-2
// min cost path
// brute force recursive

#include <bits/stdc++.h>
using namespace std;

int helper(int **input, int m, int n, int i, int j) {
    if(i == m - 1 and j == n - 1) 
        return input[i][j];
    if(i == m or j == n)
        return INT_MAX;                
    int a = helper(input, m, n, i, j + 1);
    int b = helper(input, m, n, i + 1, j);
    int c = helper(input, m, n, i + 1, j + 1);
    return input[i][j] + min({a, b, c});
}

int minCostPath(int **input, int m, int n) {
	return helper(input, m, n, 0, 0);     
}

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}