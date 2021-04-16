// Muhammad Zaeem Tauqir
//      2020376
//  Lab # 6, Task # 1 

#include<iostream>
using namespace std;

class CalculateArea{
    int length;
    int breadth;

    public:
    // Default constructor
    CalculateArea(){
        length = 0;
        breadth = 0;
    }

    CalculateArea(int x, int y){
        length = x;
        breadth = y;
    }

    friend class Area;
};

class Area{
    int a;

    public:
    Area(){
        a = 0;
    }

    void display_area(CalculateArea x){
        cout << "Length is : " << x.length << endl;
        cout << "Breadth is : " << x.breadth << endl;
        a = x.breadth * x.length;
        cout << "Area = " << a << endl;
    }
};

int main(){
    CalculateArea obj1(5, 8);
    Area obj2;
    
    obj2.display_area(obj1);

    return 0;
}