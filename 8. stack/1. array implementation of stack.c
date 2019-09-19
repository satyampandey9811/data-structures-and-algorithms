// stack
// array based implementation

#include<stdio.h>
#define max_size 101
int a[max_size];
int top=-1;

void push(int x){
	if(top==max_size-1){
		printf("Error : Stack overflow\n");
		return;
	}
	a[++top]=x;
}

void pop(){
	if(top==-1){
		printf("Error : no element to pop\n");
		return;
	}
	--top;
}

int Top(){
	return a[top];
}

void print(){
	printf("Stack : ");
	int i;
	for(i=0;i<=top;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main(){
	push(2); print();
	push(4); print();
	push(6); print();
	pop(); print();
	push(8); print();
	return 0;
}
