#include <iostream>
#include <ctime>

using namespace std;

/*
 11. Рекурсивная сумма массива
 Найти сумму элементов массива рекурсивно.
 Тренирует: рекурсию и передачу массива.
 Зачем: понять, как рекурсивная функция постепенно проходит структуру.

*/

int Sum_Arr(int* arr, int element){
    
    if(element < 0){
        return 0;
    }
    int el = arr[element];
    return el + Sum_Arr(arr,--element);
}


int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    const int SIZE = 4;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()%10+1;
    }
    
    for (int i = 0; i < SIZE; i++) {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<Sum_Arr(arr, SIZE - 1)<<endl;
    
    return 0;
}
