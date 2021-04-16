// Muhammad Zaeem Tauqir
//      2020376
// Lab 7, Task # 2

#include<iostream>
using namespace std;

class Time{
    int hrs;
    int min;
    int sec;

    public:
    //default constructor
    Time(){
        hrs = 0;
        min = 0;
        sec = 0;
    }

    friend ostream& operator<< (ostream &out, Time &t);
    friend istream& operator>>(istream &in, Time &t);

};

ostream& operator<< (ostream &out, Time &t){
    out << t.hrs << ":" << t.min << ":" << t.sec;
    return out;
}

istream& operator>>(istream &in, Time &t){
    cout << "Enter hours : ";
    in >> t.hrs;
    cout << "Enter minutes : ";
    in >> t.min;
    cout << "Enter seconds : ";
    in >> t.sec;

    return in; 
}


int main(){
    Time obj;

    cin >> obj;
    cout << endl;

    cout << "Current time is : " << obj;

   return 0; 
}