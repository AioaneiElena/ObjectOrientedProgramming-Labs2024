#define _CRT_SECURE_NO_WARNINGS
#include "BMW.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

BMW::BMW()
{
    this->Name = new char[11];
    strcpy(this->Name, "BMW");
    SetFuelCap(100);
    SetFuelCons(35);
    SetAvgSpeed(165);
}

BMW::~BMW() {}

void BMW::SetFuelCap(float n)
{
    this->FuelCap = n;
}
void BMW::SetFuelCons(float n)
{
    this->FuelCons = n;
}
void BMW::SetAvgSpeed(float n)
{
    this->AvgSpeed = n;
}
float BMW::GetFuelCap()
{
    return this->FuelCap;
}
float BMW::GetFuelCons()
{
    return this->FuelCons;
}
float BMW::GetAvgSpeed()
{
    return this->AvgSpeed;
}
char* BMW::GetName()
{
    return this->Name;
}
