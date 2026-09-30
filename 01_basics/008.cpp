#include <iostream>
#include <ctime>

using namespace std;
//Написать бинарный поиск в отсортированном массиве
//В общем, одновременно нужна и сортировка и поиск

//Бинарный поиск — это поиск в отсортированном массиве, при котором на каждом шаге проверяется середина
//текущего диапазона и отбрасывается половина, в которой искомого элемента быть не может.

//Предлагаю сразу дать отсортированный массив и сначала собрать алгоритм бинарного поиска!!!!!!!!!

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    //Размер массива
    int SIZE_before = 5;
    //Левая и правая граница
    int left_bound = 0, right_bound = SIZE_before;
    //Поиск середины относительно наших границ
    int range = right_bound/2;
    //Нужное число
    int necessery_num;
    //Найдено ли число - для вывода отрицательного ответа
    bool is_find = false;
    //Уже отсортированный массив
    int arr[] = {1, 3, 4, 5, 6};
    //Инициализация массива и вывод его элементов на экран
    cout<<"SIze os the arr is " << SIZE_before << endl;
    cout<<"[";
    for (int i = 0; i < SIZE_before; i++) {
        //arr[i] = rand()%5+1;
        cout<<" "<<arr[i];
    }
    cout<<" ]" <<endl<<endl;
    
    cout<<"What num are you need? "; cin>>necessery_num;
    
    
    //Вот тут нужно сделать бинарный поиск!
    while(range >= 0){
        
        if(necessery_num == arr[range]){
            cout<<"We are find this number! " << necessery_num <<endl;
            cout<<"His position is " << range+1 << " and adress is " << range << endl << endl;;
            is_find = true;
            break;
        }
        
        else{
            if(range == left_bound || range == right_bound){
                break;
            }
            
            
            //Тут проверка должна быть относительно своих границ
            if(necessery_num > arr[range]){
                if(range == right_bound){
                    break;
                }
                else{
                    left_bound = range;
                    range += (right_bound - left_bound)/2;
                }
                
            }
            
            if(necessery_num < arr[range]){
                if(range == left_bound){
                    break;
                }
                else{
                    right_bound = range;
                    range = right_bound/2;
                }
            }
        }
        
        
    }
    //Вывод отрицательног ответа, если число не найдено
    if(!is_find){
        cout<<"Necesseay number is not find!"<<endl<<endl;
    }
    
    return 0;
}