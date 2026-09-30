#include <iostream>
#include <ctime>
using namespace std;

/*
 28. Point + int
 Сделать возможность:
 point + 5
 Тренирует: перегрузку операторов с разными типами.
 */

template <typename T>
class Point{
    T x;
    T y;
    
public:
    Point()
    : x{}, y{} { cout<<"Конструктор по умолчанию!"<<endl; }
    
    Point(T x, T y)
    : x(x), y(y){ cout<<"Конструктор с параметрами!"<<endl; }
    
    void GetInfo(){ cout<<"X - " << x << ", Y - " << y << endl; }
    
    Point operator+(const int value)
    {
        cout<<"Оператор сложения с целым числом!"<<endl;
        return Point(this->x + (T)value , this->y + (T)value);
    }

    
};
    

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    Point a(5.5, 10.5);
    Point<double> b;

    a.GetInfo();
    b.GetInfo();
    
    b = a + 5;
    
    a.GetInfo();
    b.GetInfo();

    return 0;
}
