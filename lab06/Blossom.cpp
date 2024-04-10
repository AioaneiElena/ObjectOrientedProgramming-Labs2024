#include "Blossom.h"
#include <iostream>
Blossom::Blossom()
{
	this->damage = 20;
	this->health = 100;
}

void Blossom::Attack()
{
	std::cout << "Blossom attacks with " << damage << " damage." << std::endl;
}

void Blossom::TakeDamage(int damage)
{
	health = health - damage;
}

int Blossom::GetHealth()
{
	return health;
}
std::string Blossom::GetName()
{
	return "Blossom";
}
int Blossom::GetDamage()
{
	return damage;
}
