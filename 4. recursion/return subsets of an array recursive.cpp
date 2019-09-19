int subset(int input[], int n, int output[][20]) {
    // Write your code here
    if(n==0){
        output[0][0]=0;
         return 1;
    }
    
    int smalloutputsize=subset(input+1,n-1,output);
    int c=0;
    for(int i=0;i<smalloutputsize;i++){
        output[smalloutputsize+i][1]=input[0];
        c++;
        int k=i;
        for(int j=0;j<output[k][0];j++){
            output[smalloutputsize+i][c+1]=output[k][c];
            c++;
        }
        output[smalloutputsize+i][0]=c;
        c=0;
    }
    return smalloutputsize*2;

}