#include <iostream>
#include <iomanip>
#include <cmath>
#include "point.hpp"

Point Point::operator+(Point b) const
{
    Point result = {x + b.x, y + b.y};
    return result;
}

float Point::norm() const
{
    return std::sqrt(x * x + y * y);
}

Point Point::operator*(float k) const
{
    Point result = {k * x, k * y};
    return result;
}

void Point::normalize()
{
    float normv = norm();
    x /= normv;
    y /= normv;
}


std::ostream& operator<<(std::ostream& out, Point a)
{
    out << std::setprecision(2) << "(" << a.x << ", " << a.y << ")";
    return out;
}