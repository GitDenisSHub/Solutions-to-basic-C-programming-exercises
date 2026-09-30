#include <iostream>

using namespace std;

/*
 71. Свой Deque
 Реализовать PushFront, PushBack, PopFront, PopBack.
 Здесь главная цель: сделать структуру, у которой оба конца рабочие.
 Для первого задания я бы использовал знакомый тебе обычный фиксированный массив.

 */

class Deque{
public:
    Deque()
    : front(-1), back(-1), count(0){}
    Deque(int value)
    : front(0), back(0), count(1), arr{value}{}
    
    
    //Добавить элемент в начало очереди
    void push_front(int value){
        if(count == 0){
            arr[0] = value;
            front = back = 0;
            count++;
        }
        else if(count == SIZE){
            cout<<"Массив заполнен! Добавление не выполнилось!"<<endl;
        }
        else{
            //Два случая:
            //1. Когда первый элемент есть и нужен сдвиг право
            //2. Когда нету первого (или второго элемента) - нужно найти существующий и переместить значение к нему
            if(front != 0){
                int position_before_front = 0;
                while(front != position_before_front + 1){
                    position_before_front++;
                }
                arr[position_before_front] = value;
                front = position_before_front;
            }
            else{
                for (int i = SIZE - 1; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = value;
                back++;
            }
            count++;
            if(count == SIZE){cout<<"Массив был заполнен!"<<endl;}
        }
    }
    
    //Добавить элемент в конец очереди
    void push_back(int value){
        if(count == 0){
            arr[0] = value;
            front = back = 0;
            count++;
        }
        else if(count == SIZE){
            cout<<"Массив заполнен! Добавление не выполнилось!"<<endl;
        }
        else{
            //Два случая:
            //1. Когда последний элемент есть и нужен сдвиг влево
            //2. Когда нету последнего (или предпоследнего элемента) - нужно найти существующий и переместить значение к нему
            if(back != SIZE - 1){
                int position_after_back = SIZE - 1;
                while(back != position_after_back - 1){
                    position_after_back--;
                }
                arr[position_after_back] = value;
                back = position_after_back;
            }
            else{
                for (int i = 0; i < SIZE - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                arr[SIZE -  1] = value;
                front--;
            }
            count++;
            if(count == SIZE){cout<<"Массив был заполнен!"<<endl;}
        }
        
        
    }
    
    void pop_front(){
        if(count == 0){cout<<"Удаление не выполнено! Очередь пуста!"<<endl;}
        else{
            front++;
            count--;
            
            if(count == 0){ cout<<"Мы очистили массив! Ура!"<<endl;}
        }
    }
    
    void pop_back(){
        if(count == 0){cout<<"Удаление не выполнено! Очередь пуста!"<<endl;}
        else{
            back--;
            count--;
            
            if(count == 0){ cout<<"Мы очистили массив! Ура!"<<endl;}
        }
        
    }
    
    
    void print_deque(){
        for (int i = front; i < back + 1; i++) {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
    
private:
    int arr[5];
    int SIZE = 5;
    int count;
    int front;
    int back;
    
};


int main(){
    setlocale(LC_ALL, "Rus");

    Deque deq(77);
    deq.push_front(55);
    deq.push_back(99);
    deq.push_back(777);
    deq.push_front(1);
   

    deq.print_deque();
    
    return 0;
}
