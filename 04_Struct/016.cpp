#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 16. Студент
 Создать:
 Student
     name
     age
     averageGrade
 Создать массив студентов и найти лучшего.
 Тренирует: struct, массив структур, поля.
 Зачем: переход от примитивных данных к собственным типам
 */

struct Student{
    static int count;
  
    Student(int age, string name, double avarageGrade){
        this->age = age;
        this->name = name;
        this->avarageGrade = avarageGrade;
        count++;
    }
    void GetInfo(){
        cout<<name<<" "<<age<<" y.o. avgGrade is "<<avarageGrade<<endl;
    }
    
    double GetAvgGrade(){
        return avarageGrade;
    }
    
private:
    int age;
    string name;
    double avarageGrade;
    
};

int Student::count = 0;

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));

    int theBest;
    double grade = 0.0;
    Student student[]{
        Student(18, "Egor", 3.7),
        Student(18, "Denis", 4.2),
        Student(18, "Eugeni", 4.8)
    };
    
    
    for (int i = 0; i < Student::count; i++) {
        student[i].GetInfo();
        if(student[i].GetAvgGrade() > grade){
            grade = student[i].GetAvgGrade();
            theBest  = i;
        }
    }
    cout<<endl;
    
    cout<<"The best student is ";
    student[theBest].GetInfo();
    cout<<endl;
   
    return 0;
}
