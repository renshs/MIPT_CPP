/*
   Задача:

   Напишите шаблонный класс пары объектов - Pair, который сможет хранить в себе 2 объекта произвольных типов.
   В этом классе должно быть 2 публичных поля: first и second.
   В поле first должен храниться первый объект, а в поле second - второй.

   Напишите консруктор для этого класса от двух аргументов.
   Также определите для этого класса операторы сравнения. Операторы сравнения должны работать лексикографически.
   То есть сначала сравнивается первые элементы. Если они равны, то сравниваются вторые.

*/

#include <iostream>
using namespace std;
template <typename T, typename D>
class Pair {

    T first;
    D second;

    Pair (const T& first, const D& second) {
        first = first;
        second = second;
    }

    bool operator<(const Pair r) const {
        if (first == r.first) {
            return second < r.second;
        }
        return first < r.first;
    }

    bool operator>(const Pair r) const {
        if (first == r.first) {
            return second > r.second;
        }
        return first > r.first;
    }

    bool operator<=(const Pair r) const {
        if (first == r.first) {
            return second <= r.second;
        }
        return first <= r.first;
    }

    bool operator>=(const Pair r) const {
        if (first == r.first) {
            return second >= r.second;
        }
        return first >= r.first;
    }








};
int main()
{
    Pair<int, std::string> a {5, std::string("Cat")};
    cout << a.first << " " << a.second << endl;

    cout << std::boolalpha;
    cout << (a > Pair{5, std::string("Dog")}) << endl;
    cout << (a > Pair{5, std::string("Ant")}) << endl;
}
