#pragma once
#include "PowerPuffGirl.h"

class Bubbles :public PowerPuffGirl {
private:
	int damage;
	int health;
public:
	Bubbles();
	void Attack() override;
	void TakeDamage(int damage)override;
	int GetHealth()override;
	std::string GetName()override;
	int GetDamage() override;
};