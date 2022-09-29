#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>

/*
   Класс Number -- класс положительных больших чисел

   Большое число будет храниться в динамическом массиве data
   Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления
   (так как base = 100)
   По сути, каждый элемент data хранит две цифры числа в десятичной записи

   Значение 100 для системы счисления выбрано как компромис между
   эффективностью и удобством написания программы.
   Если выбрать значения базы 10 - то программа будет не так эффективна по памяти
   Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
   то алгоритм печати на экран сильно усложнится
   В качестве альтернативы, можно было выбрать базу 1e9, 
   изменив при этом тип элементов c char на int

   capacity - размер массива data
   size - сколько ячеек занимет число в массиве data
   size <= capacity

   Для удобства разряды числа хранятся в обратном порядке
   Например, число 12345678 соответствует массиву
   data = {78, 56, 34, 12}
   (это упрощает многие алгоритмы с такими числами)
   */


class Number 
{
    private:
        static const int base = 100;
        std::size_t size;
        std::size_t capacity;
        char* data;

    public:

        Number(int a) 
        {
            // Находим размер необходимой памяти под это число
            int temp = a;
            capacity = 0;
            while (temp != 0) 
            {
                temp /= base;
                capacity += 1;
            }

            // Отдельно обрабатываем случай, когда число равно 0
            if (capacity == 0) 
                capacity = 1;

            // Выделяем память и записывем число a в массив data
            // Например, число 12345678 представится в виде массива [78, 56, 34, 12]

            data = new char[capacity];

            for (int i = 0; i < capacity; ++i) 
            {
                data[i] = a % base;
                a /= base;
            }

            // В данном случае размер будет равен вместимости
            size = capacity;
        }

        Number()
        {
            size = 1;
            capacity = 2;
            data = new char[capacity];

            data[0] = 0;
        }

        Number(const Number& n)
        {
            size = n.size;
            capacity = n.capacity;
            data = new char[capacity];

            for (auto i = 0; i < size; i++)
            {
                data[i] = n.data[i];
            }
        }

        Number (const char* str)
        {
            size = strlen(str);
            capacity = size + 1;

            data = new char[capacity];

            for (auto i = size - 1; i >= 0; i--)
            {
                data[size - i + 1] = str[i];
            }
        }

        Number& operator=(const Number& right)
        {
            capacity = right.capacity;
            size = right.size;
            data = new char[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = right.data[i];
            }
            return *this;
        }

        Number operator+(Number a)
        {

            Number result;
            Number temp;
            int i;
            int carry = 0;
            if (size < a.size) {
                temp = *this;
                *this = a;
                a = temp;

            }
            result.capacity = size + 1;
            result.data = new char[capacity];
            result.data = (char *) calloc(result.capacity, sizeof(char));
            for (i = 0; i < a.size; ++i) {
                result.data[i] = (data[i] + a.data[i] + carry) % base;
                carry = (data[i] + a.data[i] + carry) / base;
            }
            for (; i < size; ++i) {
                result.data[i] = (data[i] + carry) % base;
                carry = (data[i] + carry) / base;
            }
            if (carry) {

                result.data[i] = carry;
                result.size = size + 1;
            } else {
                result.size = size;
            }

            return result;
        }



        void operator+=(const Number& a)
        {
            *this = *this + a;
        }

        Number operator*(const Number & right) const
        {
            int i, j;
            int temp;
            Number result;

            result.capacity = capacity + right.capacity;
            int *carry = (int *) std::calloc(result.capacity, sizeof(int));

            result.data = (char *) calloc(result.capacity, sizeof(char));

            for (i = 0; i < size; ++i) {
                for (j = 0; j < right.size; ++j) {

                    temp = (result.data[i + j] + data[i] * right.data[j] + carry[i + j]);
                    result.data[i + j] = temp % base;
                    carry[i + j + 1] += temp / base;
                    carry[i + j] = 0;


                }

            }
            if (carry[i + j - 1]) {
                result.data[i + j - 1] = carry[i + j - 1];
                result.size = i + j;

            } else {
                result.size = i + j - 1;

            }
            free(carry);
            return result;

        }

        



        ~Number() 
        {
            delete [] data;
        }


        friend std::ostream& operator<<(std::ostream& stream, const Number& right);

};

Number factorial(int n) {
    Number result = 1;
    for (int i = 2; i < n + 1; i++) {
        result = Number(i) * result; 
    }
    return result;
}

std::ostream& operator<<(std::ostream& stream, const Number & right)
{

    stream << (int) right.data[right.size - 1];

    for (std::size_t i = 0; i < right.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << (int) right.
            data[right.size - 2 - i];

    return stream;

}



int main() 
{
    Number x = 1232424;
    Number y = 1;
    x += 2;
    Number z = x * x;
    std::cout << x << " " << y << std::endl;
    std::cout << x + y << std::endl;
    std::cout << x << std::endl;
    std::cout << z << std::endl;
    std::cout << factorial(1000) << std::endl;
}
