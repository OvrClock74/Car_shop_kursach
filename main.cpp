#include "pch.h"
#include "Hello.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Hello hl;
	hl.Start();
	return 0;
}