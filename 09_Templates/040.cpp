#include <iostream>
#include <string>
using namespace std;


/*
 40. Max<T>
 Шаблонная функция поиска максимума.
 Тренирует: function templates.

 */


template <typename T>
T Max(const T arr[], const int size){
    //nt size = sizeof(arr) / sizeof(arr[0]);
    T max = T{};
    
    for (int i = 0; i < size; i++) {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    
    return max;
}

template <typename T, int N>
T Max(const T (&arr)[N]){
    T max = T{};
    
    for (int i = 0; i < N; i++) {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}


int main(){
    setlocale(LC_ALL, "Rus");
    
    int a[] = {1, 5, 6, 23, 55, 11};
    double b[] = {1.4, 5.33, 6.1234, 23.3, 55, 88.7, 88.1};
   
    //int size1 = sizeof(a) / sizeof(a[0]);
    int size2 = sizeof(b) / sizeof(b[0]);
    
    cout<< "Max value is - " << Max(a) << endl;
    cout<< "Max value is - " << Max(b, size2) << endl;
   
    return 0;
}
