#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;



/*
 35. Система сотрудников
 Employee
  ├── Developer
  ├── Manager
  └── Designer
 У каждого свой способ расчёта зарплаты.
 Тренирует: наследование + полиморфизм.

 */

class Employee{
    
public:
    virtual void Payment() = 0;
};

class Developer : public Employee{
    
public:
    void Payment(){
        cout<<"A very big salary!"<<endl;
    }
    
};
class Manager : public Employee{
    
public:
    void Payment(){
        cout<<"A very small salary!"<<endl;
    }
};
class Designer : public Employee{
    
public:
    void Payment(){
        cout<<"Not bad salary!"<<endl;
    }
};


int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
   
    Employee* worker[3];
    Developer dev;
    Manager man;
    Designer des;
    
    worker[0] = &dev;
    worker[1] = &man;
    worker[2] = &des;
    
    for (int i = 0; i < 3; i++) {
        worker[i]->Payment();
    }
    
    return 0;
}
