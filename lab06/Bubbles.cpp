#include "Bubbles.h"
#include <iostream>
Bubbles::Bubbles()
{
	this->damage = 10;
	this->health = 100;
}

void Bubbles::Attack()
{
	std::cout << "Bubbles attacks with " << damage << " damage." << std::endl;
}

void Bubbles::TakeDamage(int damage)
{
	health = health - damage;
}

int Bubbles::GetHealth()
{
	return health;
}
std::string Bubbles::GetName()
{
	return "Bubbles";
}

int Bubbles::GetDamage()
{
	return damage;
}
