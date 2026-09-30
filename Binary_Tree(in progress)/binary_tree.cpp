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

 Пришел к тупику своего метода, ничего не получится, 
 нужно менять подход, либо действительно очередь либо целочисленные параметры глубины
 
Код после 5 часа 33 минуты чистой проги

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
    
    //Пробуем адаптировать вывод под ввод!
    bool Insert2(int data, Node* currentNode){
        //Начинаем как всегда с корня
        //Node* currentNode = root;
        //При отсутствии корня добавляем его
        if(currentNode == nullptr){
            cout<<"====Добавляем корень дерева!==="<<endl;
            currentNode = new Node(data);
            count_of_Node++;
            //И выходим, действие выполнено
            return 0;
        }
        else{
        //все же попробуем хранить численные данные о грубине левой и правой ветки
            
            //Спрашиваем, есть ли у узла наследники - добавляем туда элементы, если пусто
            if(!(currentNode->left != nullptr && currentNode->right != nullptr)){
                //Узнаем где именно пусто - добавляем элемент туда
                if(currentNode->left == nullptr){
                    cout<<"====Добавляем левый листок!==="<<endl;
                    currentNode->left = new Node(data);
                    return 0;
                }
                else{
                    cout<<"====Добавляем правый листок!==="<<endl;
                    currentNode->right = new Node(data);
                    return 0;
                }
                
            }
            else{
                //Тут сначала нужно сделать циклическую проверку глубины
                //Определить насколько углубляется левая часть если идти чисто в лево + левая часть если идти чисто вправо
                //И пределить насколько углубляется правая часть если идти чисто в лево + правая часть если идти чисто вправо
                
                
                if(currentNode->left->left == nullptr || currentNode->left->right == nullptr){
                    cout<<"====Переходим в левый наследник!==="<<endl;
                    Insert2(data, currentNode->left);
                    return 0;
                }
                else if (currentNode->right->left == nullptr || currentNode->right->right == nullptr){
                    cout<<"====Переходим в правый наследник!==="<<endl;
                    Insert2(data, currentNode->right);
                    return 0;
                }
                else{
                    //Если все заполнено - переходим в левый наследник и занимаемся им
                    //Как нам отсюда попасть в правую часть?
                    currentNode = currentNode->left;
                    Insert2(data, currentNode);
                    //Добавляем глубину
                    return 0;
                    
                }
                
                
                
            }//Конец else
        }
    
        //Заплатка временная
        return 0;
        
    }//Конец нащего вывода
    
    //Сложно
    int Order(Node* currentNode){
        //Мы автоматически передаем сразу корень
        //Выводим корень в первом же проходе
        if(currentNode == nullptr){
            return 0;
        }
        //Спрашиваем - есть ли у этого узла наследники?
        if(!(currentNode->left == nullptr && currentNode->right == nullptr)){
            //Первым делом мы выводим этот элемент, а далее разбираемся с ним
            cout<<currentNode->data<<" ";
            
            //Просматриваем его наследников, выводим
            if(currentNode->left != nullptr){
                cout<<endl;
                //Выводим его в том случае, если у него нету корней - чтобы не было повторов
                if(currentNode->left->left == nullptr && currentNode->left->right == nullptr){cout<<currentNode->left->data<<" ";}
                Order(currentNode->left);
                if(currentNode->right != nullptr){
                    if(currentNode->right->left == nullptr && currentNode->right->right == nullptr){cout<<currentNode->right->data<<" ";}
                    Order(currentNode->right);
                }
            }
            else if(currentNode->right != nullptr){
                Order(currentNode->right);
            }
            
            if(currentNode != root){
                currentNode = currentNode->left;
                cout<<endl;
                return Order(currentNode);
            }
            
            
        }
        
        //Вывод корня, если у него нету наследников
        else if(currentNode == root){
            cout<<currentNode->data<<" ";
        }
        //Вывод на случай того, что корень является листком дерева
        return 0;
    }//Конец нащего вывода
    
    //Нам нужен метод, который будет безопасно возвращать корень дерева
    Node* GetRoot(){ return root;}
private:
    Node* root;
    int count_of_Node;
    
};

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));

    binary_tree bt(55);
    bt.Insert2(rand()%100+1, bt.GetRoot());
    bt.Insert2(rand()%100+1, bt.GetRoot());
    cout<<endl;
    bt.Insert2(rand()%100+1, bt.GetRoot());
    bt.Insert2(rand()%100+1, bt.GetRoot());
    cout<<endl;
    bt.Insert2(rand()%100+1, bt.GetRoot());
    bt.Insert2(rand()%100+1, bt.GetRoot());
    cout<<endl;
    //Вот это уже не добавляется, так как первый уровень листьев заполнен
    //Что делать дальше в этом случае?
    //Как понять куда двигаться?
    
    //Заполнение ячеек 9 - 12
    bt.Insert2(rand()%100+1, bt.GetRoot());
    bt.Insert2(rand()%100+1, bt.GetRoot());
    bt.Insert2(rand()%100+1, bt.GetRoot());
    bt.Insert2(rand()%100+1, bt.GetRoot());
    cout<<endl;
    
    //
    bt.Insert2(rand()%100+1, bt.GetRoot());
    
    
    
    //Нужно научиться работать вообще без GetRoot
    bt.Order(bt.GetRoot());
    return 0;
}
