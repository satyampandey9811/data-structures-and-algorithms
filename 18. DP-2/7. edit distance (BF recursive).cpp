// dp-2
// edit distance
// BF recursive

#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t){
	if(s.size() == 0) return t.size();
    if(t.size() == 0) return s.size();
    if(s[0] == t[0])
        return editDistance(s.substr(1), t.substr(1));
	int a = editDistance(s, t.substr(1));
    int b = editDistance(s.substr(1), t.substr(1));
    int c = editDistance(s.substr(1), t);
    return 1 + min({a, b, c});
}

int main(){
  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  cout << editDistance(s1,s2) << endl;
}