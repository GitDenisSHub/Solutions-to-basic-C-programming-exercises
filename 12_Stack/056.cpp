#include <iostream>
#include <stdexcept>
using namespace std;

/*
 56. Стек на списке
 То же самое, но через linked list.
 Реализовать:
 Push +
 Pop
 Top +
 Empty
 Тренирует: сравнение двух реализаций.
 */

class Stack{
public:
    Stack()
    : head(nullptr), counter(-1){}
    Stack(int data)
    : head(new Node(data)), counter(0){}
    
    void push(int data){
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
    
    void top(){
        if(head == nullptr){
            cout<<"Стек пуст!"<<endl;
        }
        else{
            Node* currentNode = head;
            while(currentNode->pNext != nullptr){
                currentNode = currentNode->pNext;
            }
            cout<<currentNode->data<<endl;
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
        int data;
        friend class Stack;
    public:
        Node()
        : pNext(nullptr), data(0){ }
        Node(int data)
        : pNext(nullptr), data(data){}
        
    };

private:
    Node* head;
    int counter;
};

int main(){
    setlocale(LC_ALL, "Rus");
    
    Stack stk(55);
    stk.top();
    stk.push(66);
    stk.top();
    stk.push(77);
    stk.top();
    
    cout<<stk.empty()<<endl;
    
    stk.pop();
    stk.top();
    stk.pop();
    stk.top();
    stk.pop();
    stk.top();
    
    cout<<stk.empty()<<endl;
    
    return 0;
}
