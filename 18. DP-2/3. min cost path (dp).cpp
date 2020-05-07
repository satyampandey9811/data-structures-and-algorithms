// dp-2
// min cost path
// dp

#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **a, int m, int n) {    
    for(int i = 1; i < m; i++) {
        a[i][0] += a[i - 1][0];
    }
	for(int j = 1; j < n; j++) {
        a[0][j] += a[j - 1][0];
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            a[i][j] += min({a[i-1][j-1], a[i][j-1], a[i-1][j]});
        }
    }
    return a[m-1][n-1];
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