// Muhammad Zaeem Tauqir
//  2020376
// lab # 11, task:1

#include<iostream>
#include<vector>
using namespace std;

template <typename T1>
T1 max( T1 *arr, int size ){
    T1 max_num = *(arr);
    for( int i = 0; i < size; i++ ){
        if( *(arr + i) > max_num ){
            max_num = *(arr + i); 
        }
    }
    return max_num;
}

template <typename T2>
T2 min( T2 *arr, int size ){
    T2 min_num = *(arr);
    for( int i = 0; i < size; i++ ){
        if( *(arr + i) < min_num ){
            min_num = *(arr + i); 
        }
    }
    return min_num;
}

int main(){
    int N = 0;

    cout << "Enter array size : ";
    cin >> N;

    int *array1 = new int [N];
    cout << "Enter int values: ";
    for( int i = 0; i < N; i++ ){
        cin >> *(array1 + i);
    }

    cout << "Largest value : " << max(array1, N) << endl;
    cout << "Smallest value : " << min(array1, N) << endl;

    cout << endl;
    float *array2 = new float [N];
    cout << "Enter float values: ";
    for( int i = 0; i < N; i++ ){
        cin >> *(array2 + i);
    }
    
    cout << "Largest value : " << max(array2, N) << endl;
    cout << "Smallest value : " << min(array2, N) << endl;

    return 0;
}
