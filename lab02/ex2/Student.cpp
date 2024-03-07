#include "Student.h"
#include <cstring>
#include <stdio.h>

Student::Student() {
    this->mat = 0;
    this->ist = 0;
    this->eng = 0;
    this->medie = 0;
    memset(this->name, 0, 30);
}

Student::Student(char* name, float mat, float ist, float eng) {
    strcpy_s(this->name, 30, name);
    this->mat = mat;
    this->eng = eng;
    this->ist = ist;
    this->medie = setMedie();
}

Student::~Student() {
    this->mat = 0;
    this->eng = 0;
    this->ist = 0;
    this->medie = 0;
    memset(this->name, 0, 30);
}

void Student::setMate(float x) {
    if (x <= 10.0 && x >= 0.0)
        this->mat = x;
}

void Student::setEngleza(float x) {
    if (x <= 10.0 && x >= 0.0)
        this->eng = x;
}

void Student::setIstorie(float x) {
    if (x <= 10.0 && x >= 0.0)
        this->ist = x;
}

float Student::setMedie() {
    float sum = this->mat + this->eng + this->ist;
    this->medie = sum / 3;
    return this->medie;
}

float Student::getMate() {
    return this->mat;
}

float Student::getEngleza() {
    return this->eng;
}

float Student::getIstorie() {
    return this->ist;
}

float Student::getMedie() {
    return this->medie;
}

void Student::setNume(char* name) {
    strcpy_s(this->name, 30, name);
}

char* Student::getNume() {
    return this->name;
}

void Student::Print() {
    printf("Nume: %s\nNote: Engleza: %.2f | Istorie: %.2f | Mate: %.2f\nMedia: %.2f \n\n",
        getNume(), getEngleza(), getIstorie(), getMate(), getMedie());
}