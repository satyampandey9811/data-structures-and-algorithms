#include<vector>

void printSubsetSumToKH(int input[], int size, vector<int>& output, int curr, int k) {
	// Write your code here
    if(size==curr){
        int sum=0;
        for(auto x: output) sum+=x;
        if(sum==k){
            for(auto x:output) cout<<x<<' ';
            cout<<endl;
        }    
        return;
    }
    printSubsetSumToKH(input, size, output, curr + 1, k);
    output.push_back(input[curr]);
    printSubsetSumToKH(input, size, output, curr + 1, k);
    output.pop_back();
    
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int> output;
    printSubsetSumToKH(input,size,output,0,k);
}