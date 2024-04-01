#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include "Weather.h"
#include "Car.h"

class Circuit
{
	int length;
	Weather weather;
	std::vector<Car*> Cars;

public:

	Circuit();
	~Circuit();

	void SetLength(float);
	void SetWeather(Weather);
	void Race();
	void AddCar(Car*);
	void ShowFinalRanks();
	void ShowConsumptionRanks();
	void ShowWhoDidNotFinish();
};

