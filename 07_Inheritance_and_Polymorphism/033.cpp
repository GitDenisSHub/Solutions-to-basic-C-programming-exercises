#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

/*
 32. Фигуры
 Базовый:
 Shape
 Производные:
 Circle
 Rectangle
 Triangle
 Каждая имеет:
 Area()
 Тренирует: абстрактные классы и полиморфизм.
 */

class Shape{
    
public:
    virtual void Area() = 0;
};

class Circle : public Shape{
    
public:
    void Area(){
        cout<<" S=πr2 " << endl;
    }
};
class Rectangle : public Shape{
    
public:
    void Area(){
        cout<<" S=a⋅b " << endl;
    }
};
class Triangle : public Shape{
    
public:
    void Area(){
        cout<<" S= 1/2 * (a * h) " << endl;
    }
};



int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
   
    Circle crl;
    Rectangle rst;
    Triangle tri;
    
    
    Shape* shape[3];
    
    shape[0] = &crl;
    shape[1] = &rst;
    shape[2] = &tri;
    
    for (int i = 0; i < 3; i++) {
        shape[i]->Area();
    }
    
    return 0;
}
