#include <iostream>
#include <ctime>

using namespace std;

/*
 12. Рекурсивный поиск максимума
 Найти максимальный элемент массива без цикла.
 Тренирует: рекурсию + массивы.
 Зачем: заставляет мыслить через состояние задачи, а не через цикл.

*/

int Bigger_El(int* arr, int size, int iterator){

    
    int bigger = arr[iterator];
    iterator++;
    
    
    if(iterator == 0){
        bigger = arr[iterator];
    }
    
    if(iterator == size){
        return bigger;
    }
    
    if(arr[iterator] > bigger){
        bigger = arr[iterator];
    }

    return Bigger_El(arr,size,--iterator);
}


int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    const int SIZE = 4;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()%100+1;
    }
    
    for (int i = 0; i < SIZE; i++) {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<Bigger_El(arr,SIZE, 0)<<endl;
    
    return 0;
}
