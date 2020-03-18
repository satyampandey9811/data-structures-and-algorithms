// stack
// evaluation of prefix expression using stack

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

int evaluatePrefix(string exp){
	stack<int> s;
	for(int i=exp.length()-1;i>=0;i--){
		if(exp[i]==',') continue;
		if(exp[i]>='0' and exp[i]<='9'){
			int num=exp[i]-'0';
			int j=i-1;
			while(exp[j]!=','){
				num+=(exp[j]-'0')*10;
				j--;
			}
			s.push(num);
		}
		else{
			/* now in stack 1st operand is above 2nd operand and 
			we have to perform (1st operand)operator(2nd operand)*/
			int o1=s.top(); s.pop();
			int o2=s.top(); s.pop();
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
	cout<<"Enter a prefix expression : ";
	getline(cin,expression);
	int ans=evaluatePrefix(expression);
	cout<<"Output = "<<ans;
	return 0;
}

// example is -,+,*,2,3,*,5,4,9
// its output is 17