#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 23. Rectangle
 Поля:
 width - ширина
 height - высота
 Методы:
 Area()
 Perimeter()
 Тренирует: класс + вычисления.
 */

class Rectangle{

    int width;
    int height;
public:
    Rectangle(){
        this->width = 0;
        this->height = 0;
    }
    Rectangle(int width, int height){
        this->width = width;
        this->height = height;
    }
    
    double Area(){
        return width * height;
    }
    
    double Perimeter(){
        return 2 * (width + height);
    }
};


int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    Rectangle rst(rand()%100+1, rand()%100+1);
    cout<<"Area - " << rst.Area() << endl;
    cout<<"Perimetr - " << rst.Perimeter() << endl;
   
    
    return 0;
}
