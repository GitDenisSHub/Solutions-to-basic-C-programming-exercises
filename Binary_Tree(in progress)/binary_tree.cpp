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
     • поиск узла +
 Тренирует: понимание иерархической структуры данных и работы с деревьями.

 - временно расположил вспомогательные указатели в поля класса Дерева(это нужно будет исправить, наверное)

реализуем удаление/смещение значения требуемого узла - все инструменты у нас присутствуют

Также, нужно что-то придумать для удаление корня, ведь у него нету роидителя 
но думаю, что для меня это вообще не проблема, потому что у нас есть "односторонний сдвиг"



нужно написать вспомогательный второй метод для рекурсии удаления элемента



Еще обязательно нужно, чтобы удаленный узел стал первым элементом в очереди на добавление элемента!!!!!!!

Код после 12 часов 00 минуты чистой проги
Понял что нужно работать с очередью через 5 часов.....
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
                    que.push_back(currentNode->left);
                    cout<<"This element was added: " << currentNode->left->data << endl;
                    //cout<<"First node in the queue: "<<que.front()<<endl;
                    cout<<"This element's address: "<<currentNode->left<<endl;
                    cout<<"Total nambers of nodes in the tree: "<<que.GetCountQueue()<<endl;
                    
                    return true;
                }
                else{
                    cout<<"====Add right leaf of the tree!==="<<endl;
                    currentNode->right = new Node(data);
                    //Заносим узел в очередь, над ним мы будем работать в дальнейшем
                    que.push_back(currentNode->right);
                    cout<<"This element was added: " << currentNode->right->data << endl;
                    //cout<<"First node in the queue: "<<que.front()<<endl;
                    cout<<"This element's address: "<<currentNode->right<<endl;
                    cout<<"Total nambers of nodes in the tree: "<<que.GetCountQueue()<<endl;
                    
                    return true;
                }
                
            }
            //Если оба листка узла заняты, значит мы выполнили работу над ним - мы его удаляем из очереди
            if(currentNode->left != nullptr && currentNode->right != nullptr){ que.pop(); cout<<"First node in the queue: "<<que.front()<<endl;}
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

    //========================================
    //Поиск элемента - создан для метода удаления(но можно использовать и так)
    Node* is_exist(int data, Node* currentNode){      
        //Алгоритм поиска узла
        if(currentNode->data == data){
            cout<<"We found this element!"<<endl;
            return currentNode;
        } 
        else if(currentNode->left == nullptr && currentNode->right == nullptr) return nullptr; 

        Node* foundNode = nullptr;
        if(currentNode->left != nullptr){
            foundNode = is_exist(data, currentNode->left);
            if(foundNode == nullptr){
                if(currentNode->right != nullptr){
                    foundNode = is_exist(data, currentNode->right);
                    if(foundNode == nullptr){
                    //cout<<"The element doesn't exist here!"<<endl;
                    return nullptr;
                    }
                    //Вот тут нужно возаращать то, что возвращает наследник правого
                    return foundNode;
                }
                cout<<"The element isn't exist here!"<<endl;
                return nullptr;
                
            }
        }
        else{
            foundNode = is_exist(data, currentNode->right);
            if(foundNode == nullptr){
                return nullptr;
            }
            return foundNode;
        }
        
        return foundNode;
    }
    //========================================

    //Поиск родителя нужного узла
    //========================================
    Node* parentNode(Node* necessaryNode, Node* currentNode){
        //Алгоритм поиска узла
        if(currentNode->left == necessaryNode){
            cout<<"We found this element! We're in his left child"<<endl;
            return currentNode;
        }
        else if(currentNode->right == necessaryNode){
            cout<<"We found this element! We're in his right child"<<endl;
            return currentNode;
            
        }
        else if(currentNode->left == nullptr && currentNode->right == nullptr) return nullptr; 

        Node* foundNode = nullptr;
        if(currentNode->left != nullptr){
            foundNode = parentNode(necessaryNode, currentNode->left);
            if(foundNode == nullptr){
                if(currentNode->right != nullptr){
                    foundNode = parentNode(necessaryNode, currentNode->right);
                    if(foundNode == nullptr){
                    //cout<<"The element doesn't exist here!"<<endl;
                    return nullptr;
                    }
                    //Вот тут нужно возаращать то, что возвращает наследник правого
                    return foundNode;
                }
                cout<<"The element isn't exist here!"<<endl;
                return nullptr;
                
            }
        }
        else{
            foundNode = parentNode(necessaryNode, currentNode->right);
            if(foundNode == nullptr){
                return nullptr;
            }
            return foundNode;
        }
        
        return foundNode;
    }
    //========================================

    //========================================
    //Вспомогательный методя для удаления
    bool DeleteNode(Node* childNode, Node* parentNode){

    }
    //========================================

    //Метод для удаления узлов
    //========================================
    //Попроюуем сделать так, чтобы метод одновременно работал с переменными данных
    //И принимал указатель на нужный элемент одновременно
    template <typename T>
    bool Delete(T data, Node* currentNode){
        if(currentNode == root){
            //Получаем этот элемент и его расположение в виде указателя
            necessaryNode = is_exist(data, currentNode);
            //Находим родителя данного узла
            helpNode = parentNode(necessaryNode, currentNode);
            //Сначала проверяем, есть ли этот элемент + получаем его значение
            //В данном случае necessaryNode - возвращенное методом значение отсутствия элемента в нашей коллекции
            if(necessaryNode == nullptr){cout<<"Nothing to delete! Element isn't exist!"<<endl; return false;}
            //Наверное вот тут где-то нужно начать переход к нашему родителю
            Delete(necessaryNode, helpNode);
        }
        else{
            //2 варианта, когда есть левый и когда нету левого
            //1 шаг - делаем рекурсию в одну из сторон
            //просто копируем значения, удаляем только последний узел
            //Тут нужно проверять 
            if(!(currentNode->left == nullptr && currentNode->right == nullptr)){
                //Тут надо понять у кого мы будем забирать значение
                //И к нему же будем переходить, чтобы он отнимал значение у следующего своего элемента
                if(currentNode->left != nullptr){

                }
                else{

                }
            }
            //Если у узла нету наследников(это значит он является листом!)
            //Значит мы не мелочимся и напрямую работаем с полями, без промежуточного указателя
            else{
                if(helpNode->left == necessaryNode){
                    helpNode->left = nullptr;
                    delete necessaryNode;
                    return true;
                }
                else{
                    helpNode->right = nullptr;
                    delete necessaryNode;
                    return true;
                }
            }
        }
        return true;
    }
    //========================================
    
    //Тут находится дерево, которое будет хранить все адреса листьев  
    //========================================
    template <class T>
    class Queue{
    public:
        Queue()
        : head(nullptr), counter(0){}
        Queue(T data)
        : head(new Node(data)), counter(1){}

        void push_back(T data){
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

        void push_front(T data){
            if(head == nullptr){push_back(data);}
            else{
                Node* newNode = new Node(data);
                counter++;
                newNode->pNext = head;
                head = newNode;
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
    //Пусть эти поля временно будут тут, мне нужно сначала решить задачку
    //Потом разберемся что с этим делать
    Node* necessaryNode;
    Node* helpNode;
};


int main() {
    //setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    cout<<endl;
    binary_tree bt(55);
    for (int i = 0; i < 8; i++)
    {
       bt.Insert(rand()%100+1, bt.GetRoot());
    }
    cout<<endl;


    cout << bt.is_exist(38,bt.GetRoot()) << endl;
    cout << bt.parentNode(bt.is_exist(38,bt.GetRoot()), bt.GetRoot()) << endl;
   
    

    cout<<"==========="<<endl;
    return 0;
}
