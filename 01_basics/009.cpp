#include <iostream>
#include <ctime>

using namespace std;

//Нужно перевернуть массив на месте без создания нового массива

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    const int SIZE = 9;
    int arr[SIZE];
    
    int save_value;
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()%10+1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
       
    
    int i = 0;
    int j = SIZE-1;
    
    while(i <= j){
        
        save_value = arr[i];
        arr[i] = arr[j];
        arr[j] = save_value;
        
        
        i++;
        j--;
    }
    
    for (int i = 0; i < SIZE; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}