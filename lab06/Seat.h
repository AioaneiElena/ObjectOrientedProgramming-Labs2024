#pragma once
#include "Car.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>

class Seat : public Car
{
public:
	Seat();
	~Seat();

	void SetFuelCap(float);
	void SetFuelCons(float);
	void SetAvgSpeed(float);

	float GetFuelCap();
	float GetFuelCons();
	float GetAvgSpeed();
	char* GetName();
};

