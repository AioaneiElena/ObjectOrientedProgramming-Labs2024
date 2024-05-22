#include <iostream>
#include "Template.h"
using namespace std;
template<class T>
int compare(const T& a, const T& b) {
    if (a < b) return 1;
    if (a > b) return -1;
    return 0;
}

int main()
{
    Array<int> a;
    Array<int> b(50);
    Array<int> c(10);
    b += 1;
    b += 2;
    b += 3;
    b += 4;
    b += 5;
    b += 6;
    b += 7;
    b += 8;
    b += 9;
    b += 10;
    c += 3;
    c += 2;
    c += 4;

    cout << "Sirul b este:";
    for (auto it : b) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Sirul c este:";
    for (auto it : c) {
        cout << *it << " ";
    }

    cout << endl;
    cout << b.BinarySearch(1) << endl;
    cout << b.Find(5) << endl;
    b.Insert(1, 100);
    for (auto it : b) {
        cout << *it << " ";
    }
    cout << b[1] << endl;
    cout << b[11] << endl;

    b.Delete(1);
    for (auto it : b) {
        cout << *it << " ";
    }
    cout << endl;
    //b.Insert(2, c);
    for (auto it : b) {
        cout << *it << " ";
    }
    cout << endl;
    b.Delete(11);

    return 0;
}