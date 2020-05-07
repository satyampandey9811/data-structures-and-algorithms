// dp-2
// min cost path
// memoization

#include <bits/stdc++.h>
using namespace std;

int helper(int **input, int m, int n, int i, int j, int **ans) {
    if(i == m - 1 and j == n - 1) 
        return input[i][j];
    if(i == m or j == n)
        return INT_MAX;                
    if(ans[i][j] != -1)
        return ans[i][j];
    int a = helper(input, m, n, i, j + 1, ans);
    if(a < INT_MAX) 
        ans[i][j + 1] = a;
    int b = helper(input, m, n, i + 1, j + 1, ans);
    if(b < INT_MAX) 
        ans[i + 1][j + 1] = b;
    int c = helper(input, m, n, i + 1, j, ans);
    if(c < INT_MAX)
        ans[i + 1][j] = c;
    ans[i][j] = input[i][j] + min({a, b, c});
    return ans[i][j];
}

int minCostPath(int **input, int m, int n) {
    int **ans = new int*[n];
    for(int i = 0; i < n; i++) {
        ans[i] = new int[m];
        for(int j = 0; j < n; j++) {
            ans[i][j] = -1;
        }
    }    
	return helper(input, m, n, 0, 0, ans);     
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