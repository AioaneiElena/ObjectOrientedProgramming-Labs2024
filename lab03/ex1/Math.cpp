#define _CRT_SECURE_NO_WARNINGS
#include <cstdarg>
#include <cstdio>
#include <iostream>
#include "Math.h"
using namespace std;

int Math::Add(int x, int y)
{
    return x + y;
}

int Math::Add(int x, int y, int z)
{
    return x + y + z;
}

int Math::Add(double x, double y)
{
    return (int)(x + y);
}

int Math::Add(double x, double y, double z)
{
    return (int)(x + y + z);
}

int Math::Mul(int x, int y)
{
    return x * y;
}

int Math::Mul(int x, int y, int z)
{
    return x * y * z;
}

int Math::Mul(double x, double y)
{
    return (int)(x * y);
}

int Math::Mul(double x, double y, double z)
{
    return (int)(x * y * z);
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);

    int s = 0;
    for (int i = 0; i < count; i++)
    {
        int x = va_arg(args, int);
        s += x;
    }
    va_end(args);
    return (int)s;
}

char* Math::Add(const char* c1, const char* c2) {
    if (c1 == nullptr || c2 == nullptr)
        return nullptr;

    int x = strlen(c1);
    int y = strlen(c2);
    int a = 0, b = 0;

    for (int i = 0; i < x; i++)
        a = a * 10 + (c1[i] - '0');
    for (int i = 0; i < y; i++)
        b = b * 10 + (c2[i] - '0');

    if (x < y)
        swap(x, y);
    char* c = new char[x + 1];
    a = a + b;


    while (a != 0)
    {
        c[x--] = a % 10 + '0';
        a /= 10;
    }
    return (char*)c;
}