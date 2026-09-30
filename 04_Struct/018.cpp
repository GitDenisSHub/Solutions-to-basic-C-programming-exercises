#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 18. Точка
 Создать Point с x и y.
 Написать функцию, которая вычисляет расстояние между двумя точками.
 Тренирует: собственные типы, функции с объектами.
 Зачем: подготовка к полноценному ООП.
 */

struct Point{

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    
    double GetDistance(const Point& another){
        double a, b;
        a = abs(this->y - another.y);
        b = abs(this->x - another.x);
        return sqrt(a*a + b*b);
    }
  
private:
    int x;
    int y;
    
};


int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
   
    Point pnt(6, 2);
    Point pnt2(18, 8);
    
    cout << "Distance is " << pnt.GetDistance(pnt2) << endl;
    
    return 0;
}
