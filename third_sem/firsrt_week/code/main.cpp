#include <iostream>
#include "vector3f.h"
using namespace std;
int main()
{
    Vector3f a = {1.0, 2.0, -2.0};
    Vector3f b = {4.0, -1.0, 3.0};
    cout << "a = " << a << endl
         << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "-a = " << -a << endl;
    cout << "Scalar product of a and b = " << a * b << endl;
    a /= 5;
    cout << "a after a /= 5; " << a << endl;
    normalize(b);
    cout << "Normalized b:" << b << endl;
    a += b;
    cout << "a after a+= b;" << a << endl;
}