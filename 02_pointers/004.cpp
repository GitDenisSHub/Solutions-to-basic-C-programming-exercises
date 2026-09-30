#include <iostream>
#include <ctime>

using namespace std;

/*
 Найти минимум и максимум
 Вернуть через два указателя адреса минимального и максимального элементов.
 Тренирует: указатели как параметры, изменение нескольких результатов функции.
 Зачем: хорошая практика работы с несколькими выходными значениями.
*/

void Min_Max(const int *arr, const int SIZE, int* min_value, int* max_value){
    
    *max_value = *min_value = arr[0];
    for (int i = 0; i < SIZE; i++) {
        if(arr[i] > *max_value){
            *max_value = &arr[i];
        }
        if(arr[i] < *min_value){
            *min_value = &arr[i];
        }
    }
}



int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    int min_value = 0, max_value = 0;
    const int SIZE = 10;
        int arr[SIZE];
        
        for (int i = 0; i < SIZE; i++) {
            arr[i] = rand()%10+1;
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    
    Min_Max(arr, SIZE, &min_value, &max_value);

    cout<<"Max value is " << max_value << "\nMin value is " << min_value << endl;
    
    return 0;
}
