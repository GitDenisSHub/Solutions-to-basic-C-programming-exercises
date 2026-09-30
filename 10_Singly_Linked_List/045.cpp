#include <iostream>
using namespace std;

/*
 45. Свой LinkedList
 Реализовать:
 PushFront+
 PushBack +
 PopFront+
 PopBack+
 Тренирует: узлы, head, динамическую память.

 */

class LinkedList{
public:
    
    LinkedList()
    : head(nullptr){}
    
    LinkedList(int data)
    : head(new Node(data)){}
    
    void PushBack(int data){
        Node* currentNode = head;
        if(head == nullptr){
            head = new Node(data);
          
            cout<<"Добавили первый элемент!"<<endl;
        }
        else{
            while(currentNode->pNext != nullptr){
                currentNode = currentNode->pNext;
            }
            //Вот тут очень непонятно написано - перепроверь
            currentNode->pNext = new Node(data);
          
            cout<<"Добавили следующий элемент!"<<endl;
        }
    }
    
    void PushFront(int data){
        if(head == nullptr){
            cout<<"Добавляем первый элемент!"<<endl;
            PushBack(data);
        }
        else{
            cout<<"Добавляем первый элемент!"<<endl;
            Node* currentNode = new Node(data);
            currentNode->pNext = head;
            head = currentNode;
            
        }
    }
    
    void PopBack(){
        if(head == nullptr){
            cout<<"No elements in list!"<<endl;
        }
        else if(head->pNext == nullptr){
            cout<<"Удаляем последний элемент!"<<endl;
            delete head;
            head = nullptr;
            
        }
        else{
            cout<<"Удаляем последний элемент!"<<endl;
            Node* currentNode = head;
            while(currentNode->pNext->pNext != nullptr){
                currentNode = currentNode->pNext;
                
            }
            delete currentNode->pNext;
            currentNode->pNext = nullptr;
            
        }
    }
    
    void PopFront(){
        if(head == nullptr){
            cout<<"No elements in list!"<<endl;
        }
        else if(head->pNext == nullptr){
            PopBack();
        }
        else{
            cout<<"Удаляем первый элемент!"<<endl;
            Node* currentNode = head->pNext;
            delete head;
            head = currentNode;
        }
    }
    
    void Print(){
        Node* currentNode = head;
        if(head == nullptr){
            cout<<"No node in List!"<<endl;
        }
        
        while(currentNode != nullptr){
            cout<<currentNode->data<<" ";
            currentNode = currentNode->pNext;
        }
        cout<<endl;

    }
    
    class Node{
        int data;
        Node* pNext;
        friend class LinkedList;
        
    public:
        Node()
        : data(0), pNext(nullptr){}
        
        Node(int data)
        : data(data), pNext(nullptr){}
        
    };
        
    void Clear(){
        while(head != nullptr){
            cout<<"Удаление первого элемента!"<<head->data<<endl;
            PopFront();
        }
    }
    
    ~LinkedList(){
        Clear();
    }
private:
    Node* head;
    friend class Node;
    
};

int main(){
    setlocale(LC_ALL, "Rus");
    
    LinkedList lst;
    lst.PushFront(999);
    lst.Print();
    
    
    lst.PushBack(55);
    lst.PushBack(99);
    lst.PushBack(13);
    lst.Print();
    
    lst.PopBack();
    lst.PopBack();
    
    lst.Print();
    
    lst.PushFront(999);
    lst.PushFront(555);
    
    lst.Print();
    
    lst.PopFront();
    lst.PopFront();

    
    lst.Print();
    
    return 0;
}
