#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdarg>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "Sort.h"

//1
Sort::Sort(int nr_elemente, int minim, int maxim) {

	vector = (int*)(malloc(nr_elemente * sizeof(int)));
	vector = new int[nr_elemente];
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < nr_elemente; i++)
		vector[i] = minim + rand() % (maxim - minim + 1);

	this->count = nr_elemente;
	
}

//2
Sort::Sort() : vector(new int[6] {55, 12, 35, 83, 15, 6}) {
	this->count = 6;
}

//3
Sort::Sort(int* vec, int nr_elemente) {

	vector = new int[nr_elemente];
	for (int i = 0; i < nr_elemente; i++) {
		vector[i] = vec[i];
	}
	this->count = nr_elemente;
}

//4
Sort::Sort(int nr_elemente, ...) {

	vector = (int*)(malloc(nr_elemente * sizeof(int)));
	vector = new int[nr_elemente];

	va_list args;
	va_start(args, nr_elemente);


	for (int i = 0; i < nr_elemente; i++) {
		vector[i] = va_arg(args, int);

	}

	va_end(args);
	this->count = nr_elemente;
}

//5
Sort::Sort(char* s) {
	int k = 1;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ',')
			k++;

	vector = new int[k];

	int cuv = 0;
	char* p;
	p = strtok(s, ",");
	while (p)
	{
		int nr = 0;
		for (int i = 0; i < strlen(p); i++)
			if (p[i] != ' ')
				nr = nr * 10 + (p[i] - '0');

		vector[cuv++] = nr;
		p = strtok(NULL, ",");
	}
	this->count = cuv;
}


Sort::~Sort() {
	delete[] vector;
}

int Sort::GetElementsCount() const
{
	return count;
}

int Sort::GetElementFromIndex(int index) const
{
	if (index >= 0 && index < count) {
		return vector[index];
	}
	else {
		std::cerr << "Invalid index!" << std::endl;
		return -1; 
	}
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < this->count; i++) {
		int key = vector[i];
		int j = i - 1;

		if (ascendent) {
			while (j >= 0 && vector[j] > key) {
				vector[j + 1] = vector[j];
				j--;
			}
		}
		else {
			while (j >= 0 && vector[j] < key) {
				vector[j + 1] = vector[j];
				j--;
			}
		}
		vector[j + 1] = key;
	}

}

void Sort::BubbleSort(bool ascendant)
{

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if ((ascendant && vector[j] > vector[j + 1]) || (!ascendant && vector[j] < vector[j + 1]))
			{
				int aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;
			}
		}
	}
}

void Sort::QuickSort(bool ascendent)
{
	if (ascendent)
	{
		std::sort(vector, vector + count);
	}
	else
	{
		std::sort(vector, vector + count, std::greater<int>());
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->count; i++) {
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}



