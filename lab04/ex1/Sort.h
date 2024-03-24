#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cstring>
#include <cstdarg>
#include <tuple>
#include <vector>


class Sort
{
    int* vector;
    int count;

public:
    Sort(int nr_elemente, int minim, int maxim); //1
    Sort(); //2
    Sort(int* vec, int nr_elemente); //3
    Sort(int nr_elemente, ...); //4
    Sort(char* s); //5
    ~Sort();

    int GetElementsCount() const; 
    int GetElementFromIndex(int index) const; 
    void InsertSort(bool ascendent = false); 
    void QuickSort(bool ascendent = false); 
    void BubbleSort(bool ascendent = false); 
    void Print();

};

