/*
    Direct initialization

    Выглядит вот так:

        type a{arg1, ...};       или так    type a(arg1, ...);

    Объекты инициализируются так:
    
        1)  Обычные типы - передаём один аргумент и инициализируем им

        2)  Классы - вызывается конструктор с подходящими типами параметров, если его нет, то ошибка.

        3)  Агрегаты - каждый элемент агрегата инициализируется с помощью copy initialization
                                        
*/

#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

struct Book
{
    string title;
    int pages;
    float price;
};

class Cat
{
private:
    string mname {};
    int mage     {};

public:
    Cat()   {cout << "Cat Default Constructor (" << mname << ")" << endl;}
    ~Cat()  {cout << "Cat Destructor ("          << mname << ")" << endl;}
    Cat(const Cat& c)                : mname(c.mname), mage(c.mage) {cout << "Cat Copy Constructor (" << mname << ")" << endl;}
    Cat(const string& name, int age) : mname(name),    mage(age)    {cout << "Cat Constructor ("      << mname << ")" << endl;}
    void setName(const std::string& name) {mname = name;};
    void say(){cout << "Meow, I am " << mname << endl;}
};




int main()
{
    int a{5}; // обычный
    
    Cat b{"Alice", 10}; // класс

    Book c{"Harry Potter", 400, 600.0}; // агрегат

    Cat d[2]{{"Casper", 5}, {"Cleo", 6}}; // агрегат
}

