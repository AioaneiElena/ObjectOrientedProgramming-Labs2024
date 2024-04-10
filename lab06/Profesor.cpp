#include "Profesor.h"
#include "Blossom.h"
#include "Bubbles.h"
#include "ButterCup.h"
#include <vector>

Profesor::Profesor(const std::vector<std::string>& ingredients)
{
	this->ingredients = ingredients;
}

int Profesor::CreatePowerPuffGirls()
{
	int sugar_count = 0;
	int spice_count = 0;
	int everythingNice_count = 0;
	int createdGirls = 0;

	for (const auto& ingredient : ingredients)
	{
		if (ingredient == "sugar")
			sugar_count++;
		else
			if (ingredient == "spice")
				spice_count++;
			else
				everythingNice_count++;
	}
	while (sugar_count > 1 && spice_count > 1 && everythingNice_count > 1)
	{
		sugar_count--;
		spice_count--;
		everythingNice_count--;
		createdGirls++;
	}

	return createdGirls;
}
std::vector<PowerPuffGirl*> Profesor::GetGirls()
{
	 return girls;;
}
void Profesor::AddGirl(PowerPuffGirl* girl)
{
	girls.push_back(girl);
}
;
