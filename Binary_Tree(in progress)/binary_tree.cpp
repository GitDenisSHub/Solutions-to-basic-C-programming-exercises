#include <iostream>
#include <ctime>
using namespace std;

/*
 74. Бинарное дерево
 Реализовать:
     • создание узлов +
     • добавление дочерних узлов +
     • обход дерева
     • удаление узлов
     • поиск узла
 Тренирует: понимание иерархической структуры данных и работы с деревьями.
 
Код после 7 часа 38 минуты работы над ним
Доходил до очереди почти 5 часов.....

Написал корректное равномерное заполнение дерева 

 */

class binary_tree{
public:
    binary_tree()
    : root(nullptr), count_of_Node(0){cout<<"====Add tree without a root!==="<<endl;}
    binary_tree(int data)
    : root(new Node(data)), count_of_Node(1){cout<<"====Add a tree with a root!==="<<endl;}
    
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
    
    //========================================
    //Заполнение дерева
    bool Insert(int data, Node* currentNode){
        if(currentNode == nullptr){
            cout<<"====Add tree's root!==="<<endl;
            root = new Node(data);
            count_of_Node++;

            cout<<"This element was added: " << root->data << endl;
            cout<<"Count elements in the tree: "<<que.GetCountQueue() << endl;
            //И выходим, действие выполнено
            return true;
        }
        else if((root->left == nullptr || root->right == nullptr) || currentNode == que.front()){
            //Спрашиваем, есть ли у узла наследники - добавляем туда элементы, если пусто
            if(!(currentNode->left != nullptr && currentNode->right != nullptr)){
                //Узнаем где именно пусто - добавляем элемент туда
                if(currentNode->left == nullptr){
                    cout<<"====Add left leaf of the tree!==="<<endl;
                    //cout<<"ABS"<<endl;
                    currentNode->left = new Node(data);
                    //Заносим узел в очередь, над ним мы будем работать в дальнейшем
                    que.push(currentNode->left);
                    cout<<"This element was added: " << currentNode->left->data << endl;
                    cout<<"First node in the queue: "<<que.front()<<endl;
                    cout<<"Total nambers of nodes in the tree: "<<que.GetCountQueue()<<endl;
                    
                    return true;
                }
                else{
                    cout<<"====Add right leaf of the tree!==="<<endl;
                    currentNode->right = new Node(data);
                    //Заносим узел в очередь, над ним мы будем работать в дальнейшем
                    que.push(currentNode->right);
                    cout<<"This element was added: " << currentNode->right->data << endl;
                    cout<<"First node in the queue: "<<que.front()<<endl;
                    cout<<"Total nambers of nodes in the tree: "<<que.GetCountQueue()<<endl;
                    
                    return true;
                }
                
            }
            //Если оба листка узла заняты, значит мы выполнили работу над ним - мы его удаляем из очереди
            if(currentNode->left != nullptr && currentNode->right != nullptr){ que.pop();}
            return false;
        }
        //Условие выхода из цикла
        else if(currentNode != que.front() && currentNode->left == nullptr && currentNode->right == nullptr){
            return false;
        }
        //Тут нужно сначала идти в правую сторону потом в левую
        //Тут мы будем искать не первое попавшееся свободное место
        //А будем искать именно наш индекc
        if(!(Insert(data, currentNode->left))){
            if(!(Insert(data, currentNode->right))){
                return false;
            }
        }

        return true;  
    }//Конец нащего ввода
    //========================================

    //Удаление элемента
    bool Romove(int data, Node* currentNode){
        //Удаление должно происходить так
        //Если элемент удаляется - мы сдвигаем всю левую сторону его наследников
        //Переопределяя им правых наследников на тех, что выше
        //И в очередь первыми мы должны поставить самый нижний элемент
        //Самый последний что мы сдвинули

        //Алгоритм поиска узла(скопировать из метода ввода)


        //Алгоритм удаления и сдвига когда мы уже нашли этот узел
        if(currentNode->left == nullptr && currentNode->right == nullptr){
            delete currentNode;
            count_of_Node--;
        }
        else{
            //Это нужно полностью переделать -- смотреть мой рисунок после смены правого узла 
            //И потери связи со своим пустым узлом - это все нужно учитывать
            if(currentNode->left != nullptr){
                currentNode->left->right = currentNode->right;
                currentNode = currentNode->left;
                count_of_Node--;
                
            }
            else{
                currentNode->right->left = currentNode->left;
                currentNode = currentNode->right;
                count_of_Node--;
            }
            
        }

    }

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
            if(head == nullptr){ cout<<"Queue is clear!Nothing to output!"<<endl;}
            else if(counter == 1){
                head = head->pNext;
                counter--;
                cout<<"The last element of the queue!"<<endl;
            }
            else{
                head = head->pNext;
                counter--;
            }
        }

        T front(){
            if(head == nullptr){cout<<"Queue is clear!First elemnt is absent!"<<endl; return 0;}
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
    //setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    cout<<endl;
    binary_tree bt(55);
    for (int i = 0; i < 12; i++)
    {
       bt.Insert(rand()%100+1, bt.GetRoot());
    }
    cout<<endl;

    

    cout<<"==========="<<endl;
    return 0;
}
