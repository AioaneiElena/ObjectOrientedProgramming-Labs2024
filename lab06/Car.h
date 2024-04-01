#pragma once

class Car
{
protected:
	char* Name;
	float FuelCap;
	float FuelCons;
	float AvgSpeed;

public:
	virtual void SetFuelCap(float) = 0;
	virtual void SetFuelCons(float) = 0;
	virtual void SetAvgSpeed(float) = 0;
	virtual float GetFuelCap() = 0;
	virtual float GetFuelCons() = 0;
	virtual float GetAvgSpeed() = 0;
	virtual char* GetName() = 0;

};

