#include <iostream>
using namespace std;

#include<stack>
stack<char> s;

bool check(char &b){
    char a = s.top();
    if(a == '(' and b == ')')
        return true;
    else if(a == '{' and b == '}')
        return true;
    else if(a == '[' and b == ']')
        return true;
    return false;
}

bool checkBalanced(char *exp) {

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' or exp[i] == '{' or exp[i] == '[')
            s.push(exp[i]);
        else if(exp[i] == ')' or exp[i] == '}' or exp[i] == ']'){
            if(!s.empty() and check(exp[i])){
                s.pop();
            }
            else
                return false;
        }
    }
    return s.empty();
}

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}