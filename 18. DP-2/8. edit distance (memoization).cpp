// dp-2
// edit distance
// memoization

#include<bits/stdc++.h>
using namespace std;

int editDistance(string s, string t, int **dp) {
    int m = s.size(), n = t.size();
    if(m == 0) return n;
    if(n == 0) return m;
    
    if(dp[m][n] != -1)
        return dp[m][n];
    if(s[0] == t[0]) {
        dp[m-1][n-1] = editDistance(s.substr(1), t.substr(1), dp);
        dp[m][n] = dp[m-1][n-1];
    }
    else {
		dp[m][n-1] = editDistance(s, t.substr(1), dp);
    	dp[m-1][n-1] = editDistance(s.substr(1), t.substr(1), dp);
    	dp[m-1][n] = editDistance(s.substr(1), t, dp);
        dp[m][n] = 1 + min({dp[m][n-1], dp[m-1][n-1], dp[m-1][n]});
    }
    return dp[m][n];
}

int editDistance(string s, string t){
    int m = s.size(), n = t.size();
	int **dp = new int*[m+1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n+1];
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    return editDistance(s, t, dp);
}

int main(){
  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  cout << editDistance(s1,s2) << endl;
}