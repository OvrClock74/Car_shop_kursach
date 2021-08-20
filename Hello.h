#pragma once
#include "Kia.h"
#include "Bmw.h"
#include "Audi.h"
#include <fstream>

class Hello
{
private:
	char YesNo[9], NameCar[50];
	std::ifstream ifile;
public:
	Hello();
	void Hat(); // шапка, чтоб удобно было добавлять поддержку новых марок
	void Start();
	void Enter();
	void NoCars();
	void View1();
	void View2(int i);
	void Find();
	void Exit();
	~Hello();
};