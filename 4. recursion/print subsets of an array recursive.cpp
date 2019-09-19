#include<vector>

void printSubsetsOfArrayH(int input[], int size, vector<int>& output, int curr) {
	// Write your code here
    if(size==curr){
        for(auto x: output) cout << x <<' ';
        cout <<'\n';
        return;
    }
    printSubsetsOfArrayH(input, size, output, curr + 1);
    output.push_back(input[curr]);
    printSubsetsOfArrayH(input, size, output, curr + 1);
    output.pop_back();    
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    vector<int> output;
    printSubsetsOfArrayH(input, size, output, 0);    
}
