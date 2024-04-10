#pragma once
#include "PowerPuffGirl.h"

class Blossom :public PowerPuffGirl {
private:
	int damage;
	int health;
public:
	Blossom();
	void Attack() override;
	void TakeDamage(int damage)override;
	int GetHealth()override;
	std::string GetName()override;
	int GetDamage() override;
};