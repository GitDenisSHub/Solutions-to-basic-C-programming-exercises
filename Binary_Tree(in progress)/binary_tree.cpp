#include <iostream>
#include <ctime>
using namespace std;

/*
 74. Бинарное дерево
 Реализовать:
     • создание узлов
     • добавление дочерних узлов
     • обход дерева
     • удаление узлов
     • поиск узла
 Тренирует: понимание иерархической структуры данных и работы с деревьями.
 
Код после 6 часа 18 минуты чистой проги

 */

class binary_tree{
public:
    binary_tree()
    : root(nullptr), count_of_Node(0){cout<<"====Добавляем дерево без корня!==="<<endl;}
    binary_tree(int data)
    : root(new Node(data)), count_of_Node(1){cout<<"====Добавляем дерево с корнем!==="<<endl;}
    
    class Node{
    public:
        Node()
        : left(nullptr), right(nullptr){}
        Node(int data)
        : left(nullptr), right(nullptr), data(data){}
        
    private:
        int data;
        Node* left;
        Node* right;
        friend class binary_tree;
    };
    
    Node* Insert(int data, Node* currentNode){
        if(currentNode == nullptr){
            cout<<"====Добавляем корень дерева!==="<<endl;
            root = new Node(data);
            count_of_Node++;

            cout<<"Количество элементов в очереди: "<<que.GetCountQueue() << endl;
            //И выходим, действие выполнено
            return currentNode;
        }

        //Тут мы сначала должны найти тот самый первый адрес
        //Если не нашли - вернуться к корню и начать искать в правой стороне
        //И уже через него добавлять ему листья
        //Если левый пуст - добавляем в левый
        //Если занят - добавляем в правый лист
        //И удаляем этот узел из очереди!
        else{
            //Спрашиваем, есть ли у узла наследники - добавляем туда элементы, если пусто
            if(!(currentNode->left != nullptr && currentNode->right != nullptr)){
                //Узнаем где именно пусто - добавляем элемент туда
                if(currentNode->left == nullptr){
                    cout<<"====Добавляем левый листок!==="<<endl;
                    currentNode->left = new Node(data);
                    //Заносим узел в очередь
                    que.push(currentNode->left);
                    cout<<"Первый узел очереди: "<<que.front()<<endl;
                    cout<<"Всего узлов в очереди: "<<que.GetCountQueue()<<endl;
                    return nullptr;
                }
                else{
                    cout<<"====Добавляем правый листок!==="<<endl;
                    currentNode->right = new Node(data);
                    //Заносим узел в очередь
                    que.push(currentNode->right);
                    cout<<"Первый узел очереди: "<<que.front()<<endl;
                    cout<<"Всего узлов в очереди: "<<que.GetCountQueue()<<endl;
                    return nullptr;
                }
                
            }
            else{   
                
                Insert(data, currentNode->left);
                Insert(data, currentNode->right);
                
             
            }//Конец else
        }
    
        //
        return 0;  
    }//Конец нащего ввода
    
    //Тут находится дерево, которое будет хранить все адреса листьев  
    //========================================
    template <class T>
    class Queue{
    public:
        Queue()
        : head(nullptr), counter(0){}
        Queue(T data)
        : head(new Node(data)), counter(1){}

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
            if(head == nullptr){ cout<<"Очередь пуста!Выводить нечего!"<<endl;}
            else if(counter == 1){
                head = head->pNext;
                counter--;
                cout<<"Это был последний элемент очереди!"<<endl;
            }
            else{
                head = head->pNext;
                counter--;
            }
        }

        T front(){
            if(head == nullptr){cout<<"Очередь пуста!Первый элемент отсутствует!"<<endl; return 0;}
            else{
                return head->data;
            }
        }
        //Вывод количества узлов в очереди
        int GetCountQueue(){ return counter;}

        ~Queue(){
            while(counter != 0){
                pop();

            }
        }

        class Node{
        public:
                Node(T data)
                : data(data), pNext(nullptr){}

        private:
            T data;
            Node* pNext;
            friend class Queue;
        }; 

    private:
        Node* head;
        int counter;
    };
    //========================================
    
    //Нам нужен метод, который будет безопасно возвращать корень дерева
    Node* GetRoot(){ return root;}
private:
    Node* root;
    int count_of_Node;
    //Внутри будет очередь указателей на узлы
    Queue<Node*> que;
    
};





int main() {
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    binary_tree bt(55);
    bt.Insert(rand()%100+1, bt.GetRoot());
    bt.Insert(rand()%100+1, bt.GetRoot());
    //bt.Insert(rand()%100+1, bt.GetRoot());
    cout<<endl;

    // bt.Insert2(rand()%100+1, bt.GetRoot());
    // cout<<endl;
    // bt.Insert2(rand()%100+1, bt.GetRoot());
    // bt.Insert2(rand()%100+1, bt.GetRoot());
    // cout<<endl;
    // bt.Insert2(rand()%100+1, bt.GetRoot());
    // bt.Insert2(rand()%100+1, bt.GetRoot());
    // cout<<endl;
    // //Вот это уже не добавляется, так как первый уровень листьев заполнен
    // //Что делать дальше в этом случае?
    // //Как понять куда двигаться?

    // //Заполнение ячеек 9 - 12
    // bt.Insert2(rand()%100+1, bt.GetRoot());
    // bt.Insert2(rand()%100+1, bt.GetRoot());
    // bt.Insert2(rand()%100+1, bt.GetRoot());
    // bt.Insert2(rand()%100+1, bt.GetRoot());
    // cout<<endl;
    
    // //
    // bt.Insert2(rand()%100+1, bt.GetRoot());

    
    
    //Нужно научиться работать вообще без GetRoot
    //bt.Order(bt.GetRoot());

    cout<<"==========="<<endl;
    return 0;
}
