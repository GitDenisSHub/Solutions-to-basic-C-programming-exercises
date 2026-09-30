#include <iostream>
#include <ctime>

using namespace std;

/*
 Увеличение динамического массива
 Есть массив размера N. Создать новый размером 2N, перенести данные, удалить старый.
 Тренирует: динамическую память, копирование данных.
 Зачем: понять, что примерно происходит внутри динамического контейнера.
*/

int* Go_To_Second_Array(int*& arr, int& size){
    
    size*=2;
    int* arr2 = new int[size];
    for (int i = 0; i < size; i++) {
        if(i < size/2){
            arr2[i] = arr[i];
        }
        else{
            arr2[i] = 0;
        }
        
    }
    
    delete[] arr;
    return arr2;
}
\

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    int SIZE;
    cout<<"Input size of arr: ";
    cin>>SIZE;
    
    int* arr = new int[SIZE];
    for (int i = 0; i<SIZE; i++) {
        arr[i] = rand()%10+1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    arr = Go_To_Second_Array(arr, SIZE);
    
    for (int i = 0; i< SIZE; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    delete[] arr;
    arr = nullptr;
    return 0;
}
