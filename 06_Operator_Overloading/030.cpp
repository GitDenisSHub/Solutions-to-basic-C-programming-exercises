#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

/*
 30. String
 Создать собственный класс строки с динамическим char*.
 Реализовать:
     • конструктор;+
     • копирование;+
     • присваивание;
     • +;
     • ==;
     • [].
 Тренирует: практически всё самое неприятное из управления ресурсами.
 */

class String{
    char* str;
    friend ostream& operator<<(ostream& out, const String& another);
    friend istream& operator>>(istream& fin, String& another);
public:
    
    String()
    : str(nullptr){ cout<<"Вызван конструктор по умолчанию!"<<endl;}
    
    String(char* str)
    {
        cout<<"Вызван конструктор с параметром!"<<endl;
        int size = (int)strlen(str) + 1;
        this->str = new char[size];
        for (int i = 0; i < size-1; i++) {
            this->str[i] = str[i];
        }
        this->str[size - 1] = '\0';
    }
    
    String(const String& another){
        cout<<"Вызван конструктор копирования"<<endl;
        int size = (int)strlen(another.str) + 1;
        this->str = new char[size];
        for (int i = 0; i < size - 1; i++) {
            this->str[i] = another.str[i];
        }
        this->str[size - 1] = '\0';
        
    }
    
    String& operator=(const String& another){
        cout<<"Вызов оператора присвоить!"<<endl;
        
        if(this != &another){
            delete[] this->str;
            int size = (int)strlen(another.str) + 1;
            this->str = new char[size];
            for (int i = 0 ; i < size - 1 ; i++) {
                this->str[i] = another.str[i];
            }
            this->str[size - 1] = '\0';
        }
        return *this;
    }
    
    String& operator=(String&& another){
        
        delete[] this->str;
        this->str = another.str;
        another.str = nullptr;
        
        return *this;
    }
    
    String operator+(const String& another){
        cout<<"Вызыван оператор конкатенации!"<<endl;
        char* result = "";
        int size1 = (int)strlen(this->str);
        int size2 = (int)strlen(another.str);
        int size = size1+size2 + 1;
        result = new char[size];
        
        for (int i = 0; i < size1; i++) {
            result[i] = this->str[i];
        }
        for (int i = size1, j = 0; i < size - 1; i++, j++) {
            result[i] = another.str[j];
        }
        result[size - 1] = '\0';
        
        return String(result);
    }
    
    String(String&& another){
        cout<<"Вызван конструктор перемещения!"<<endl;
        this->str = another.str;
        another.str = nullptr;
    }
    
    bool operator==(const String& another){
        int size1 = strlen(this->str);
        int size2 = strlen(another.str);
        
        if(size1 != size2){
            return false;
        }
        else{
            for (int i = 0; i < size1; i++) {
                if(this->str[i] != another.str[i]){
                    return false;
                }
            }
            return true;
        }
    }
    
    char& operator[](int index){
        
        return this->str[index];
    }
        
    ~String()
    {
        if(this->str != nullptr){
            delete[] this->str;;
        }
        cout<<"Вызван деструктор"<<endl;
    }
    
};

ostream& operator<<(ostream& out, const String& another){
    
    if(another.str != nullptr){
        out << another.str;
        return out;
    }
    
    return out;
}

istream& operator>>(istream& fin, String& another){
    delete[] another.str;
    another.str = new char[100];
    fin.getline(another.str, 100);
    return fin;
}

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
   
    String str;
    String str2("Hello!");
    String str3("World!");
    String str4(str2);
    
    str = str2 + str3;
    
    cout << (str4 == str3) << endl;
    
    str2[2] = 'x';
    cout << str2[2] << endl;
 
    cout<<"First - "<<str<<endl;
    cout<<"Second - " << str2<<endl;
    cout<<"Third - " << str3 << endl;
    cout<<"Fouth - " << str4 << endl;
    
    
    
    return 0;
}
