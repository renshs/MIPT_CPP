/*
    Итератор std::back_insert_iterator

    std::back_insert_iterator<Container> – это специальный итератор у которого операторы перегружены по другому. 
    Для него:

        – operator*     ничего не делает

        – operator++    ничего не делает

        – operator=     вызывает метод push_back контейнера

    Благодаря таким перегрузкам поведение этого итератора сильно отличается от поведения обычных итераторов. 
    К примеру, следующий код добавит в контейнер a ещё один элемент:

        std::vector<int> a { 1, 2, 3 };
        std::back_insert_iterator<std::vector<int>> it{a};
        *it = 4;

    Так как тип этого итератора может иметь длинное название, то была введена функция под названием
    std::back_inserter, которая принимает на вход контейнер и возвращает такой итератор.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout, std::endl;

template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

template <typename T>
void append(std::vector<T>& src, const std::vector<T>& source) {
    std::copy(source.begin(), source.end(), std::back_inserter(src));
}

int main()
{
    std::vector<int> a { 4, 8, 15, 16, 23, 42 };
    std::vector<std::string> vs {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Chameleon", "Iguana", "Bat", "Mouse", "Cow"};
    std::vector<std::string> vvs {"trt", "trr"};
    std::vector<int> b;
    std::vector<std::string> new_vs;

    printVector(a);
    printVector(b);
    
    std::copy(a.begin(), a.end(), std::back_inserter(b));
    printVector(b);

    std::copy_if(vs.begin(), vs.end(), std::back_inserter(new_vs), [](std::string str){return str[0] == 'C';});

    printVector(new_vs);
    append(vs, vvs);
    printVector(vs);
}


/*
    Задачи:

        1)  Пусть есть такой вектор строк:

                std::vector<std::string> vs {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Chameleon", "Iguana", "Bat", "Mouse", "Cow"};

            Создайте новый вектор строк, и скопируйте в него все строки, начинающиеся на символ 'C'.

        2)  Напишите функцию append, которая будет принимать 2 вектора. Первый вектор эта функция должна принимать по ссылке, 
            а второй – по константной ссылке. Функция должна копировать всё содержимое второго вектора в первый с помощью функции std::copy.
*/
