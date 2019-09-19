int subsetSumToKH(int input[],int size,int temp[],int id,int output[][50],int curr, int k,int& c) {
	// Write your code here
    if(size==curr){
        int sum=0;
        for(int i=0;i<id;i++) sum+=temp[i];
        if(sum==k){
            output[c][0]=id;
            for(int i=0;i<id;i++){
                output[c][i+1]=temp[i];
            }
            c++;
        }    
        return c;
    }
    int a=subsetSumToKH(input, size, temp,id, output, curr + 1, k, c);
    temp[id]=input[curr];
    int b=subsetSumToKH(input, size, temp,id+1, output, curr + 1, k, c);
    return c;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    int temp[100];int c=0;
    return subsetSumToKH(input,n,temp,0,output,0,k,c)+1;
}