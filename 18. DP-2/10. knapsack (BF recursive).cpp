// dp-2
// knapsack
// BF recursive

#include <bits/stdc++.h>
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight){
	if(n == 0 or maxWeight < 1) {
        return 0;
    }	
    if(weights[0] > maxWeight)
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    int a = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0]; 
    int b = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    return max(a, b);
}

int main() {
	int n; 
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];
	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}
	for(int i = 0; i < n; i++){
		cin >> values[i];
	}
	int maxWeight;
	cin >> maxWeight;
	cout << knapsack(weights, values, n, maxWeight) << endl;
}