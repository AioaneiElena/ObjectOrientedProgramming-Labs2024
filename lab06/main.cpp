#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "Car.h"
#include "Circuit.h"
#include "Seat.h"
#include "BMW.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Volvo.h"
using namespace std;

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::rain);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); // print the time each car needed to finish the circuit from the fastest car to slowest.
	c.ShowWhoDidNotFinish(); //some cars don't have enough fuel to finish 
	return 0;
}