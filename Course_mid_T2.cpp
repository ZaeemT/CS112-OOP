// Muhammad Zaeem Tauqir
//  2020376
//  course mid, task 2

#include <iostream>
using namespace std;

class midq2 {
	float *fp;

	public:

	void show() {
		cout << *fp;
	}
	//default constructor
	midq2(){
		*fp = 0;
	}
	// constructor
	midq2(float a){
		fp = new float;
		if(fp == nullptr){
			cerr << "Memory Error!" << endl;
			exit(-1);
		}
		*fp = a;
	}
	// implement increment() here
	void increment(){
		*fp = *fp + 1.0;
	}

	// implement f1() here
    float & f1(){
        return *fp;
    }

	// implement f2() here
    float * f2(){
        return this;
    }

    // destructor
    ~midq2(){
        if(fp != nullptr){
            delete fp;
        }
    }
};


int main () {
	midq2 v1;
	v1.show(); cout<<endl; // should print 0

	midq2 v2(99.9);
	v2.show(); cout<<endl;	// should print 99.9 

	v1.increment();
	v1.show(); cout<<endl;	// should print 1

	v2.f1() = 33.3;
	v2.show(); cout<<endl;  // should print 33.3

	v2.f2()->show(); cout<<endl;	// should print 33.3
}
