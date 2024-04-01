#pragma once
#include "Car.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

class Volvo : public Car
{
public:
	Volvo();
	~Volvo();

	void SetFuelCap(float);
	void SetFuelCons(float);
	void SetAvgSpeed(float);

	float GetFuelCap();
	float GetFuelCons();
	float GetAvgSpeed();
	char* GetName();
};

