#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 24. Массив объектов
 Создать массив Student и реализовать:
     • поиск лучшего;
     • поиск по имени;
     • сортировку.
 Тренирует: ООП + массив объектов.
 */

class Student{
  
    string Name;
    double Grade;
public:
    Student(string name, double grade){
        Name = name;
        Grade = grade;
    }
    
    void GetInfo(){
        cout << "Name: " << Name << " -- grade: " << Grade << endl;
    }
    string GetName(){
        return Name;
    }
    
    double GetGrade(){
        return Grade;
    }
    
    
    
};

void PrintMenu(){
    cout<<"Whar do you want?"<<endl;
    cout<<R"(
            Find the best - 1
            Name search - 2
            Sort the list - 3
            Skip - 4
            )"<<endl;
}

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    Student stnd[]{
        Student("Denis Sementsov", 3.1),
        Student("Kirill Sementsov", 3.4),
        Student("Elizavets Sementsova", 4.7),
        Student("Sergey Sementsov", 4.3),
        Student("Denis Sementsov", 4.1),
        Student("den", 4),
        Student("Nadya Sementsova", 3.7)
    };
    int Size = sizeof(stnd) / sizeof(stnd[0]);
    
    
    int choice = 0;
    PrintMenu();
    cin >> choice;
    bool is_end = false;
    
    do{
        
        switch (choice) {
            case 1:{
                cout<<"\n======================="<<endl;
                double the_best = 0;
                int position = 0;
                for (int i = 0; i < Size; i++) {
                    if(stnd[i].GetGrade() > the_best){
                        the_best = stnd[i].GetGrade();
                        position = i;
                    }
                }
                cout<<"The best student is ";
                stnd[position].GetInfo();
                cin.ignore();
                cin.get();
                cout<<"\n======================="<<endl;
                PrintMenu();
                cin >> choice;
                if(choice == 4){
                    is_end = true;
                }
                else{
                    is_end = false;
                }
                
                break;
            }
            case 2:{
                cout<<"\n======================="<<endl;
                string Name;
                bool is_find = false;
                cout<<"Enter you name first second" << endl;
                cin.ignore();
                getline(cin, Name);
                for (int i = 0; i < Size; i++) {
                    if(stnd[i].GetName() == Name){
                        cout<<"Name is exist!"<<endl;
                        stnd[i].GetInfo();
                        is_find = true;
                    }
                }
                if(!(is_find)) cout<<"Name isn't exist!"<<endl;
                
                cin.get();
                cout<<"\n======================="<<endl;
                PrintMenu();
                cin >> choice;
                if(choice == 4){
                    is_end = true;
                }
                else{
                    is_end = false;
                }
                break;
            }
               
            case 3:{
                cout<<"\n======================="<<endl;
                cout<<"Сортировка по оценкам: "<<endl;
                
                int* count = new int[Size];
                for (int i = 0; i < Size; i++) {
                    count[i] = -1;
                }
                
                int position = 0;
                int size_of_arr = Size;
                double max_value = 0;
                int count_point = 0;
                bool is_here = false;
                //Внутри нужно найти индекс самого большого элемента
                //Если он найден - сохранить индекс в массив и убрать его из оценивания
                
                while(size_of_arr != 0){
                    for (int i = 0; i < Size; i++) {
                        is_here = false;
                        for (int j = 0; j < Size; j++) {
                            if(count[j] == i){
                                is_here = true;
                            }
                        }
                        if(!(is_here)){
                            if(stnd[i].GetGrade() > max_value){
                                max_value = stnd[i].GetGrade();
                                position = i;
                                count[count_point] = position;
                                
                            }
                        }
                        
                    }
                    
                    count_point++;
                    size_of_arr--;
                    max_value = 0;
                }
                
                for (int i = 0; i < Size; i++) {
                    //cout<<count[i]<<" " <<endl;
                    stnd[count[i]].GetInfo();
                }
                
                
                
                
                
                delete[] count;
                
                cin.ignore();
                cin.get();
                cout<<"\n======================="<<endl;
                PrintMenu();
                cin >> choice;
                if(choice == 4){
                    is_end = true;
                }
                else{
                    is_end = false;
                }
                
                break;
            }
               
            case 4:{
                cout<<"\n======================="<<endl;
                is_end = true;
                break;
            }
                
            default:{
                cout<<"Are u stupid?"<<endl;
                cin.ignore();
                cin.get();
                cout<<"\n======================="<<endl;
                PrintMenu();
                cin >> choice;
                if(choice == 4){
                    is_end = true;
                }
                else{
                    is_end = false;
                }
                break;
            }
                
        }
        
    }while(!(is_end));
    
    
    
    
    
    return 0;
}
