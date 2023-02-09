/*
    std::vector и функции

    У класса std::vector есть конструктор копирования, который копирует вектор полностью: сам объект вектора и
    его элементы, которые хранятся в куче.
    Поэтому передача вектора в/из функции похоже на передачу обычных переменных.

        func(std::vector v)         -  происходит полное копирование вектора
        func(std::vector& v)        -  передача по ссылке
        func(const std::vector& v)  -  передача по константной ссылке
*/

#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;


void printVector(const std::vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

void inc(std::vector<int>& v) {
    for (auto i = 0; i < v.size(); i++) {
        v[i]++;
    }
}

int sum(const std::vector<int>& v) {
    int answer = 0;
    for (auto i = 0; i < v.size(); i++) {
        answer += v[i];
    }
    return answer;
}

std::vector<int>& operator+=(std::vector<int>& v, int a) {
    for (int i = 0; i < v.size(); i++) {
        v[i] += a;
    }
    return v;
}


int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};

    inc(v);

    v += 5;

    cout << sum({100, 200}) << endl;

    printVector(v);
}


/*
    Задачи:

        1)  Напишите функцию inc, которая будет принимать std::vector<int> по ссылке 
            и увеличивать все его элементы на 1.
            Протестируйте эту функцию в main передав её вектор v.
            Можно ли использовать эту функцию следующим образом и почему?

                inc({100, 200, 300});

        2)  Напишите функцию sum, которая будет принимать std::vector<int> по константной ссылке 
            и возвращать сумму всех элементов вектора.
            Протестируйте эту функцию в main передав её вектор v.
            Можно ли использовать эту функцию следующим образом и почему?

                int s = sum({100, 200, 300});


        3)  Напишите функцию std::vector<int> createArithmetic(int start, int d, int n), которая будет
            создавать вектор, содержащий арифметическую прогрессию длины n с элементами:

                start, start + d, start + 2*d, ... start + (n - 1) * d


        4)  Перегрузите оператор += с типами std::vector<int> v и int a.
            Этот оператор должен прибавлять к каждому элементу вектора число a.

                std::vector<int> v {10, 20, 30, 40, 50};
                v += 5;
                printVector(v);

            Должно напечатать  15 25 35 45 55

*/