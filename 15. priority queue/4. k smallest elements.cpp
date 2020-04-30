// priority queue
// k smallest elements

#include<bits/stdc++.h>
using namespace std;

vector<int> kSmallest(int *input, int n, int k) {
    vector<int> ans;
	priority_queue<int> p;
    for(int i = 0; i < k; i++){
        p.push(input[i]);
    }
  	for(int i = k; i < n; i++){
		if(input[i] < p.top()){
            p.pop();
            p.push(input[i]);
        }
    }  
    while(!p.empty()){
        ans.push_back(p.top());
        p.pop();
    }
    return ans;
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	vector<int> output = kSmallest(input, n, k);
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}
}