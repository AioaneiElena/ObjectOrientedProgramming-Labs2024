
#include <iostream>
#include "Template.h"
using namespace std;
int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	cout << "-------------------------------" << endl;
	cout << "Set:" << endl;
	m.Set("buna ziua", 7);
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	cout << "-------------------------------" << endl;
	cout << "Delete:" << endl;
	m.Delete(20);
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	cout << "-------------------------------" << endl;
	cout << "Get:" << endl;
	const char* aici;
	m.Get(10, aici);
	cout << aici << endl;

	cout << "-------------------------------" << endl;
	cout << "Clear:" << endl;
	m.Clear();
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	return 0;

}