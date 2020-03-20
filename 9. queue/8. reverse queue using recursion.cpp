#include <iostream>
using namespace std;
#include <queue>

void reverseQueue(queue<int> &q) {	
    if(q.size() < 2)
        return;
    
	int val = q.front();
    q.pop();
	
    reverseQueue(q);
    q.push(val);
}

int main() {
    queue<int> q;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	q.push(val);
    }
    reverseQueue(q);
    while(!q.empty()) {
    	cout << q.front() << " ";
    	q.pop();
    }
}