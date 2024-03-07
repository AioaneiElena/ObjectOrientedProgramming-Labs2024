#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList obj;
	obj.Init();
	obj.Add(5);
	obj.Add(9);
	obj.Add(2);
	obj.Print();
	obj.Sort();
	obj.Print();
	
	return 0;
}