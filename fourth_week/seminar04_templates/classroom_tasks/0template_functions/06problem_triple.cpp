/*
    Задача:

        Напишите шаблонную функцию T triple(T x), которая будет принимать на вход объект типа T,
        умножать его на 3 и возвращать результат:

        triple(3);      // вернёт 9 (int)
        triple(1.5)     // вернёт 4.5 (double)

        triple(std::string("cat")) // вернёт catcatcat (std::string)
*/




#include <iostream>
#include <string>

template <typename T>
T triple(T x)
{
    return x * 3;
}
int main() 
{
    std::cout << triple(3.4) << std::endl;

}
