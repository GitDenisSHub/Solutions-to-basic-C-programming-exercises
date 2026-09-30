#include <iostream>
#include <ctime>

using namespace std;

/*
 Найти максимум через указатель (обычный массив)
 Функция получает массив и его размер и возвращает указатель на максимальный элемент.
 Тренирует: указатели, массивы, адреса элементов.
 Зачем: понять, что указатель может обозначать не просто число, а конкретное место в массиве.
*/

int* Max(int* arr, const int size){
    int max_value = arr[0];
    int index_max_value = 0;
    
    for (int i = 0; i < size; i++) {
        if(max_value < arr[i]){
            max_value = arr[i];
            index_max_value = i;
        }
    }
    return &arr[index_max_value];
}



int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    const int SIZE = 10;
    int arr[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()%10+1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int *max_value = Max(arr, SIZE);
    cout<<"Max value is "<< *max_value << " value" <<endl;
    
    
    return 0;
}
