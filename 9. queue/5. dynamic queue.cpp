// dynamic queue 
// also using the concept of templates.

#include<bits/stdc++.h>
using namespace std;

template<typename t>
class queueUsingArray{
	t *data;
	int firstIndex;
	int nextIndex;
	int size;
	int capacity;
	
public:
	
	queueUsingArray(){
		data = new t[5];
		firstIndex = -1;
		nextIndex = 0;
		size = 0;
		capacity = 5;
	}
	
	int getSize(){
		return size;
	}
	
	bool isEmpty(){
		return size == 0;
	}
	
	void enqueue(t element){
		if(size == capacity){
			t *newdata = new t[2 * capacity];
			int j = 0;
			for(int i = firstIndex; i < capacity; i++)
				newdata[j++] = data[i];
			for(int i = 0; i < firstIndex; i++)
				newdata[j++] = data[i];
			firstIndex = 0;
			nextIndex = j;
			capacity *= 2;
			delete [] data;
			data = newdata;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity;
		if(firstIndex == -1)
			firstIndex = 0;
		size++;
	}
			
	t dequeue(){
		if(isEmpty()){
			cout << "queue is empty" << endl;
			return 0;
		}
		t val = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0){
			firstIndex = -1;
			nextIndex = 0;
		}
		return val;
	}
	
	t front(){
		if(isEmpty()){
			cout << "queue is empty" << endl;
			return 0;
		}
		return data[firstIndex];
	}
};
	
int main(){
	
	queueUsingArray<int> q;
	
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	
	cout << q.front() << endl;			// 10
	cout << q.dequeue() << endl;		// 10
	cout << q.dequeue() << endl;		// 20
	cout << q.dequeue() << endl;		// 30
	
	cout << q.getSize() << endl;  		// 3
	cout << q.isEmpty() << endl;		// 0
}			