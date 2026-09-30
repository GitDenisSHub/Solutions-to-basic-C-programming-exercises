#include <iostream>
#include <stdexcept>
using namespace std;

/*
 53. Поиск с двух концов
 Искать элемент, начиная одновременно от head и tail.
 Тренирует: преимущество двусвязного списка.
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
            //cout<<tail->data<<endl;
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
    
    void erase(int index){
        if(index <= count_of_head-1){
            if(head == nullptr){
                cout<<"Отсутствуют элементы для удаления!"<<endl;
            }
            else if(count_of_head-1 == index){
                pop_back();
            }
            else if(index == 0){
                pop_front();
            }
            else{
                int count = 0;
                if(index > (count_of_head-1)/2){
                    cout<<"Удаляем элемент из правой половины"<<endl;
                    Node* currentNode = tail;
                    count = count_of_head - 1;
                    while(index != count){
                        currentNode = currentNode->pPrev;
                        count--;
                    }
                    currentNode = currentNode->pPrev;
                
                    currentNode->pNext = currentNode->pNext->pNext;
                    delete currentNode->pNext->pPrev;
                    currentNode->pNext->pPrev = currentNode;
  
                    count_of_head--;
                }
                else{
                    cout<<"Удаляем элемент из левой половины"<<endl;
                    Node* currentNode = head;
                    while(index != count){
                        currentNode = currentNode->pNext;
                        count++;
                    }
                    currentNode = currentNode->pPrev;
                
                    currentNode->pNext = currentNode->pNext->pNext;
                    delete currentNode->pNext->pPrev;
                    currentNode->pNext->pPrev = currentNode;
  
                    count_of_head--;
                    
                }
            }
        }
        else{
            cout<<"Такого элемента нету в коллекции!"<<endl;
        }
        
    }
    
    bool Search(int data){
        
        int counter = 1;
        int last_counter = count_of_head;
        if(head == nullptr){
            cout<<"Коллекция пуста! Элементы отсутствуют!"<<endl;
            return false;
        }
        else if(head->data == data){
            cout<<"Найденные данные: " <<"#"<< counter << " - " << head->data << endl;
            return true;
        }
        else if(tail->data == data){
            counter = count_of_head;
            cout<<"Найденные данные: " <<"#"<< counter << " - " << tail->data << endl;
            return true;
        }

        else{
            Node* currentHead = head->pNext;
            Node* currenTail = tail->pPrev;
            bool is_find = false;
            for (int i = 0, j = count_of_head; i < (count_of_head-1); i++,j--) {
                counter++;
                last_counter--;
                if(currentHead->data == data){
                    cout<<"Найденные данные55: " <<"#"<< counter << " - " << currentHead->data << endl;
                    is_find = true;
                    return true;
                }
                if(currenTail->data == data){
                    cout<<"Найденные данные: " <<"#"<< last_counter << " - " << currenTail->data << endl;
                    is_find = true;
                    return true;
                }
                
                currentHead = currentHead->pNext;
                currenTail = currenTail->pPrev;
            }
            if(!is_find){
                cout<<"Элементы отсутствуют!"<<endl;
                return false;
            }
            
            return false;
            
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
    dlst.push_back(666);
    dlst.push_back(777);
    dlst.push_back(99);
    dlst.PrintList();
    
    dlst.push_front(999);
    dlst.PrintList();
    
    dlst.erase(5);
    dlst.PrintList();
    
    
    dlst.Search(11);
    cout<<"==================="<<endl;
    return 0;
}
