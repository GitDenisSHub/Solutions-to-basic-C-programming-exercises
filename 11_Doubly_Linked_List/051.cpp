#include <iostream>
#include <stdexcept>
using namespace std;

/*
 51. DoublyLinkedList
 Реализовать:
 PushFront +
 PushBack +
 PopFront +
 PopBack +
 Тренирует: prev, next, head, tail.

 */

class DoublyLinkedList{
public:
    //Конструктор по умолчанию
    DoublyLinkedList()
    : head(nullptr), tail(nullptr), count_of_head(0){}
    //Конструктор с параметрами
    DoublyLinkedList(int data)
    : head(new Node(data)),tail(head), count_of_head(1){}
    //Добавить узел в конец коллекции
    void push_back(int data){
        if(head == nullptr){
            cout<<"Добавляем первый эллемент коллекции!"<<endl;
            head = new Node(data);
            tail = head;
            count_of_head++;
        }
        else{
            cout<<"Добавляем следующий эллемент коллекции!"<<endl;
            tail->pNext = new Node(data);
            tail->pNext->pPrev = tail;
            tail = tail->pNext;
            count_of_head++;
            
        }
    }
    
    //Добавление элемента первым в коллекцию
    void push_front(int data){
        if(head == nullptr){
            push_back(data);
        }
        else{
            cout<<"Добавление элемента первым в коллекцию"<<endl;
            Node* first = new Node(data);
            first->pNext = head;
            head->pPrev = first;
            head = first;
            count_of_head++;
        }
        
    }
    
    //Удалить последний элемент коллекции
    void pop_back(){
        if(head == nullptr){
            cout<<"Коллекция пуста!"<<endl;
        }
        else if(head->pNext == nullptr){
            cout<<"Удаляем первый элемент коллекции!"<<endl;
            delete head;
            head = nullptr;
            tail = nullptr;
            count_of_head--;
        }
        else{
            cout<<"Удаляем крайний элемент коллекции!"<<endl;
            tail = tail->pPrev;
            delete tail->pNext;
            tail->pNext = nullptr;
            count_of_head--;
        }
    }
    //Удалить первый элемент коллекции
    void pop_front(){
        if(head == nullptr){
            cout<<"Удалять нечего!"<<endl;
        }
        else if(head->pNext == nullptr){
            pop_back();
        }
        else{
            cout<<"Удаляем первый элемент!"<<endl;
            head = head->pNext;
            delete head->pPrev;
            head->pPrev = nullptr;
            count_of_head--;
        }
    }
    
    //Вывод коллекции
    void PrintList(){
        if(head == nullptr){
            cout<<"Выводить нечего. Коллекция пуста!"<<endl;
        }
        else{
            cout<<"Вывод нашей коллекции: "<<endl;
            Node* currentNode = head;
            while(currentNode != nullptr){
                cout<<currentNode->GetData()<<" ";
                currentNode = currentNode->pNext;
            }
            cout<<endl;
        }
        
    }
    
    void Clear(){
        while(tail != nullptr){
            pop_back();
        }
    }
    
    ~DoublyLinkedList(){ Clear();}
    
    class Node{
        int data;
        Node* pNext;
        Node* pPrev;
        friend class DoublyLinkedList;
    public:
        //Конструктор по умолчанию
        Node()
        : data(0), pNext(nullptr), pPrev(nullptr){}
        //Конструктор с параметрами
        Node(int data)
        : data(data), pNext(nullptr), pPrev(nullptr){}
        //Возвращение значения узла
        int& GetData(){ return this->data;}
 
    };
    
private:
    Node* head;
    Node* tail;
    int count_of_head;
    friend class Node;
};


int main(){
    setlocale(LC_ALL, "Rus");
    
    DoublyLinkedList dlst;
    dlst.push_front(11);
    dlst.PrintList();
    dlst.push_back(55);
    dlst.push_back(99);
    dlst.PrintList();
    
    dlst.push_front(999);
    dlst.PrintList();
    
    /*
    dlst.pop_back();
    dlst.pop_back();
    dlst.pop_front();
    dlst.pop_front();
    
    dlst.PrintList();
     */
    return 0;
}
