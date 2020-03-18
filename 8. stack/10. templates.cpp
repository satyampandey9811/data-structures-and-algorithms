// templates
// it is one the most important things in c++ to create objects 
// containing data of different data types.

template<typename T, typename V>

class Pair{
	T x;
	V y;
public:
	void setX(T x){
		this -> x = x;
	}
	T getX(){
		return x;
	}
	void setY(V y){
		this -> y = y;
	}
	V getY(){
		return y;
	}
};

int main(){
	Pair<int , int> p1;
	p1.setX(4);
	p1.setY(8);
	cout << p1.getX() << ' ' << p1.getY() << endl;
	// 4 8
	
	Pair<int, double> p2;
	p2.setX(10);
	p2.setY(23.23);
	cout << p2.getX() << ' ' << p2. getY() << endl;
	// 10 23.23
	
	Pair<Pair<int, int>, int> p3;
	p3.setY(10);
	Pair<int, int> p4;
	p4.setX(4);
	p4.setY(7);
	p3.setX(p4);
	cout << p3.getX().getX() << ' ' << p3.getX().getY() << ' ' << p3.getY() << endl;
	// 4 7 10
}