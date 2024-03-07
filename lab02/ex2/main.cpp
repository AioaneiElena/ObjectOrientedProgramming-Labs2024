#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Student.h"
#include "Global.h"
using namespace std;

int main() {

    Student Elena;
    Elena.setNume((char*)"Elena");
    Elena.setEngleza(9.5);
    Elena.setIstorie(9.2);
    Elena.setMate(8.9);
    Elena.setMedie();

    Student Ana((char*)"Ana", 10.0, 9.2, 9.3);
    Student Nicole((char*)"Nicole", 6.7, 9.1, 7.9);

    Ana.Print();
    Elena.Print();
    Nicole.Print();

    CmpMate(Nicole, Elena);
    CmpIst(Elena, Ana);
    CmpEng(Nicole, Elena);
    CmpAverage(Ana, Elena);
    CmpName(Nicole, Elena);
    CmpName(Elena, Nicole);

    return 0;
}