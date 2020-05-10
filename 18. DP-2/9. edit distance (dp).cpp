// dp-2
// edit distance
// dp

#include<bits/stdc++.h>
using namespace std;

int editDistance(string s, string t){
    int m = s.size(), n = t.size();
	int **dp = new int*[m+1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n+1];        
    }
    for(int j = 0; j <= n; j++) {
		dp[0][j] = j;
    }
    for(int i = 0; i <= m; i++) {
		dp[i][0] = i;
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j-1], dp[i-1][j]});
            }
        }
    }
    
    return dp[m][n];
}

int main(){
  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  cout << editDistance(s1,s2) << endl;
}