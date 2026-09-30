#include <iostream>
#include <ctime>


using namespace std;

/*
 15. Рекурсивный бинарный поиск
 Реализовать бинарный поиск рекурсивно.
 Тренирует: рекурсию, массивы, алгоритмы поиска.
 Зачем: впервые серьёзно соединяет алгоритмическую идею и рекурсию.
 */

bool Binary_Search(int* arr,int left_side, int right_side, int number){
    
    int i = (right_side + left_side) / 2;
    if(arr[i] < number){
        if((right_side - left_side) <= 1){
            i = right_side;
        }
        else{
            i = (right_side + left_side) / 2;
        }
    }
    
    if(number > arr[right_side] || number < 1){
        return false;
    }
    
    if((right_side - left_side) <= 1){
        if(number == arr[left_side] || number == arr[right_side]){
            return true;
        }
        
        if(number != arr[right_side] && number != arr[left_side]){
            return false;
        }
        
        if(number > arr[right_side] || number < arr[0]){
            return false;
        }
        
    }
    
    
    else{
        
        
        if(arr[i] > number){
            
            right_side = i;
            return Binary_Search(arr,left_side, right_side, number);

        }
        
        if(arr[i] < number){
            left_side = i;
            return Binary_Search(arr,left_side, right_side, number);
            
        }
    }
    
    
    
    
    if(number == arr[i]){
        return true;
    }
    

    return false;
}


int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    
    int arr[] = {1, 3, 4, 5, 7, 8, 10};
    int SIZE = sizeof(arr) / sizeof(arr[0]);

    int number;
    cout<<"Necessary integer number: "; cin >> number;
    
    cout<< Binary_Search(arr, 0, SIZE - 1, number) << endl;
    
   
    return 0;
}
