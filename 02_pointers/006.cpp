#include <iostream>
#include <ctime>

using namespace std;

/*
 Динамический массив
 Пользователь вводит размер N, программа создаёт динамический массив, заполняет его и удаляет.
 Тренирует: new[], delete[].
 Зачем: закрепить ручное управление памятью.
*/

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
    
    
    delete[] arr;
    arr = nullptr;
    
    return 0;
}
