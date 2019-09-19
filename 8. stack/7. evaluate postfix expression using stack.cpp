// stack
// evaluation of postfix expression using stack

#include<bits/stdc++.h>
#include<stack>
using namespace std;

int performOperation(char a,int x,int y){
	int res;
	if(a=='+') res=x+y;
	else if(a=='-') res=x-y;
	else if(a=='*') res=x*y;
	else if(a=='/') res=x/y;
	return res;
}

int evaluatePostfix(string exp){
	stack<int> s;
	for(int i=0;i<exp.length();i++){
		if(exp[i]==',') continue;
		if(exp[i]>='0' and exp[i]<='9'){
			int num=exp[i]-'0';
			int j=i+1;
			while(exp[j]!=','){
				num=(num*10)+(exp[j]-'0');
				j++;
			}
			s.push(num);
		}
		else{
			/* in stack 2nd operand is above 1st operand and 
			we have to perform (1st operand)operator(2nd operand)*/
			int o2=s.top(); s.pop();
			int o1=s.top(); s.pop();
			int res=performOperation(exp[i],o1,o2);
			s.push(res);
		}
	}
	int ans=s.top();
	s.pop();
	return ans;
}

int main(){
	string expression;
	cout<<"Enter a postfix expression : ";
	getline(cin,expression);
	int ans=evaluatePostfix(expression);
	cout<<"Output = "<<ans;
	return 0;
}

// example is 2,3,*,5,4,*,+,9,-
// its output is 17