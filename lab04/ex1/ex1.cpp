#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <cstdarg>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iterator>


#include "Sort.h"
int main()
{
	Sort s1(5, 10, 25);
	std::cout << "Original array: ";
	s1.Print();
	s1.InsertSort(true);
	std::cout << "Sorted array (InsertSort, ascending): ";
	s1.Print();
	printf("\n");

	Sort s2;
	std::cout << "Original array: ";
	s2.Print();
	s2.BubbleSort(true);
	std::cout << "Sorted array (BubbleSort, ascending): ";
	s2.Print();
	printf("\n");

	int x[] = { 4, 7, 2, 8, 5, 6, 10 }; int k = 7;
	Sort s3(x, k);
	std::cout << "Original array: ";
	s3.Print();
	s3.QuickSort(true);
	std::cout << "Sorted array (QuickSort, ascending): ";
	s3.Print();
	printf("\n");

	Sort s4(7, 4, 2, 6, 1, 7, 3, 5);
	std::cout << "Original array: ";
	s4.Print();
	s4.InsertSort(false);
	std::cout << "Sorted array (InsertSort, descending): ";
	s4.Print();
	printf("\n");

	char str[] = "11, 7, 8, 34, 5";
	Sort s5(str);
	std::cout << "Original array: ";
	s5.Print();
	s5.QuickSort(false);
	std::cout << "Sorted array (QuickSort, descending): ";
	s5.Print();
	printf("\n");


	return 0;
}