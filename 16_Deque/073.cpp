#include <iostream>
#include <ctime>


using namespace std;

/*
 Экстра задача. Написать полноценный дек на Чанках!
 Сделать:
 
 PushFront +
 PushBack +
 PopFront +
 PopBack +
 Print +
 Правильное удаление всех массивов очереди!
 
 */

class Deque{
public:
    Deque()
    : head(nullptr), tail(nullptr), count_of_Node(0), count_of_elements(0){
        cout << "//====Создание дека без элементов!====//" << endl;
    }
    Deque(int data)
    : head(new Node(data)), tail(nullptr), count_of_Node(1), count_of_elements(1){
        head->front = head->back = 0;
        tail = head;
        cout << "//====Создание дека с первым элементом!====//" << endl;
    }
    
    void push_back(int data){
        //Если нету массива - создаем его
        if(count_of_Node == 0){
            cout << "//====Создание первого узла!====//" << endl;
            cout << "//====Добавление первого элемента!====//" << endl;
            head = new Node(data);
            count_of_Node++;
            count_of_elements++;
            tail = head;
            
        }
        else{
            //потом спрашиваем, есть ли у текущего массива место для элементов?
            if(tail->count_in_current_node == tail->SIZE){
                cout << "//====Создание следующего узла!====//" << endl;
                cout << "//====Добавление первого элемента следующего узла!====//" << endl;
                tail->pNext = new Node(data);
                tail->pNext->pPrev = tail;
                tail = tail->pNext;
                count_of_Node++;
                count_of_elements++;
                
            }
            else{
                cout << "//====Добавление очередного элемента!====//" << endl;
                //Добавляем элемент в массив, следующим элементом
                tail->back++;
                tail->arr[tail->back] = data;
                count_of_elements++;
                tail->count_in_current_node++;
            }
        }
    }
    
    void push_front(int data){
        if(count_of_Node == 0){
            push_back(data);
        }
        else{
            if(head->count_in_current_node == head->SIZE){
                cout << "//====Создание узла перед нашим узлом!====//" << endl;
                cout << "//====Добавление первого элемента переднего узла!====//" << endl;
                head->pPrev = new Node;
                head->pPrev->pNext = head;
                head = head->pPrev;
                //Обязательно нужно задать последний элемент массиву не забываем об этом!!
                head->front = head->back = head->SIZE - 1;
                head->arr[head->front] = data;
                count_of_Node++;
                count_of_elements++;
                head->count_in_current_node++;
            }
            else{
                cout << "//====Добавление переднего элемента!====//" << endl;
                head->front--;
                head->arr[head->front] = data;
                count_of_elements++;
                head->count_in_current_node++;
            }
            
        }
    }
    
    void pop_front(){
        //Крайние случаи://
        //Когда остался последний элемент вообще +
        //Когда остался один элемент у head узла +
        //Просто когда удаляем элемент в head узле
        //Когда дек пуст полностью +
        if(count_of_elements == 0){
            cout << "//====Дек пуст!Удалять нечего!====//" << endl;
        }
        else if(count_of_elements == 1){
            delete head;
            head = tail = nullptr;
            count_of_elements--;
            count_of_Node--;
        }
        else if(head->count_in_current_node == 1){
            head = head->pNext;
            delete head->pPrev;
            head->pPrev = nullptr;
            count_of_Node--;
            count_of_elements--;
        }
        else{
            head->front++;
            count_of_elements--;
            head->count_in_current_node--;
        }
        
    }
    
    void pop_back(){
        //Крайние случаи://
        //Когда остался последний элемент вообще
        //Когда остался один элемент у head узла
        //Просто когда удаляем элемент в head узле
        //Когда дек пуст полностью +
        if(count_of_elements == 0){
            cout << "//====Дек пуст!Удалять нечего!====//" << endl;
        }
        else if(count_of_elements == 1){
            pop_front();
        }
        else if(tail->count_in_current_node == 1){
            tail = tail->pPrev;
            delete tail->pNext;
            tail->pNext = nullptr;
            count_of_Node--;
            count_of_elements--;
        }
        else{
            tail->back--;
            count_of_elements--;
            tail->count_in_current_node--;
        }
        
    }
    
    void print_queue(){
        if(count_of_Node == 0){
            cout << "//====Очередь пуста! Выводить нечего!====//" << endl;
        }
        else{
            cout << "//====Вывод всей коллекции!====//" << endl;
            Node* currentNode = head;
            int start, end;
            
            for (int i = 0; i < count_of_Node; i++) {
                start = currentNode->front;
                end = currentNode->back + 1;
                
                while(start != end){
                    cout<<currentNode->arr[start]<<" ";
                    start++;
                }
                cout<<endl;
                currentNode = currentNode->pNext;
            }
        }
        
    }
    
    void clear(){
        while(count_of_elements != 0){ pop_back();}
    }
    
    ~Deque(){ clear();}
    
    //Каждый узел будет массивом из 5 элементов
    class Node{
    public:
        //Узел по умолчанию будет использоваться методом push_front
        //Потому что тут будет иная инициализация первым элементом
        Node()
        : pPrev(nullptr), pNext(nullptr), count_in_current_node(0), front(-1), back(-1)
        {}
        //Если все элементы по местам - нету смысла им выделять новую память
        Node(int data)
        : pPrev(nullptr), pNext(nullptr),arr{data}, count_in_current_node(1), front(0), back(0)
        {}
        
    private:
        Node* pPrev;
        Node* pNext;
        int front;
        int back;
        int SIZE = 5;
        int arr[5];
        int count_in_current_node;
        friend class Deque;
        
    };
private:
    Node* head;
    Node* tail;
    int count_of_Node;
    int count_of_elements;
};


int main() {
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));

    Deque deq;
    
    deq.push_back(rand()%100+1);
    deq.push_back(rand()%100+1);
    deq.push_back(rand()%100+1);
    deq.push_back(rand()%100+1);
    deq.push_back(rand()%100+1);
    deq.push_back(rand()%100+1);
    deq.push_back(rand()%100+1);
   
    
    deq.print_queue();
    
    

    deq.push_front(rand()%100+1);
    
    deq.print_queue();
    
    deq.push_back(rand()%100+1);
    deq.print_queue();
    
    
    deq.pop_front();
    deq.pop_front();
    deq.push_front(rand()%100+1);
    deq.push_front(rand()%100+1);
    
    deq.print_queue();
    
    cout<<"============"<<endl;
    
    deq.pop_back();
    deq.pop_back();
    deq.pop_back();
    deq.pop_back();
    deq.print_queue();
    
    deq.clear();
    deq.print_queue();
    return 0;
}
