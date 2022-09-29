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

    T m_first;
    D m_second;

    Pair (const T& first, const D second) {
        m_first = first;
        m_second = second;
    }

    bool operator<(const Pair r) const {
        if (m_first == r.m_first) {
            return m_second < r.m_second;
        }
        return m_first < r.m_first;
    }

    bool operator>(const Pair r) const {
        if (m_first == r.m_first) {
            return m_second > r.m_second;
        }
        return m_first > r.m_first;
    }

    bool operator<=(const Pair r) const {
        if (m_first == r.m_first) {
            return m_second <= r.m_second;
        }
        return m_first <= r.m_first;
    }

    bool operator>=(const Pair r) const {
        if (m_first == r.m_first) {
            return m_second >= r.m_second;
        }
        return m_first >= r.m_first;
    }








};
int main()
{
    Pair a {5, std::string("Cat")};
    cout << a.first << " " << a.second << endl;

    cout << std::boolalpha;
    cout << (a > Pair{5, std::string("Dog")}) << endl;
    cout << (a > Pair{5, std::string("Ant")}) << endl;
}
