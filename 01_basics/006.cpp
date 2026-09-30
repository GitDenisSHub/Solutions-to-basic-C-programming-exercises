#include <iostream>
#include <ctime>

using namespace std;

//Реализовать сортировку пузырьком (bubble sort) вручную — без std::sort.
//Сравниваем соседние элементы. Если они стоят неправильно — меняем их местами.

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    const int SIZE = 10;
    int help_value;
    bool change_is_happen;
    
    int arr[SIZE];
    //Инициализация массива и вывод его элементов на экран
    cout<<"[";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()%100+1;
        cout<<" "<<arr[i];
    }
    cout<<" ]" <<endl;
    
    
    do{
        //На каждому следующем проходе значение обнуляется
        change_is_happen = false;
        //Тут цикл сравнения элементов и смена их местами
        for (int i = 0; i < SIZE; i++) {
            //Чтобы не было сравнения со значением вне массива
            if(i+1 == SIZE){
                break;
            }
            //Первый проход
            if(arr[i+1] < arr[i]){
                help_value = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = help_value;
                change_is_happen = true;
            }
        }
    }while(change_is_happen == true);
    
    cout<<"[";
    for (int i = 0; i < SIZE; i++) {
        cout<<" "<<arr[i];
    }
    cout<<" ]" <<endl;
    
    return 0;
}