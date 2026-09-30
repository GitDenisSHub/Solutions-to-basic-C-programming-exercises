#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 17. Книга
 Создать Book:
 title
 author
 year
 price
 Найти самую дорогую книгу.
 Тренирует: структуры и функции, работающие со структурами.
 */

struct Book{
    static int count;
    
    Book(string title, string author, int year, int price){
        this->title = title;
        this->author = author;
        this->year = year;
        this->price = price;
        
        count++;
    }
    
    int GetPrice(){
        return price;
    }
    
    void GetInfo(){
        cout<<"The title: " << title << " Author: " << author << " year: " << year << endl;
    }
private:
    string title;
    string author;
    int year;
    int price;
};
int Book::count = 0;

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    Book book[]{
        Book("The first book", "The first author", 1990, 580),
        Book("The second book", "The second author", 1900, 1800),
        Book("The third book", "The third author", 2013, 320),
        Book("The fourth book", "The fourth author", 1999, 800),
        Book("The fifth book", "The fifth author", 1978, 670)
    };
    
    int max_price = 0, necessary_book;
    for (int i = 0; i < Book::count; i++) {
        if(book[i].GetPrice() > max_price){
            max_price = book[i].GetPrice();
            necessary_book = i;
        }
    }
    
    cout<<"The max price has: "<<endl; book[necessary_book].GetInfo();

   
    return 0;
}
