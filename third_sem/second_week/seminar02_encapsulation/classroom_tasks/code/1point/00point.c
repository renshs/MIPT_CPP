/*
    Это программа на языке C, для компиляции:
        gcc 00point.c
        ./a.out

    Опишем структуру точки в двумерном пространстве на языке C

    Точка задаётся двумя координатами x и y
    Так как эта структура имеет очень маленький размер (всего 8 байт), то в функции
    её можно передавать по значению, а не по константному указателю.
*/

#include <stdio.h>
#include <math.h>

struct point 
{
    float x, y;
};
typedef struct point Point;


void point_print(Point a)
{
    printf("(%.2f, %.2f)\n", a.x, a.y);
}

Point point_add(const Point* a, const Point* b) {
    Point answer;
    answer.x = a->x + b->x;
    answer.y = a->y + b->y;
    return answer;
}

float point_norm(const Point* a) {
    return sqrt((a->x) * (a->x) + (a->y) * (a->y));
}

Point point_mult(const Point* a, float k) {
    Point answer = {a->x * k, a->y * k};
    return answer;
}

Point point_normalize(Point* a) {
    
}

int main() 
{
    Point a = {7.2, 3.1};
    Point b = {-4.6, 2.4};
    
    point_print(a);
    point_print(b);
}

/*
    Задачи:
    
        1)  Напишите функцию point_add, 
            которая будет принимать две точки и возвращать их сумму

        2)  Напишите функцию point_norm, 
            которая будет принимать точку и возвращать расстояние до этой точки от начала координат
            Будем называть расстояние от точки до начала координат нормой точки
            Для вычисления корня числа можно использовать функцию sqrt из math.h

        3)  Напишите функцию point_mult, 
            которая будет принимать на вход точку и число k типа float и возвращать точку, координаты которой
            равны координатам изначальной точки, умноженные на число k

        4)  Напишите функцию point_normalize,
            которая будет принимать точку по указателю и делить координаты точки на норму точки
            Эта функция не должна ничего возвращать
*/
