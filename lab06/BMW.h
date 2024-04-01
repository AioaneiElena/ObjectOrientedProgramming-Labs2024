#pragma once
#include "Car.h"

class BMW : public Car
{
public:
    BMW();
    ~BMW();

    void SetFuelCap(float);
    void SetFuelCons(float);
    void SetAvgSpeed(float);

    float GetFuelCap();
    float GetFuelCons();
    float GetAvgSpeed();
    char* GetName();
};

