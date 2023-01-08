/*
    Алгоритмы с компараторами
    
    find_if(it1, it2, f)    -   возвращает итератор на первый элемент, для которого f(el) возвращает true

    count_if(it1, it2, f)   -   ищет количество элементов, для которого f(el) возвращает true


    Например, данная программа печатает количество чётных элементов.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<std::string> v {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Lion", "Iguana", "Bat", "Mouse", "Oak"};


    cout << std::count_if(v.begin(), v.end(), [](std::string el){return el[0] == 'C';}) << endl;
}


/*
    Задачи:

        1)  Пусть у нас есть некоторый вектор строк
            Напечатайте следующее:

                a)  Количество строк в векторе, имеющие размер в 3 символа

                b)  Количество строк в векторе, начинающиеся на букву C
                
                c)  Количество строк в векторе, начинающиеся со строки "Cat"


            Для следующего вектора:
            
                std::vector<std::string> v {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Lion", "Iguana", "Bat", "Mouse", "Oak"};

            результаты будут такие:

                4
                3
                2
*/
