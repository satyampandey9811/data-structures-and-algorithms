// dp-2
// lcs - longest common subsequence
// dp

int lcs(string s, string t, int **dp) {
	int m = s.size(), n = t.size();
	int **dp = new int*[m + 1];
	for(int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];		
	}
	for(int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}
	for(int j = 0; j <= n; j++) {
		dp[0][j] = 0;
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[i - 1] == b[j - 1]) {                        
				dp[i][j] += dp[i - 1][j - 1] + 1;                
			}
			else {                  
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);                
			}
		}
    }
	return dp[m][n];
} 

int main() {
	string s, t;
	cin >> s >> t;	
	cout << lcs(s, t);
	return 0;
}