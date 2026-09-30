#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*
 63. Принтер
 Документы поступают в очередь печати.
 У каждого есть количество страниц.
 Рассчитать время ожидания каждого документа.
 Тренирует: FIFO и моделирование.

 */
template <class T>
class Queue;

struct Document{
    string Name;
    int page;
    static int count;
    int personalcount;
    
    Document* pNext;
    Document* pPrev;
    friend class Queue<Document>;
    
    Document()
    : Name("Документ"), pNext(nullptr), pPrev(nullptr), page(rand()%5+1){count++; personalcount = count;}
    Document(string Name)
    : Name(Name), pNext(nullptr), pPrev(nullptr), page(rand()%5+1){ count++; personalcount = count;}
    ~Document(){ count--;}
    
};
int Document::count = 0;

ostream& operator<<(ostream& out, const Document& doc){
    string msg = doc.Name + " " + to_string(doc.personalcount) + " --> " + to_string(doc.page);
    out << msg;
    return out;
}

template <class T>
class Queue{
public:
    Queue()
    : head(nullptr), tail(nullptr), count(0){}
    Queue(string name)
    : head{new T(name)}, tail(head), count(1){}
    
    void push(){
        if(head == nullptr){
            head = new T();
            tail = head;
            count++;
        }
        else{
            tail->pNext = new T();
            tail->pNext->pPrev = tail;
            tail = tail->pNext;
            count++;
        }
    }
    
    void pop(bool is_end = false){
        if(head == nullptr){
            cout<<"Очередь пуста!"<<endl;
            
        }
        else if(head->pNext == nullptr){
            if(!is_end){
                
                cout<<"Ожидание 2 минуты на 1 страницу!"<<endl;
                cout<<front()<<endl;
                int i = head->page * 2;
                position++;
                wait_time += i;
                while(i != 0){
                    cin.get();
                    i--;
                }
                cout<<"Всего прошло: " << wait_time << " минут для Документа #" << position <<endl;
                cout<<"Next!"<<endl;
            }
            delete head;
            head = nullptr;
            tail = nullptr;
            count--;
        }
        else{
            if(!is_end){
                
                cout<<"Ожидание 2 минуты на 1 страницу!"<<endl;
                cout<<front()<<endl;
                int i = head->page * 2;
                position++;
                wait_time += i;
                while(i != 0){
                    cin.get();
                    i--;
                }
                cout<<"Всего прошло: " << wait_time << " минут для Документа #" << position <<endl;
                cout<<"Next!"<<endl;
            }
            head = head->pNext;
            delete head->pPrev;
            head->pPrev = nullptr;
            count--;
            
            T* currentDoc = head;
            int i = 1;
            while(currentDoc->pNext != nullptr){
                currentDoc->personalcount = i;
                i++;
                currentDoc = currentDoc->pNext;
            }
            currentDoc->personalcount = i;
            
        }
    }
  
    string back(){
        if(head == nullptr){
            throw logic_error("Очередь пуста!");
        }
        else{
            string msg = tail->Name + " " + to_string(tail->personalcount) + " --> " + to_string(tail->page) + " страниц";
            return msg;
        }
        
    }
    
    string front(){
        if(head == nullptr){
            throw logic_error("Очередь пуста!");
        }
        else{
            string msg = head->Name + " " + to_string(head->personalcount) + " --> " + to_string(head->page) + " страниц";
            return msg;
        }
    }
    bool Empty(){ if(count == 0) return true; else return false;}
    
    void Clear(){
        while(!Empty()){ pop(true);}
    }
    
    ~Queue(){ Clear();}
    
private:
    int count;
    T* head;
    T* tail;
    static int wait_time;
    static int position;
};
template <class T>
int Queue<T>::wait_time = 0;
template <class T>
int Queue<T>::position = 1;


int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    Queue<Document> que("Документ");
    que.push();
    que.push();
    que.push();
    que.push();
    que.push();
    cout << que.front() << endl;
    cout << que.back() << endl;
    
    que.pop();
    que.pop();
    que.pop();
    que.pop();
    cout << que.front() << endl;
    cout << que.back() << endl;
    
    cout<<"==========="<<endl;
    return 0;
}
