#pragma once

#include <cstring>
class Student {
private:
    char name[30];
    float mat;
    float eng;
    float ist;
    float medie;

public:
    Student();
    Student(char* name, float mat, float ist, float eng);
    ~Student();

    void setMate(float x);
    void setEngleza(float x);
    void setIstorie(float x);
    float setMedie();
    float getMate();
    float getEngleza();
    float getIstorie();
    float getMedie();
    void setNume(char* name);
    char* getNume();

    void Print();
};