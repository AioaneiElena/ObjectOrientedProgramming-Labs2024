#pragma once
#include "PowerPuffGirl.h"

class ButterCup :public PowerPuffGirl {
private:
	int damage;
	int health;
public:
	ButterCup();
	void Attack() override;
	void TakeDamage(int damage)override;
	int GetHealth()override;
	std::string GetName()override;
	int GetDamage() override;
};