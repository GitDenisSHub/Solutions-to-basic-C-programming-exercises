#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 19. Массив точек
 Найти две наиболее удалённые точки.
 Тренирует: структуры + массивы + алгоритмическое мышление.
 */

struct Point{
    static int count;
    
    Point(){
        this->x = 0;
        this->y = 0;
        count++;
    }

    Point(int x, int y){
        this->x = x;
        this->y = y;
        count++;
    }
    
    void SetParametrs(int x, int y){
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
int Point::count = 0;

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    int num;
    cout<<"How mane points do u want? "; cin>>num;
    
    Point* pnt = new Point[num];
   
    for (int i = 0; i < num; i++) {
        pnt[i].SetParametrs(rand()%100+1, rand()%100+1);
    }
    
    
    double max_distance = 0;
    int first, second;
    for (int i = 0; i < Point::count; i++) {
        for (int j = 0; j < Point::count; j++) {
            if(pnt[i].GetDistance(pnt[j]) > max_distance){
                if(i == j) continue;
                max_distance = pnt[i].GetDistance(pnt[j]);
                first = i;
                second = j;
            }
        }
    }
    
    cout << "Max Distance is " << max_distance << " between: " << first << " and " << second  << " ponts "<< endl;
    
    
    delete[] pnt;
    return 0;
}
