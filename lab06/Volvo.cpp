#define _CRT_SECURE_NO_WARNINGS
#include "Volvo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


Volvo::Volvo()
{
    this->Name = new char[11];
    strcpy(this->Name, "Volvo");
    SetFuelCap(300);
    SetFuelCons(39);
    SetAvgSpeed(142);
}

Volvo::~Volvo() {}

void Volvo::SetFuelCap(float n)
{
    this->FuelCap = n;
}
void Volvo::SetFuelCons(float n)
{
    this->FuelCons = n;
}
void Volvo::SetAvgSpeed(float n)
{
    this->AvgSpeed = n;
}
float Volvo::GetFuelCap()
{
    return this->FuelCap;
}
float Volvo::GetFuelCons()
{
    return this->FuelCons;
}
float Volvo::GetAvgSpeed()
{
    return this->AvgSpeed;
}
char* Volvo::GetName()
{
    return this->Name;
}