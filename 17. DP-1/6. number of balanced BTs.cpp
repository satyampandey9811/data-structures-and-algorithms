// dp-1
// number of balanced BTs

#include <bits/stdc++.h>
using namespace std;

int balancedBTs(int h) {
    int v[h+1] = {-1};	
    v[0] = v[1] = 1;
    const int m = 1e9 + 7;
    
    for(int i = 2; i <= h; i++) {
    	int x = (1LL * (v[i-1] % m) * (v[i-1] % m)) % m;
    	int y = (1LL * (v[i-1] % m) * (v[i-2] % m)) % m;
    	y *= 2;
    	y %= m;        
	    v[i] = (x + y) % m;
    }
    return v[h];
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}