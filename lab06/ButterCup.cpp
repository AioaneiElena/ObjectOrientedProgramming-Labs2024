#include "ButterCup.h"
#include<iostream>
ButterCup::ButterCup()
{
	this->damage = 30;
	this->health = 100;
}

void ButterCup::Attack()
{
	std::cout << "ButterCup attacks with " << damage << " damage." << std::endl;
}

void ButterCup::TakeDamage(int damage)
{
	health = health - damage;

}

int ButterCup::GetHealth()
{
	return health;
}

std::string ButterCup::GetName()
{
	return "ButterCup";
}

int ButterCup::GetDamage()
{
	return damage;
}
