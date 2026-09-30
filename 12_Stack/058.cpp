#include <iostream>
#include <cstring>
using namespace std;

/*
 58. Обратная строка через стек
 Поместить символы в стек и вывести их обратно.
 Тренирует: практическое применение LIFO.

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
    
    int top(){
        if(head == nullptr){
            cout<<"Стек пуст!"<<endl;
            return ' ';
        }
        else{
            Node* currentNode = head;
            while(currentNode->pNext != nullptr){
                currentNode = currentNode->pNext;
            }
            cout<<currentNode->data<<" ";
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
};

int main(){
    setlocale(LC_ALL, "Rus");
    
    const char* word = "Hello world!";
    Stack<char> stk;
    
    try {
        for (int i = 0; i < strlen(word); i++) {
            stk.push(word[i]);
            stk.top();
        }
        cout<<endl;
        while(!stk.empty()){
            stk.top();
            stk.pop();
        }

    }
    catch (const std::exception& ex) {
        cout<<ex.what()<<endl;
    }
    
    
    return 0;
}
