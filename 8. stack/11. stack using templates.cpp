// stack using templates 
// using dynamic array

template<typename t>

class stackUsingArray{
	t *data;
	int nextindex;
	int capacity;
public:
	
	stackUsingArray(){
		data = new t[4];
		nextindex = 0;
		capacity = 4;
	}
	
	int size(){
		return nextindex;
	}
	
	bool isEmpty(){
		return nextindex == 0;
	}
	
	void push(t element){
		if(nextindex == capacity){
			t *newdata = new t[2 * capacity];
			for(int i = 0; i < capacity; i++)
				newdata[i] = data[i];
			delete [] data;
			capacity *= 2;
			data = newdata;
		}
		data[nextindex++] = element;
	}
	
	t pop(){
		if(isEmpty()){
			cout << "stack is empty" << endl;
			return 0;
		}
		nextindex--;
		return data[nextindex];
	}
	
	t top(){
		if(isEmpty()){
			cout << "stack is empty" << endl;
			return 0;
		}
		return data[nextindex - 1];
	}
};

int main(){
	stackUsingArray<int> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	
	cout << s.top() << endl;		// 104
	cout << s.pop() << endl;		// 104
	cout << s.pop() << endl;		// 103
	cout << s.pop() << endl;		// 102
	cout << s.size() << endl;		// 2
	cout << s.isEmpty << endl;		// 0
	
	stackUsingArray<char> y;
	y.push(100);					// 100 will be taken as ascii value of d.
	y.push(101);
	y.push(102);
	y.push(103);
	y.push(104);
	
	cout << y.top() << endl;		// h
	cout << y.pop() << endl;		// h
	cout << y.pop() << endl;		// g
	cout << y.pop() << endl;		// f
	cout << y.size() << endl;		// 2
	cout << y.isEmpty << endl;		// 0
	
}