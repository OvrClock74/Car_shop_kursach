#include "pch.h"
#include "Hello.h"
#include <iostream>

using namespace std;

Hello::Hello()
{

}

void Hello::Hat()
{
	system("cls");
	cout << "support KIA, BMW, Audi";
	cout << "\n\n     <<Showcase of Cars>>\n\n\n";
}

void Hello::Start()
{
	Hat();
	cout << " Добавить или найти машину?\n ";
	cin >> YesNo;
	if (!strcmp(YesNo, "добавить") || !strcmp(YesNo, "Добавить")) Enter();
	else if (!strcmp(YesNo, "найти") || !strcmp(YesNo, "Найти")) Find();
	else
	{
		cout << "\n Хотите закрыть программу?\n ";
		cin >> YesNo;
		if (!strcmp(YesNo, "нет") || (!strcmp(YesNo, "Нет")))
		{
			Start();
		}
		else exit(0);
	}
}

void Hello::Enter()
{
	Hat();
	cout << " Заполнение данных\n\n Введите латинскими буквами марку машины: ";
	cin.ignore();
	cin.getline(NameCar, 50);
	if (!strcmp(NameCar, "kia") || !strcmp(NameCar, "KIA")) { Car *car = new Kia; delete car; } // delete выполняется, всё норм!
	else if (!strcmp(NameCar, "bmw") || !strcmp(NameCar, "BMW")) { Car *car = new Bmw; delete car; }
	else if (!strcmp(NameCar, "audi") || !strcmp(NameCar, "Audi")) { Car *car = new Audi; delete car; }
	else {
		cout << "\n\n Пока что нет поддержки данной марки, но в скором времени мы обязательно добавим!";
		Exit();
	}

	Hat();
	cout << "   Машина успешно добавлена!";
	Exit();
}

void Hello::NoCars()
{
	ifile.close();
	cout << "\n К сожалению, нет ни одной машины данной марки.";
	cout << "\n\n Хотите найти машину другой марки?\n ";
	cin >> YesNo;
	if (!strcmp(YesNo, "да") || !strcmp(YesNo, "Да"))
	{
		Find();
	}
	else Exit();
}

void Hello::View2(int i)
{
	int j = 1;
	while (j <= i / 7)
	{
		ifile >> NameCar;
		cout << "     " << NameCar;

		ifile.ignore();
		ifile.getline(NameCar, 50);
		cout << "\n Модель: " << NameCar;

		ifile >> NameCar;
		cout << "\n Год выпуска: " << NameCar;

		ifile >> NameCar;
		cout << "\n Пробег (км): " << NameCar;

		ifile >> NameCar;
		cout << "\n Мощность (л.с.): " << NameCar;

		ifile >> NameCar;
		cout << "\n Объем двигателя: " << NameCar;

		ifile >> NameCar;
		cout << "\n Цена: " << NameCar << "\n\n";

		j++;
	}
}

void Hello::View1()
{
	ifile >> NameCar;
	if (strcmp(NameCar, ""))
	{
		int i = 1;
		while (!ifile.eof())
		{
			ifile >> NameCar;
			i++;
		}
		cout << endl << " " << i / 7 << " машин(а/ы) находится в продаже.\n"; // на 7 потому что 7 параметров машины, увеличить при увеличении параметров
		cout << "\n Хотите посмотреть характеристики этих машин?\n ";
		cin >> YesNo;
		if (!strcmp(YesNo, "да") || !strcmp(YesNo, "Да"))
		{
			Hat();
			ifile.clear();
			ifile.seekg(0);
			View2(i);
		}
		else Exit();
	}
	else
	{
		NoCars();
	}
}

void Hello::Find()
{
	Hat();
	cout << " Машины какой марки хотите найти?\n ";
	cin.ignore();
	cin.getline(NameCar, 50);
	if (!strcmp(NameCar, "kia") || !strcmp(NameCar, "KIA"))
	{
		ifile.open("kia.txt");
		View1();
	}
	else if (!strcmp(NameCar, "bmw") || !strcmp(NameCar, "BMW"))
	{
		ifile.open("bmw.txt");
		View1();
	}
	else if (!strcmp(NameCar, "audi") || !strcmp(NameCar, "Audi"))
	{
		ifile.open("audi.txt");
		View1();
	}
	else cout << "\n К сожалению, на данный момент нет машин введённой Вами марки.";
	Exit();
}

void Hello::Exit()
{
	ifile.close();
	cout << "\n\n Хотите вернуться в главное меню?  ";
	cin >> YesNo;
	if (!strcmp(YesNo, "да") || !strcmp(YesNo, "Да")) { Start(); }
	else exit(0);
}

Hello::~Hello()
{

}