#define _CRT_SECURE_NO_WARNINGS
#include "Fiat.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Fiat::Fiat()
{
    this->Name = new char[11];
    strcpy(this->Name, "Fiat");
    SetFuelCap(30);
    SetFuelCons(34);
    SetAvgSpeed(125);
}

Fiat::~Fiat() {}

void Fiat::SetFuelCap(float n)
{
    this->FuelCap = n;
}
void Fiat::SetFuelCons(float n)
{
    this->FuelCons = n;
}
void Fiat::SetAvgSpeed(float n)
{
    this->AvgSpeed = n;
}
float Fiat::GetFuelCap()
{
    return this->FuelCap;
}
float Fiat::GetFuelCons()
{
    return this->FuelCons;
}
float Fiat::GetAvgSpeed()
{
    return this->AvgSpeed;
}
char* Fiat::GetName()
{
    return this->Name;
}
