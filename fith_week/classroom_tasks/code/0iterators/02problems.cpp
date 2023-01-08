#include <iostream>
#include <vector>
using std::cout, std::endl;


int main () 
{
    std::vector<int> v = {54, 62, 12, 97, 41, 62, 73, 10, 59, 92};

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        if (*it % 2 == 0) {
            cout << *it << endl;
        }
    }

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it+=2) {
        cout << *it << ' '; 
    }

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        *it+=1;
    }
    cout << endl;

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
}


/*
    Задачи:
    
        Используйте итераторы во всех следующих задачах:

        1)  Напечатайте только чётные элементы вектора

        2)  Напечатайте каждый второй элемент вектора

        3)  Увеличьте все элементы вектора на 1

        4)  Напишите функцию inc, которая будет принимать на вход вектор целых чисел типа int 
            и будет увеличивать все элементы на 1.

        5)  Напечатать содержимое вектора в обратном порядке.
*/
