#pragma once
#include "PowerPuffGirl.h"
#include <iostream>
#include <vector>
class Profesor {
private:
	std::vector<std::string> ingredients;
	std::vector<PowerPuffGirl*> girls;
public:
	Profesor(const std::vector<std::string> &ingredients);
	int CreatePowerPuffGirls();
	std::vector<PowerPuffGirl*> GetGirls();
	void AddGirl(PowerPuffGirl* girl);
};