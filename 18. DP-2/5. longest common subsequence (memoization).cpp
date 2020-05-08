// dp-2
// lcs - longest common subsequence
// memoization

int lcs(string s, string t, int **dp) {
	if(s.size() == 0 or t.size() == 0)
		return 0;
	int m = s.size(), n = t.size();
	if(dp[m][n] != -1)
		return dp[m][n];
	if(s[0] == t[0]) {
		dp[m - 1][n - 1] = lcs(s.substr(1), t.substr(1), dp);
		dp[m][n] = 1 + dp[m - 1][n - 1];		
	}
	else {
		dp[m - 1][n] = lcs(s.substr(1), t, dp);
		dp[m][n - 1] = lcs(s, t.substr(1), dp);	
		dp[m][n] =  max(dp[m - 1][n], dp[m][n - 1]);
	}
	return dp[m][n];
} 

int main() {
	string s, t;
	cin >> s >> t;
	int m = s.size(), n = t.size();
	
	int **dp = new int*[m + 1];
	for(int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
		for(int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	cout << lcs(s, t, dp);
	return 0;
}