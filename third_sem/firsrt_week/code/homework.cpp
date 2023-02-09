#include <iostream>
#include "vector3f.h"
#include "complex.h"

using namespace std;

struct Color
{
    unsigned char r, g, b;
};

struct Book
{
    char title[100];
    int pages;
    float price;
};

namespace myspace
{
    void print_n_times(char str[], int n = 10)
    {
        for (auto i = 0; i < n; i++)
        {
            cout << str << endl;
        }
    }

    void cubeR(int &n)
    {
        n = n * n * n;
    }

    int cubeV(int n)
    {
        return n * n * n;
    }

    void count_letters(char str[], int &n_letters, int &n_digits, int &n_other)
    {
        for (; *str; ++str)
        {
            if (isdigit(*str))
            {
                n_digits++;
            }
            else if (isalpha(*str))
            {
                n_letters++;
            }
            else
            {
                n_other++;
            }
        }
    }

    void addPrice(Book &b, float price)
    {
        b.price = price;
    }

    bool isExpensive(Book &b)
    {
        return b.price > 1000;
    }
}

Complex function(Complex z, Complex c, int x)
{
    if (x >= 20) {
        return z;
    } else {
        return function(z * z + c, c, x + 1);
    }

}

void julia(Complex c, int n)
{
    int width = 800, height = 800;
    float x0 = -2.0f, x1 = 2.0f;
    float y0 = -2.0f, y1 = 2.0f;

    // Выделяем память под пиксели
    Color *data = (Color *)malloc(sizeof(Color) * width * height);

    // data - это массив цветов размером width * height
    // Задаём значения этого массива так, чтобы
    // реальная часть функции func соответствовала зелёному цвету,
    // а мнимая часть -- синей компоненте цвета

    Complex num = {1, 1};

    double  max = 0;
    
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            Complex z = {x0 + (x1 - x0) / width * i, y0 + (y1 - y0) / width * j};
            Complex f = function(z, c, 1);

            if (max < abs(f)) {
                max = abs(f);
            }
            
            data[i + width * j].r = 255 - abs(f);
            data[i + width * j].g = 255 - abs(f);
            data[i + width * j].b = 255 - abs(f);
        }
    }

    cout << "max is " << max << endl;

    // Сохраняем массив цветов data как картинку в формате .ppm
    FILE *file = fopen("julia.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, file);
    fclose(file);
}


void mandelbrot(Complex c, int n)
{
    int width = 800, height = 800;
    float x0 = -2.0f, x1 = 2.0f;
    float y0 = -2.0f, y1 = 2.0f;

    // Выделяем память под пиксели
    Color *data = (Color *)malloc(sizeof(Color) * width * height);

    // data - это массив цветов размером width * height
    // Задаём значения этого массива так, чтобы
    // реальная часть функции func соответствовала зелёному цвету,
    // а мнимая часть -- синей компоненте цвета

    Complex num = {1, 1};

    double  max = 0;
    
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            Complex z = {x0 + (x1 - x0) / width * i, y0 + (y1 - y0) / width * j};
            Complex f = function(z, c, 1);

            if (max < abs(f)) {
                max = abs(f);
            }
            
            data[i + width * j].r = 255 - abs(f);
            data[i + width * j].g = 255 - abs(f);
            data[i + width * j].b = 255 - abs(f);
        }
    }

    cout << "max is " << max << endl;

    // Сохраняем массив цветов data как картинку в формате .ppm
    FILE *file = fopen("mandelbrot.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, file);
    fclose(file);
}



int main(int argc, char* argv[])
{
    Complex c = {-0.7, -0.38};
    int n = 20;
    if (argc > 1)
    {
        c.re = stof(argv[1]);
        c.im = stof(argv[2]);
        n = stoi(argv[3]);
    }
    julia(c, n);
    return 0;
}