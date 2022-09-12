/*
    Инкапсуляция - это объединение данных и функций для работы с ними

    Объекты-данные, составляющие наш объект, называются полями
    Функции для работы с этими данными называются методами
    То есть у структуры Book из этого примера есть 3 поля (title, price и pages) и 2 метода (makeDiscount и print)


    Сравните код в этом файле с кодом из предыдущего файла и обратите внимание на следующие моменты:

    1)  Функции для работы со структурой сейчас объявляются внутри структуры. 
        Получается методы как-бы принадлежат самой структуре
        Это делает невозможным использование этих функций (случайно или намерено) для работы с объектами других типов.

    2)  Вызов методов осуществляется с помощью точки, то есть такой вызов из прошлого файла:
            makeDiscount(b, 500);
        заменился на такой:
            b.makeDiscount(500);
    
        То есть объект как бы сам вызывает функцию для работы со своими данными, а не передаётся первым аргументом в функцию.


    3)  Методы "знают" о том объекте, который их вызвал
        
        Например, в методе makeDiscount используется поле price без указания объекта, которому принадлежит это поле
        Но метод сам "знает" какой объект его вызвал, поэтому если его вызывает объект a вот так:
            a.makeDiscount(500);
        то в этом случае метод использует поле price объекта a


    4)  Константный метод не меняет полей вызывающего объекта. 
        Чтобы указать, что метод является константным нужно написать const в конце объявления метода

        В предыдущем файле при передаче по константной ссылке передаваемый объект не мог измениться внутри функции
            void printBook(const Book& b)    ->     printBook(b)    не изменит b

        Аналог этого для константного метода:
            void print() const               ->     b.print()       не изменит b
        Следовательно, внутри константного метода нельзя менять поля объекта

*/

#include <iostream>

struct Book 
{
    char title[100];
    float price;
    int pages;

    void makeDiscount(int discount) 
    {
        if (price > discount)
            price -= discount;
        else
            price = 0;
    }

    void print() const
    {
        std::cout << title << ", price = " << price << ", pages = " << pages << std::endl;
    }
};



int main() 
{
    Book a = {"War and Peace", 1700, 900};
    Book b = {"The Master and Margarita", 600, 400};

    a.print();
    a.makeDiscount(500);
    a.print();
}

/*
    Задачи:

        1)  Напечатайте книгу b

        2)  Сделайте скидку для книги b в 1000 рублей и напечатайте её ещё раз

        3)  Напишите метод  void setPrice(float newPrice)  который будет задавать новую цену книги
            Вызовите этот метод для книги b и установите её цену в 1000 рублей. Напечатайте книгу ещё раз.

        4)  Попробуйте изменить поле внутри константного метода print, к какой ошибке это приведёт?

        5)  Можно ли вызвать метод makeDiscount из константного метода?

*/
