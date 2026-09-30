#include <iostream>
#include <ctime>

using namespace std;

/*
 10. Динамический двумерный массив
 Создать матрицу N × M динамически, заполнить и вывести.
 Тренирует: динамическую память, указатели, вложенные циклы.
 Зачем: следующий уровень после одномерного массива.

*/

void Rand_Arr(int** arr, int row, int col){
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = rand()%100+1;
        }
    }
}

void Input_Arr(int** arr, int row, int col){
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout<< arr[i][j] << " ";
        }
        cout<<endl;
    }
}

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    int ROW, COL;
    cout<<"Input ROW: "; cin>>ROW;
    cout<<"Input COL: "; cin>>COL;
    
    int** arr = new int* [ROW];
    for (int i = 0; i < ROW; i++) {
        arr[i] = new int [COL];
    }
   
    Rand_Arr(arr, ROW, COL);
    Input_Arr(arr, ROW, COL);
    
    
    for (int i = 0; i < ROW; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}