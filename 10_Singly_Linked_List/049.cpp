#include <iostream>
using namespace std;

/*
 49. Развернуть список
 Получить:
 1 → 2 → 3 → 4
 как:
 4 → 3 → 2 → 1
 Тренирует: манипуляцию связями.
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
        
    bool Find(int value){
        bool is_find = false;
        int position = 0;
        Node* currentNode = head;
        while(currentNode != nullptr){
            position++;
            if(currentNode->data == value){
                is_find = true;
                cout<<"Число " << value << " найдено!"<<endl;
                cout<<"Его позиция - " << position << " элемент списка!"<<endl;
                return true;
            }
            currentNode = currentNode->pNext;
        }
        cout<<"Число не найдено!"<<endl;
        return false;
       
    }
        
    void Delete(int data){
        if(!(Find(data))){
            cout<<"Данное число отсутствует!"<<endl;
            
        }
        else if(data == head->data){
        
            PopFront();
        }
        else{
            Node* currentNode = head;
            Node* helper = nullptr;
            int is_find = false;
            while(currentNode->pNext != nullptr){
                
                if(currentNode->pNext->data == data){
                    cout<<"Удаляем выбранный элемент!"<<endl;
                    helper = currentNode->pNext;
                    
                    currentNode->pNext = currentNode->pNext->pNext;
                    is_find = true;
                    delete helper;
                    helper = nullptr;
                    break;
                }
                currentNode = currentNode->pNext;
            }
            if(!is_find){ cout<<"Элемент не найден!"<<endl;}
            
        }
    }
        
    void HardDelete(int data){
        bool is_find = false;
        while(Find(data)){
            Delete(data);
            is_find = true;
            cout<<"Число найдено!"<<endl;
        }
        if(!is_find){
            cout<<"Данное число отсутствует!"<<endl;
        }

    }
        
    void Reverse(){
        Node* currentNode = head;
        Node* newNode = nullptr;
        Node* firstNode = nullptr;
        
        if(head != nullptr){
            while(head->pNext != nullptr){
                while(currentNode->pNext->pNext != nullptr){
                    currentNode = currentNode->pNext;
                }
                
                if(newNode == nullptr){
                    newNode = currentNode->pNext;
                    firstNode = newNode;
                }
                else{
                    newNode->pNext = currentNode->pNext;
                    newNode = newNode->pNext;
                }
                
                currentNode->pNext = nullptr;
                currentNode = head;
            }
            
            
            
            newNode->pNext = head;
            newNode = newNode->pNext;
            head = firstNode;
            
        }
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
            //cout<<"Удаление первого элемента!"<<head->data<<endl;
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

    lst.PushFront(999);
    lst.PushFront(555);
    lst.PushFront(555);

    lst.Print();
    
    lst.Reverse();
    lst.Print();
    
    cout<<"================="<<endl;
    return 0;
}
