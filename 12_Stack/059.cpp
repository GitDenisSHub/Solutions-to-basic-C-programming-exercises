#include <iostream>
#include <cstring>
using namespace std;

/*
 59. История действий
 Сделать систему:
 Do()
 Undo()
 Каждое действие помещается в стек.
 Тренирует: применение стека как модели реальной системы.

 */

template <class T>
class Stack{
public:
    
    Stack()
    : head(nullptr), counter(0){}
    Stack(T data)
    : head(new Node(data)), counter(0){}
    
    
    void push(T data){
        if(head == nullptr){
            head = new Node(data);
            counter++;
        }
        else{
            Node* currentNode = head;
            while(currentNode->pNext != nullptr){
                currentNode = currentNode->pNext;
            }
            currentNode->pNext = new Node(data);
            counter++;

        }
    }
    
    void pop(){
        if(head == nullptr){
            cout<<"Коллекция пуста! Удалять нечего!"<<endl;
        }
        else if(head->pNext == nullptr){
            delete head;
            head = nullptr;
            counter--;
        }
        else{
            Node* currentNode = head;
            while(currentNode->pNext->pNext != nullptr){
                currentNode = currentNode->pNext;
            }
            delete currentNode->pNext;
            currentNode->pNext = nullptr;
            counter--;
        }
        
    }
    
    T top(){
        if(head == nullptr){
            cout<<"Стек пуст!"<<endl;
            return " ";
        }
        else{
            Node* currentNode = head;
            while(currentNode->pNext != nullptr){
                currentNode = currentNode->pNext;
            }
            //cout<<currentNode->data<<endl;
            return currentNode->data;
        }
        
    }
    
    bool empty(){
        if(head == nullptr){
            return true;
        }
        else return false;
    }
    
    
    void clear(){
        while(head != nullptr){ pop();}
    }
    
    ~Stack(){ clear();}
    
    class Node{
        Node* pNext;
        T data;
        friend class Stack;
    public:
        Node()
        : pNext(nullptr), data(T{}){ }
        Node(T data)
        : pNext(nullptr), data(data){}
        
    };

private:
    Node* head;
    int counter;
    friend void UnDo();
};

Stack<const char*> stk;

void Do(const char* str){
    stk.push(str);
    cout<<"Выполнил: " << str << endl;
}

void UnDo(){
    if(stk.head == nullptr){
        cout<<"Стек пуст! Действий больше не осталось!"<<endl;
    }
    else{
        cout<<"Отменяю последнее действие: " << stk.top() <<endl;
        stk.pop();
    }
    
}




int main(){
    setlocale(LC_ALL, "Rus");
   
    Do("Выполняю действие!");
    Do("Копирую действие!");
    Do("Удаляю массив!");
    Do("Ввожу пароль Пентагона!");
    
    cout<<"===================" << endl;
    
    UnDo();
    UnDo();
    UnDo();
    UnDo();
    UnDo();
    
    return 0;
}
