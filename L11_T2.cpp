// Muhammad Zaeem Tauqir
//  2020376
// lab # 11, task:2

#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Operations{
    T num1;
    T num2;

    public:

    //constructor
    Operations( T a, T b){
        num1 = a;
        num2 = b;
    }

    T addition(){
        return (num1 + num2);
    }

    T subtraction(){
        return (num1 - num2);
    }

    T product(){
        return (num1 * num2);
    }
    
    T divide(){
        return (num1 / num2);
    }

    void dispaly(){
        cout << "Numbers are : " << num1 << " and " << num2 << endl;
        cout << "Addition is: " << addition() << endl;
        cout << "Subtraction is: " << subtraction() << endl;
        cout << "Multiplication is: " << product() <<endl;
        cout << "Division is: " << divide() << endl;
    }

};

int main(){
    Operations<int> intVals( 7, 5);
    Operations<float> floatVals( 3.5, 2);

    cout << "Operations result for int values" << endl;
    intVals.dispaly();
    
    cout << endl;
    
    cout << "Operations result for float values" << endl;
    floatVals.dispaly();

    return 0;
}