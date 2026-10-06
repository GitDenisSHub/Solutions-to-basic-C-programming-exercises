#include <iostream>
#include <ctime>
using namespace std;

/*
74. Бинарное дерево
 Реализовать:
     • создание узлов +
     • добавление дочерних узлов +
     • обход дерева
     • удаление узлов +
     • поиск узла +
 Тренирует: понимание иерархической структуры данных и работы с деревьями.
//========================================
- наладил корректное добавление элементов в дерево
- написал обход дерева preorder
- написал обход дерева inorder
- написал обход дерева postorder
- написал обход дерева levelorder

//========================================

Нам нужно переделать метож Clear() - потому что он очень много ресурсов тратит
нужно, чтобы удаление происходило внутри него!!!!!!
Без использования нашего метода поиска и удаления - нужно это оптимизировать жестко
(возможно сделать то же самое, что происходит во время обхода дерева!)

insert работает очень запутано, нужно будет это поправить

levelorder работает не совсем корректно

Код после 17 часов 16 минуты чистой проги
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
            currentNode = new Node(data);
            count_of_Node++;
            root = currentNode;
            cout<<"This element was added: " << currentNode->data << endl;
            cout<<"Count elements in the tree: "<< count_of_Node << endl;
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
                    count_of_Node++;
                    cout<<"Total nambers of nodes in the tree: "<<count_of_Node<<endl;
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
                    count_of_Node++;
                    cout<<"Total nambers of nodes in the tree: "<<count_of_Node<<endl;
                    //После добавления второго элемента нужно удалить узел из очереди добавления
                    //В случае, если это не корень, конечно же
                    if(currentNode != root){ que.pop();}
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

    //Метод для удаления узлов
    //========================================
    bool Delete(int data, Node* currentNode){
        if(currentNode == nullptr){
            cout << "Nothing to delete! Tree is empty!" << endl;
            return false;
        }
        //Получаем этот элемент и его расположение в виде указателя
        Node* necessaryNode = is_exist(data, currentNode);
        if(necessaryNode == root && count_of_Node == 1){
            delete root;
            root = nullptr;
            que.Clear();
            count_of_Node--;
            return true;
        }

        //В данном случае necessaryNode - возвращенное методом значение отсутствия элемента в нашей коллекции
        if(necessaryNode == nullptr){cout<<"Nothing to delete! Element isn't exist!"<<endl; return false;}
        //Находим одителя данного узла
        Node* helpNode = parentNode(necessaryNode, currentNode);
        //Сначала проверяем, есть ли этот элемент + получаем его значение
        
        //Наверное вот тут где-то нужно начать переход к нашему родителю
        DeleteNode(necessaryNode, helpNode);

        return true;
    }
    //========================================
    
    //1. Preorder: прямой обход
    //корень → левое поддерево → правое поддерево
    //1 → 2 → 4 → 5 → 3
    void preorder(Node* currentNode){
        cout<<currentNode->data<<" ";
        if(currentNode->left != nullptr) preorder(currentNode->left);
        if(currentNode->right != nullptr) preorder(currentNode->right);
    }

    //2. Inorder: симметричный обход
    //левое поддерево → корень → правое поддерево
    //4 → 2 → 5 → 1 → 3
    void inorder(Node* currentNode){
        if(currentNode->left != nullptr) inorder(currentNode->left);
        cout<<currentNode->data<<" ";
        if(currentNode->right != nullptr) inorder(currentNode->right);
    }

    
    //3. Postorder: обратный обход
    //левое поддерево → правое поддерево → корень
    //4 → 5 → 2 → 3 → 1   
    void postorder(Node* currentNode){
        if(currentNode->left != nullptr) postorder(currentNode->left);
        if(currentNode->right != nullptr) postorder(currentNode->right);
        cout<<currentNode->data<<" ";
    }

    //4. Обход по уровням
    //1 → 2 → 3 → 4 → 5
    bool levelorder(Node* currentNode){
        if(currentNode == root && root == nullptr){
            cout<<"Tree if empty! Nothing to print!";
            return false;
        }

        //Сначала выводим первый уровень, дерево
        if(currentNode == root) cout<<currentNode->data<<" ";
           
        //Потом выводим его наследников (если они есть)
        if(!(currentNode->left == nullptr && currentNode->right == nullptr)){
            if(currentNode->left != nullptr) cout<<currentNode->left->data<<" ";
            if(currentNode->right != nullptr) cout<<currentNode->right->data<<" ";
        }
        else return false;
        
        //Переход по ветвям
        //Осталось добавить проверку на существование направлений
        if(currentNode->left != nullptr){
            if(!(levelorder(currentNode->left))) {
                if(currentNode->right != nullptr)
                    if(!(levelorder(currentNode->right))) {
                        return false;
                }   
            }
        }
        else{
            if(!(levelorder(currentNode->right))) {
                        return false;
                }   
        }
        
        return false;
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
                Node* helpNode = head->pNext;
                delete head;
                head = helpNode;
                counter--;
                cout<<"The last element of the queue!"<<endl;
            }
            else{
                Node* helpNode = head->pNext;
                delete head;
                head = helpNode;
                counter--;
            }
        }

        bool is_in_the_queue(T necesseryNode){
            Node* currentNode = head;
            bool is_find = false;

            while(currentNode != nullptr){
                if(currentNode->data == necesseryNode){
                    is_find = true;
                    break;
                }
                currentNode = currentNode->pNext;
            }

            if(is_find) return true;

            return false;
        }

        T front(){
            if(head == nullptr){cout<<"Queue is clear!First elemnt is absent!"<<endl; return 0;}
            else{
                return head->data;
            }
        }
        //Вывод количества узлов в очереди
        int GetCountQueue(){ return counter;}

        void Clear(){
            while(counter != 0){
                pop();
            }
        }

        ~Queue(){ Clear();}
        

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

    //Нужно найти иной подход в удалении элементов
    bool Clear(Node* currentNode){

        if(currentNode == nullptr) return true;
        if(currentNode->left == nullptr && currentNode->right == nullptr && currentNode == root){
            delete root;
            root = nullptr;
            return true;
        }   
        else if(currentNode->left == nullptr && currentNode->right == nullptr) return false;
        
        //Переход по ветвям
        //Осталось добавить проверку на существование направлений
        if(currentNode->left != nullptr){
            if(!(Clear(currentNode->left))) {
                delete currentNode->left;
                currentNode->left = nullptr;
                if(currentNode->right != nullptr)
                    if(!(Clear(currentNode->right))) {
                        delete currentNode->right;
                        currentNode->right = nullptr;
                        if(currentNode == root){
                            delete root;
                            root = nullptr;
                            count_of_Node = 0;
                            return true;
                        }
                        return false;
                }   
            }
        }
        else{
            if(!(Clear(currentNode->right))) {
                        delete currentNode->right;
                        currentNode->right = nullptr;
                        return false;
                }   
        }
        return false;
    }

    //Стандартный деструктор
    ~binary_tree(){ Clear(root);}
private:
    Node* root;
    int count_of_Node;
    //Внутри будет очередь указателей на узлы
    Queue<Node*> que;

    //========================================
    //Вспомогательный методя для удаления
    bool DeleteNode(Node* childNode, Node* parentNode){
        //2 варианта, когда есть левый и когда нету левого
        //1 шаг - делаем рекурсию в одну из сторон
        //просто копируем значения, удаляем только последний узел
        //Тут нужно проверять 
        if(!(childNode->left == nullptr && childNode->right == nullptr)){
            //Тут надо понять у кого мы будем забирать значение
            //И к нему же будем переходить, чтобы он отнимал значение у следующего своего элемента
            if(childNode->left != nullptr){
                childNode->data = childNode->left->data;
                DeleteNode(childNode->left, childNode);
            }
            else{
                childNode->data = childNode->right->data;
                DeleteNode(childNode->right, childNode);
            }
        }
        //Если у узла нету наследников(это значит он является листом!)
        //Значит мы не мелочимся и напрямую работаем с полями, без промежуточного указателя
        else{
            if(parentNode->left == childNode){
                parentNode->left = nullptr;
                //Заносим узел в очередь, чтобы он заполнялся самым первым в очереди(для нормализации)
                if(!(que.is_in_the_queue(parentNode))){que.push_front(parentNode); }
                delete childNode;
                count_of_Node--;
                return true;
            }
            else{
                parentNode->right = nullptr;
                //Заносим узел в очередь, чтобы он заполнялся самым первым в очереди(для нормализации)
                if(!(que.is_in_the_queue(parentNode))){que.push_front(parentNode); }
                delete childNode;
                count_of_Node--;
                return true;
            }
        }
        return false;
    }
    //========================================
};


int main() {
    //setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    cout<<endl;
    binary_tree bt(55);
    for (int i = 0; i < 7; i++)
    {
       bt.Insert(rand()%100+1, bt.GetRoot());
    }
    cout<<endl;
    

    bt.preorder(bt.GetRoot());
    cout<<endl;
    bt.inorder(bt.GetRoot());
    cout<<endl;
    bt.postorder(bt.GetRoot());
    cout<<endl;
    bt.levelorder(bt.GetRoot());
    cout<<endl;


    cout<<"==========="<<endl;
    bt.Clear(bt.GetRoot());
    bt.levelorder(bt.GetRoot());
    cout<<endl;


    cout<<"==========="<<endl;
    return 0;
}
