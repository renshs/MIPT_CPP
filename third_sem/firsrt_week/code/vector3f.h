//Файл с реализацей вектора.
#include <iostream>
#include <math.h>


struct Vector3f {
    float x;
    float y;
    float z;
};

Vector3f operator+(const Vector3f& va, const Vector3f& vb) {
    Vector3f result = va;
    result.x += vb.x;
    result.y += vb.y;
    result.z += vb.z;
    return result;
}

Vector3f operator-(const Vector3f& va, const Vector3f& vb) {
    Vector3f result = va;
    result.x -= vb.x;
    result.y -= vb.y;
    result.z -= vb.z;
    return result;
}

Vector3f operator*(float x, const Vector3f& v) {
    Vector3f result = v;
    result.x *= x;
    result.y *= x;
    result.z *= x;
    return result;
}

Vector3f operator*(const Vector3f& v, float x) {
    Vector3f result = v;
    result.x *= x;
    result.y *= x;
    result.z *= x;
    return result;
}

Vector3f operator/(const Vector3f& v, float x) {
    Vector3f result = v;
    result.x /= x;
    result.y /= x;
    result.z /= x;
    return result;
}


float operator*(const Vector3f& va, const Vector3f& vb) {
    float result = 0;
    result += va.x * vb.x;
    result += va.y * vb.y;
    result += va.z * vb.z;
    return result;
}

Vector3f operator-(Vector3f v) {
    v.x *= -1;
    v.y *= -1;
    v.z *= -1;
    return v;
}

Vector3f operator+(Vector3f v) {
    return v;
}

bool operator==(const Vector3f& va, const Vector3f& vb) {
    if (va.x == vb.x and va.y == vb.y and va.z == vb.z) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const Vector3f& va, const Vector3f& vb) {
    if (va.x != vb.x || va.y != vb.y || va.z != vb.z) {
        return true;
    } else {
        return false;
    }
}

void operator+=(Vector3f& va, const Vector3f& vb) {
    va.x += vb.x;
    va.y += vb.y;
    va.z += vb.z;
}

void operator-=(Vector3f& va, const Vector3f& vb) {
    va.x -= vb.x;
    va.y -= vb.y;
    va.z -= vb.z;
}

void operator*=(Vector3f& v, int x) {
    v.x *= x;
    v.y *= x;
    v.z *= x;
}

void operator/=(Vector3f& v, int x) {
    v.x /= x;
    v.y /= x;
    v.z /= x;
}

std::ostream& operator<<(std::ostream& out, const Vector3f v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector3f v) {
    in>> v.x>> v.y >> v.z;
    return in;
}

float squared_norm(const Vector3f& v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

float norm(const Vector3f& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void normalize(Vector3f& v) {
    v.x /= norm(v);
    v.y /= norm(v);
    v.z /= norm(v);
}
