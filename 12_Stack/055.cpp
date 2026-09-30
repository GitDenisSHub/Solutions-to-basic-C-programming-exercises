#include <iostream>
#include <stdexcept>
using namespace std;

/*
 55. Свой стек на массиве
 Реализовать:
 Push - добавить последний
 Pop - удалить последний
 Top - возвращает верхний элемент
 Empty - очистить весь
 Тренирует: LIFO и ручную реализацию структуры.
 */

class Stack{
    int arr[100];
    int top;

public:
    Stack()
    : top(-1){}
    
    void push(int data){
        
        if((top+1) > 99){
            cout<<"Стек переполнен! Добавление элементов недоступно!"<<endl;
        }
        else{
            cout<<"Добавляем верхний элемент!"<<endl;
            top++;
            arr[top] = data;
        }
        
        
    }
    
    void pop(){
        if(top != -1){
            cout<<"Очищаем верхний элемент!"<<endl;
            top--;

        }
        else{
            cout<<"Стэк пуст! Удалять нечего!"<<endl;
        }
        
    }
    
    int Top(){
        if(top != -1){
            return arr[top];
        }
        else{
            throw logic_error("Стек пуст!");
        }
        
    }
    
    bool Empty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    
};


int main(){
    setlocale(LC_ALL, "Rus");
    
    Stack stack;
    stack.push(55);
    stack.push(66);
    stack.push(99);
    
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    
    try {
        cout<<stack.Top()<<endl;
    } catch (const std::exception& ex) {
        cout<<ex.what()<<endl;
    }
    cout<<stack.Empty()<<endl;
    
    
    return 0;
}
