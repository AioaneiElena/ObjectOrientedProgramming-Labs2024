#define _CRT_SECURE_NO_WARNINGS
#include "RangeRover.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


RangeRover::RangeRover()
{
    this->Name = new char[11];
    strcpy(this->Name, "RangeRover");
    SetFuelCap(38);
    SetFuelCons(46);
    SetAvgSpeed(130);
}

RangeRover::~RangeRover() {}

void RangeRover::SetFuelCap(float n)
{
    this->FuelCap = n;
}
void RangeRover::SetFuelCons(float n)
{
    this->FuelCons = n;
}
void RangeRover::SetAvgSpeed(float n)
{
    this->AvgSpeed = n;
}
float RangeRover::GetFuelCap()
{
    return this->FuelCap;
}
float RangeRover::GetFuelCons()
{
    return this->FuelCons;
}
float RangeRover::GetAvgSpeed()
{
    return this->AvgSpeed;
}
char* RangeRover::GetName()
{
    return this->Name;
}