#include <iostream>
#include <vector>
#include <span>

// Рассмотрим различные способы передачи вектора в функцию
// Для примера рассмотрим функцию, которая печатает вектор
// Но данные способы применимы при любой передаче вектора в функцию


/*
    printArrayCStyle принимает массив в стиле C
    Теоретически, эту функцию можно использовать для печати вектора
    Она хороша по быстродействию, но использовать 
    её для печати вектора, очевидно, очень плохая идея.

    Во-первых, это может привести к ошибкам, если вы ошибётесь с указанием размера.
    Во-вторых, постоянно передавать 2 аргумента в функцию неудобно
        особенно, если сама эта функция сама должна передавать данные в другие функции
    В-третьих, передаваемые внутрь функции объекты (int* и int) теряют функциональность вектора
*/
void printArrayCStyle(const int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


/*
    printVectorByValue принимает вектор по значению
    В этом случае вызывается конструктор копирования вектора
    и всё содержимое вектора копируется.

    Очевидно, это очень медленный способ передачи вектора.
    Так делать нельзя.
*/
void printVectorByValue(std::vector<int> v)
{
    for (int el : v)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}


/*
    printVectorByPointer принимает указатель на объект вектор
    В этом случае вектор не копируется, а передаётся лишь указатель на него

    Это не самый удобный способ передачи вектора в функцию, так как
    для использования вектора придётся всегда разыменовывать указатель.
    Более того в функцию нужно передавать не сам вектор, а его адрес

    По быстродействию это, конечно, намного лучше передачи по значению,
    но немножко медленней, чем передача в стиле C
    Потому что, для того чтобы доступиться до данных нам нужно сделать 2 разыменования:
        1) Разыменовать указатель pv, чтобы доступиться до объекта std::vector
        2) Объект std::vector хранит указатели на данные в Куче. Чтобы дойти до данных
           в Куче нужно ещё одно разыменование
*/
void printVectorByPointer(const std::vector<int>* pv)
{
    for (int el : *pv)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}


/*
    printVectorByPointer принимает ссылку на объект вектор
    В этом случае вектор не копируется, а передаётся лишь ссылка на него

    Это удобный и эффективный способ передачи вектора в функцию
    
    Так как ссылка под капотом является просто указателем
    То для того чтобы доступиться до данных и в данном случае нужно
    будет сделать 2 разыменования. Только в этом случае они будут скрытыми.

    Таким образом и этот способ чуть менее быстрый, чем передача в стиле C
*/
void printVectorByReference(const std::vector<int>& v)
{
    for (int el : v)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}



/*
    printSpan принимает специальный легковесный объект типа std::span
    Объект типа std::span хранит в себе указатель на первых элемент и размер
    Он может конструироваться от обычных массивов, векторов, других контейнеров, итераторов и т. д.
    
    Передаём по значению, так std::span очень маленький.
    Так как std::span хранит указатель на данные, то нужно будет лишь одно разыменование.
    Для std::span применимы многие алгоритмы STL

    Этот способ совмещает в себе скорость обычных массивов в стиле C и удобство std::vector
*/
void printSpan(std::span<int> s)
{
    for (int el : s)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}



int main()
{
    std::vector<int> v {4, 8, 15, 16, 23, 42};


    std::cout << "Sizeof vector = " << sizeof(std::vector<int>) << std::endl;
    std::cout << "Sizeof span   = " << sizeof(std::span<int>) << std::endl;

    printArrayCStyle(v.data(), v.size());

    printVectorByValue(v);

    printVectorByPointer(&v);

    printVectorByReference(v);

    printSpan(v);
}
