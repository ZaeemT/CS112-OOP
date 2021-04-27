// Muhammad Zaeem Tauqir
//		2020376
// Assignment # 3

#include<iostream>
using namespace std;

class myfunnyarray{
	int size = 0;
	int *arr = new int [size];

	public:	
	//constructors
	myfunnyarray(int x){
		size = x;
		for(int i = 0; i < size; i++){
			arr[i] = 0;
		}		
	}
	myfunnyarray(int x, int y){
		size = x;
		for(int i = 0; i < size; i++){
			arr[i] = y;
		}
	}
	//Copy constructor
	myfunnyarray(const myfunnyarray & a){
		size = a.size;
		for(int i = 0; i < size; i++){
			arr[i] = a.arr[i];
		}
	}

	friend myfunnyarray operator + (myfunnyarray a, myfunnyarray b);
	friend myfunnyarray operator - (myfunnyarray a, int b);
	friend myfunnyarray & operator ++ (myfunnyarray & a);
	friend myfunnyarray operator ++ (myfunnyarray & a, int);
	
	int & operator [] (int i){
		if(i < 0 || i > size){
			cerr << "Invalid index" <<endl;
			exit(-1);
		}
		return arr[i];
	}

	friend ostream& operator << (ostream &out, const myfunnyarray a);

	//Destructor
	~myfunnyarray(){
		if(arr != nullptr)
			delete [] arr;
	}

};

myfunnyarray operator + (myfunnyarray a, myfunnyarray b){
	int c = 0;
	int size = 0;
	size = a.size + b.size;
	myfunnyarray result(size);

	for(int i = 0; i < a.size; i++){
		result.arr[c] = a.arr[i];
		c++;
	}
	for(int i = 0; i < b.size; i++){
		result.arr[c] = b.arr[i];
		c++;
	}

	return result;
}

myfunnyarray operator - (myfunnyarray a, int b){
	myfunnyarray result(a.size);
	for(int i = 0; i < a.size; i++){
		result.arr[i] = a.arr[i] - b;
	}
	return result;
}

//Pre-increment 
myfunnyarray & operator ++ (myfunnyarray & a){	
	for(int i = 0; i < a.size; i++){
		a.arr[i]++;
	}
	return a;
}

//Post-increment
myfunnyarray operator ++ (myfunnyarray & a, int){
	myfunnyarray result = a;
	for(int i = 0; i < a.size; i++){
		a.arr[i]++;
	}
	return result;
}

ostream& operator << (ostream &out, const myfunnyarray a){
	for(int i = 0; i < a.size; i++){
		out << a.arr[i];
		if(i != a.size - 1){
			cout << ",";
		}
	}
    return out;
}


bool checkifzero (myfunnyarray arg, int index){
	if (arg[index] == 0)	
		return true;
	//else
	return false;
}

int main () {
	myfunnyarray a(3);		// should create an array containing 3 integers each initialized to zero
	cout<<a<<endl;		// should print: 0,0,0
	myfunnyarray b(4,5);		// should create an array containing 4 integers each initialized to five
	cout<<b<<endl;		// should print: 5,5,5,5

	myfunnyarray c = a+b; // c should contain 7 elements: first 3 intialized to 0, last four to 5.
	cout<<c<<endl;				// should print: 0,0,0,5,5,5,5

	c[1] = 33;			// should assign value 33 to the element at index 1
	if (checkifzero(c, 1)==false)
		cout<<c<<endl;			// should print: 0,33,0,5,5,5,5

	myfunnyarray d = c++;
	cout<<d<<endl;			// should print: 0,33,0,5,5,5,5
	cout<<c<<endl;			// should print: 1,34,1,6,6,6,6

	myfunnyarray e = ++(++c);			
	cout<<e<<endl;			// should print: 3,36,3,8,8,8,8
	cout<<c<<endl;			// should print: 3,36,3,8,8,8,8

	myfunnyarray f = c-3;	// f[i] = c[i]-3;
	cout<<f<<endl;			// should print: 0,33,0,5,5,5,5
	cout<<c<<endl;			// should print: 3,38,3,8,8,8,8

	(c = b) = a;
	cout<<c<<endl;			// should print: 0,0,0

	cout << a << "-" << b << "-" << c;	// should print 0,0,0-5,5,5,5-0,0,0

	return 0;
}
