// priority queue
// in-place heap sort

#include <bits/stdc++.h>
using namespace std;

void inplaceHeapSort(int a[], int n){
    int ci, pi, li, ri;
    n--;
    
    for(int i = 1; i <= n; i++){        
        ci = i;                
        while(ci > 0){
            pi = (ci - 1) / 2;
            if(a[ci] < a[pi])
                swap(a[ci], a[pi]);
            else
                break;
            ci = pi;
        }
    }    
    
    for(int i = n; i > 0; i--){
        swap(a[i], a[0]);
        pi = 0, li = 1, ri = 2;
        while(ri <= i){
            if(ri == i and a[pi] > a[li]){
                swap(a[pi], a[li]);
                pi = li;
            }
            else if(ri < i and a[pi] > min(a[li], a[ri])){
                if(a[li] < a[ri]){
                    swap(a[pi], a[li]);
                    pi = li;
                }
                else{
                    swap(a[pi], a[ri]);
                    pi = ri;
                }
            }
            else
                break;
            li = 2 * pi + 1;
            ri = 2 * pi + 2;
        }           
    }
}

int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
	
	return 0;
}