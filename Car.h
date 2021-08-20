#pragma once
#include "pch.h"
#include <fstream>
#include <iostream>

class Car
{
protected:
	std::ofstream ofile;
	char ModelCar[50];
	int Horse, Year, Mileage, Price;
	double Liters;
public:
	virtual void data() = 0;
};