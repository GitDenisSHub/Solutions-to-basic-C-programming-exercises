#include <iostream>
#include <ctime>
using namespace std;

/*
 27. Класс Point
 Перегрузить:
 +
 -
 ==
 !=
 Тренирует: operator overloading.
 */

class Point{
    int x;
    int y;
    
public:
    Point()
    : x(0), y(0) { cout<<"Конструктор по умолчанию!"<<endl; }
    
    Point(int x, int y)
    : x(x), y(y){ cout<<"Конструктор с параметрами!"<<endl; }
    
    void GetInfo(){ cout<<"X - " << x << ", Y - " << y << endl; }
    
    bool operator==(const Point& another)
    {
        if(this->x == another.x && this->y == another.y){ return true; }
        else{ return false; }
    }
    bool operator!=(const Point& another)
    {
        return !(*this == another);
    }
    
    Point operator+(const Point& another)
    {
        return Point(this->x + another.x , this->y + another.y);
    }
    
    Point operator-(const Point& another)
    {
        return Point(this->x - another.x, this->y - another.y);
    }
    
};
    

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    Point a(5, 10);
    Point v;
    Point b(55, 99);
    Point c(55, 99);
    
    
    cout << (b == c) << endl;
    cout << (b != c) << endl;
    
    a.GetInfo();
    b.GetInfo();
    
    c = b + a;
    
    a.GetInfo();
    b.GetInfo();
    c.GetInfo();
    
    
    return 0;
}
