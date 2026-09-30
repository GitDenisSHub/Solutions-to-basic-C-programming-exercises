#include <iostream>
#include <ctime>

using namespace std;

/*
 Развернуть массив
 Развернуть массив на месте, без создания второго массива.
 Тренирует: указатели/индексы, работу с памятью.
 Зачем: учит изменять существующие данные, не создавая лишнюю память.
*/

void Rotate(int* arr, const int size){
    
    int help;
    int i = 0, j = size-1;
    
    while(i < j){
        help = arr[i];
        arr[i] = arr[j];
        arr[j] = help;
        
        i++;
        j--;
    }
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
    
    Rotate(arr, SIZE);
    
    for (int i = 0; i < SIZE; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
    
    return 0;
}
