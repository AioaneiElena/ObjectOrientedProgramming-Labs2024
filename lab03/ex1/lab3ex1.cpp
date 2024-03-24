#include <iostream>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include "Math.h"
using namespace std;

int main()
{
    cout << "2+2 = " << Math::Add(2, 2) << '\n';
    cout << "2+3+1 = " << Math::Add(2, 3, 1) << '\n';
    cout << "1.29+2.48 = (int) " << Math::Add(1.29, 2.48) << '\n';
    cout << "1.0+1.0+0.2 = (int) " << Math::Add(1.0, 1.0, 0.2) << '\n';
    cout << "3*2 = " << Math::Mul(3, 2) << '\n';
    cout << "2*3*5 = " << Math::Mul(2, 3, 5) << '\n';
    cout << "1.2*3.0 = (int) " << Math::Mul(1.2, 3.0) << '\n';
    cout << "1.23*2.0*3.5 = (int) " << Math::Mul(1.23, 2.0, 3.5) << '\n';
    cout << "1+2+3 = " << Math::Add(3, 1, 2, 3) << '\n';
    cout << "'123' + '45' = " << Math::Add("123", "45") << '\n';
}