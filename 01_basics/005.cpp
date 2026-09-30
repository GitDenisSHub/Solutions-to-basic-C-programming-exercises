#include <iostream>
#include <ctime>

using namespace std;

//Найти максимум, минимум и среднее значение массива без сортировки.




int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    const int SIZE = 5;
    int *arr = new int[SIZE];
    
    //Отдельно инициализация массива
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()%100+1;
        cout<<arr[i] << " ";
    }
     
    int min = arr[0], max = arr[0], sum = 0;
    double avg;
    
    //Провека элементов по двум условиям и общий подсчет значений
    for (int i = 0; i < SIZE; i++) {
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
        sum+=arr[i];
    }
    //Узнаем среднее значение (не считая последнего нулевого)
    avg = (double)sum/SIZE;
    
    cout<<"\nMin value is " << min << "\nMax value is " << max << "\nAverage value is " << avg << endl;
    
    delete[] arr;
    arr = nullptr;
    return 0;
}