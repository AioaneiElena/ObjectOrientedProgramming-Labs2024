#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


Seat::Seat()
{
    this->Name = new char[11];
    strcpy(this->Name, "Seat");
    SetFuelCap(29);
    SetFuelCons(36);
    SetAvgSpeed(110);
}

Seat::~Seat() {}

void Seat::SetFuelCap(float n)
{
    this->FuelCap = n;
}
void Seat::SetFuelCons(float n)
{
    this->FuelCons = n;
}
void Seat::SetAvgSpeed(float n)
{
    this->AvgSpeed = n;
}
float Seat::GetFuelCap()
{
    return this->FuelCap;
}
float Seat::GetFuelCons()
{
    return this->FuelCons;
}
float Seat::GetAvgSpeed()
{
    return this->AvgSpeed;
}
char* Seat::GetName()
{
    return this->Name;
}