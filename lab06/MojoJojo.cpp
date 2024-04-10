#include "MojoJojo.h"

MojoJojo::MojoJojo()
{
	this->damage = 10;
	this->health = 100;
}

void MojoJojo::Attack(PowerPuffGirl* girl)
{
	girl->TakeDamage(damage);
}

int MojoJojo::GetHealth()
{
	return health;
}

void MojoJojo::TakeDamage(int damage)
{
	health = health - damage;
}

int MojoJojo::GetDamage()
{
	return damage;
}

PowerPuffGirl* MojoJojo::SelectTarget(const std::vector<PowerPuffGirl*>& girls)
{
	if (girls.empty()) {
		return nullptr; 
	}
	int index = rand() % girls.size();
	return girls[index];
}
