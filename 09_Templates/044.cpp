#include <iostream>
using namespace std;

/*
 44. Шаблонный поиск
 Написать шаблонную функцию поиска элемента в массиве любого типа.
 Тренирует: шаблоны + алгоритмы.

 */

template <typename T, int N>
void Search(const T (&arr)[N]){
    T value;
    bool is_find =  false;
    cout<<"ENter ur value: "; cin >> value;
    
    for (int i = 0; i < N; i++) {
        if(value == arr[i]){
            is_find = true;
            cout<<"Элемент найден!"<<endl;
        }
    }
    if(!is_find){ cout<<"Элемент отсутствует!"<<endl;}
}

int main(){
    setlocale(LC_ALL, "Rus");
    
    int arr1[] = {5, 44, 55, 66, 77};
    double arr2[] = {34.4 , 24324.4, 3543.4, 44.0, 33.4};
  
    Search(arr1);
    Search(arr2);
    
    return 0;
}
