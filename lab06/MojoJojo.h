#pragma once
#include "PowerPuffGirl.h"
#include <vector>
#include <iostream>
class MojoJojo {
private:
	int damage;
	int health;
public:
	MojoJojo();
	void Attack(PowerPuffGirl* girl);
	int GetHealth();
	void TakeDamage(int damage);
	int GetDamage();
	PowerPuffGirl* SelectTarget(const std::vector<PowerPuffGirl*>& girls);
};