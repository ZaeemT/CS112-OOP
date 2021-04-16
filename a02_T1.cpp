//  Muhammad Zaeem Tauqir
//      2020376
//  assignment # 2

#include<iostream>
using namespace std;

struct mytime{

    private:
    int sec;
    int min;
    int hrs;

    public:
    mytime(){   
        sec = 0;
        min = 0;
        hrs = 0;
        cout << "ctor0 called" << endl;
    }

    mytime( int x, int y, int z ){
        sec = x;
        min = y;
        hrs = z;
        cout << "ctor1 called" << endl;

    }

    mytime( int x ){
        sec = x;
        min = 0;
        hrs = 0;
        cout << "ctor2 called" << endl;
    }

    mytime( int x, int y){
        sec = x;
        min = y;
        hrs = 0;
        cout << "ctor3 called" << endl;
    }

    void show12(){
        if ( hrs >= 12 ){
            hrs = hrs - 12;
            cout << hrs << " : " << min << " : " << sec << " PM " << endl;
        }
        else {
            cout << hrs << " : " << min << " : " << sec << " AM " << endl;
        }
    }

    void show23(){
        if( hrs >= 24 ){
            hrs = hrs - 24;
        }
        cout << hrs << " : " << min << " : " << sec << endl;
    }

    void  add_seconds( int x ){
        sec = sec + x;
        
        if ( sec > 59){
           add_minutes(sec / 60);
           sec = sec % 60; 
        }
    }

    void add_minutes( int x ){
        min = min + x;
        if( min > 59){
            add_hours(min / 60);
            min = min % 60;
        }
    }

    void add_hours( int x ){
        hrs = hrs + x;
    }
    
    int return_sec(){
        return sec;
    }  
    int return_min(){
        return min;
    } 
    int return_hrs(){
        return hrs;
    }
};

void mytime_diff( mytime x, mytime y){
    int time1 = 0, time2 = 0;
    time1 = (x.return_hrs() * 3600) + (x.return_min() * 60) + x.return_sec();
    time2 = (y.return_hrs() * 3600) + (y.return_min() * 60) + y.return_sec();
    if( time1 > time2){
        cout << "Time difference : " << time1 - time2 << endl;
    }
    else{
        cout << "Time difference : " << time2 - time1 << endl;
    }
}

mytime seconds_to_mytime( int x ){
    mytime obj;
    obj.add_seconds(x);
    return obj;
}

int main(){

    mytime a;
    mytime b(30);
    mytime c(30, 30);
    mytime d(30, 30, 10);

    /* b.add_seconds(40);
    b.show12();

    c.add_minutes(60); 
    c.show12(); */

    cout << "Original time = ";
    d.show12();
    d.add_hours(3);
    cout << "After addition " << endl;
    d.show23();
    d.show12();

    cout << endl;
    mytime_diff(b,c);

    cout << endl;
    a = seconds_to_mytime(1200);
    a.show23();
    
    return 0;
}