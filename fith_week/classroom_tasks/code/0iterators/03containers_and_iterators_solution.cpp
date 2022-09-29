/*
    Контейнеры и итераторы STL

    Помимо вектора std::vector и массива std::array в STL есть множество других контейнеров.
    У этих контейнеров есть свои преемущества по сравнению с вектором.

    Рассмотрим наиболее известные из них:

        1)  std::list - двусвязный список.
            Позволяет добавлять/удалять элементы за O(1).
            Но долгий поиск и долгий доступ по индексу.


        2)  std::set - контейнер, реализуюций абстрактный тип данных Множество.
            Хранит элементы без дубликатов, в отсортированном виде.
            Поиск/вставка/удаление элементов за O(log(N)).
            Практически всегда реализован на основе сбалансированного дерева поиска.


        3)  std::unordered_set - контейнер, реализуюций абстрактный тип данных Множество.
            Хранит элементы без дубликатов, но в произвольном порядке.
            Поиск/вставка/удаление элементов за O(1).
            Практически всегда реализован на основе хеш-таблицы.

    
    У этих контейнеров есть и свои типы итераторов, для работы с их элементами.
    Мы не можем обратиться к элементам этих контейнеров по индексу, у этих контейнеров нет перегруженного operator[]
    Это сделано специально, так как если сделать такой оператор, то он бы долго работал для этих контейнеров.
    Получается, что для работы с элементами этих контейнеров нужно использовать итераторы.

    Для класса std::list<T> тип итератора называется std::list<T>::iterator.
    У итератора std::list<T>::iterator it; перегружены унарные операторы  ++it  --it   *it
    Они перегруженные таким образом, что ++it переходит к следующему элементу, а --it к предыдущему.
    Видно, что итератор связного списка гораздо меньше похож на указатель.
    При увелечении на 1 он не просто смещается на некоторое количество байт в памяти, а именно переходит к следующему элементу.


    Для класса std::set<T> тип итератора называется std::set<T>::iterator и у него также перегруженные
    операторы ++ и -- чтобы они переходили к следующему/предыдущему элементам.
    Так как std::set это двоичное дерево, то оператор++ должен проделать непростую работу, чтобы перейти к следующему элемету.
*/



#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <list>
using std::cout, std::endl;

int main()
{
    std::list l          {70, 10, 40, 30, 80};
    std::set s           {70, 10, 40, 30, 80};
    std::unordered_set u {70, 10, 40, 30, 80};

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;

    for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;

    for (std::unordered_set<int>::iterator it = u.begin(); it != u.end(); ++it)
        cout << *it << " ";
    cout << endl;

}


/*
    Задачи:

        1)  Напишите цикл for, в котором напечатайте все элементы списка l. Для обхода используйте итератор.
        2)  Напишите цикл for, в котором напечатайте все элементы множества s. Для обхода используйте итератор.
        3)  Напишите цикл for, в котором напечатайте все элементы неупорядоченного множества u. Для обхода используйте итератор.

*/