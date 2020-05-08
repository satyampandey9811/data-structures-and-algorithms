// dp-2
// lcs - longest common subsequence
// BF recursive

int lcs(string s, string t) {
	if(s.size() == 0 or t.size() == 0)
		return 0;
	if(s[0] == t[0])
		return 1 + lcs(s.substr(1), t.substr(1));
	
	int a = lcs(s.substr(1), t);
	int b = lcs(s, t.substr(1));
	int c = lcs(s.substr(1), t.substr(1));
	return max({a, b, c});
} 

int main() {
	string s, t;
	cin >> s >> t;
	cout << lcs(s, t);
	return 0;
}