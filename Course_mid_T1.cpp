// Muhammad Zaeem Tauqir
//  2020376
// course mid, Task 1

#include<iostream>
using namespace std;

class midq1{
    float var1;
    float var2;

    public:
    // default constructor
    midq1(){
        var1 = 0.0;
        var2 = 0.0;
    }
    // constructor
    midq1(float x, float y){
        var1 = x;
        var2 = y;
    }
    //member ftn
    float getsum(){
        float sum = 0.0;
        sum = var1 + var2;
        return sum;
    }

    friend bool compare(midq1 const & a, midq1 const & b);

    // copy ctor and dtor not needed. in class midq1.
};

bool compare(midq1 const & a, midq1 const & b){
    if(a.var1 == b.var1 && a.var2 == b.var2){
        return true;
    }
    //else it will
    return false;
}

int main(){
    midq1 obj1, obj2(3, 5);
    midq1 obj3;

    cout << obj2.getsum() << endl;
    cout << compare(obj1, obj2) << endl;
    cout << compare(obj1, obj3) << endl;

    return 0;
}