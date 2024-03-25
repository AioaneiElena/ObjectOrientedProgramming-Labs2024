
/*
Number operator+(Number m);
Number operator+(int x);
friend int operator+(Number m, int x);
Number operator-(Number m);
Number operator-(int x);
friend int operator-(Number m, int x);

Number operator++(); //++x
Number operator++(int x); //x++
Number operator--();
Number operator--(int x);

int operator[](int index);
bool operator!();
bool operator<();
bool operator>();
bool operator<=();
bool operator>=();
bool operator==();
bool operator!=();


};
*/

#pragma once
#include <string>
#include <iostream>
using namespace std;
class Number
{
	char* value;
	int base;
public:

	Number(const char* newValue, int newBase); 
	Number(const Number& n);
	Number(int);
	~Number();


	Number(const Number&& ex); 

	void operator=(const Number& n1);
	void operator=(const char* newValue);
	void operator-();
	char& operator[](int index);
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	friend Number operator+=(Number& n1, const Number& n2);
	Number operator|(const Number& n);
	bool operator>(const Number& n1);
	Number operator--();
	Number operator--(int x);


	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount();
	int  GetBase(); 
};