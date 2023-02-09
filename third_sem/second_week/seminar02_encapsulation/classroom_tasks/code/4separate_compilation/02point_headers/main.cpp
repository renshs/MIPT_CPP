/*
    Перенос кода в заголовочный файл

    В этом примере мы перенесли весь код, связанный с классом Point в отдельный файл point.hpp.
    Файл point.hpp подключается к файлу main.cpp с помощью директивы #include в строке:

        #include "point.hpp"

    На самом деле директива #include делает очень простую вещь: она просто берёт всё содержимое
    передаваемого ей файла и вставляет это содержимое на место директивы.
    То есть в этом примере за место  #include "point.hpp"  подставится всё содержимое файла point.hpp.

    Так как директива #include уже сама вставила файл point.hpp в файл main.cpp, то дополнительно
    указывать файл point.hpp при компиляции не нужно. Скомпилировать этот пример можно так:

        g++ main.cpp


    Стандартные библиотеки типа iostream подключаются так же. То есть где-то в системе, в какой-то папке 
    хранится стандартная библиотека C++ и, соответственно, есть файл под название iostream (без расширения).
    Этот файл и подставляется за место строки  #include <iostream>.
    Чтобы посмотреть в каких папках компилятор ищет файлы стандартной библиотеки можно скомпилировать программу так:
        
        g++ -v main.cpp

    Он напечатает множество информации о компиляции, в числе прочего пути где происходит поиск при исполнении #include.
    Вы могли заметить, что стандартные библиотеки в директиве #include пишутся в треугольных скобочках, а нашу
    библиотеку point.hpp мы написали в двойных кавычках. В чём разница между этими вариантами?
    На самом деле разница лишь в том, в каких папках компилятор ищет данные файлы.
    Если мы пишем библиотеку в треугольных скобках, то компилятор ищет её в папках стандартной библиотеки.
    Если мы пишем библиотеку в кавычках, то компилятор ищет её в папках текущей директории.



    Защита от двойного включения

    Используя директивы #include, очень легко включить один и тот же файл 2 и более раз.
    Например, в этом примере файл iostream включается 2 раза: один раз непосредственно в файле main.cpp, а второй раз 
    он включится после того, как включиться файл point.hpp. Внутри файла point.hpp тоже есть #include <iostream>.
    Если не предпринимать никаких действий, то произойдёт ошибка, так как одинаковые функции и классы 
    будут повторяться в программе несколько раз.

    Чтобы защититься от этой проблемы нужно в начале заголовочного файла написать директиву

        #pragma once

    Таким образом компилятор будет понимать, что вы не хотите включать файл более одного раза и включит только одну копию файла.
    Эта директива была использовани и в файле point.hpp.
*/


#include <iostream>
#include "point.hpp"

using std::cout, std::endl;

int main() 
{
    Point a = {7.2, 3.1};
    cout << a.norm() << endl;
}