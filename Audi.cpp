#include "pch.h"
#include "Audi.h"

using namespace std;

Audi::Audi()
{
	ofile.open("audi.txt", ios_base::app);
	ofile << "Audi\n";
	data();
}

void Audi::data()
{
	cout << "\n Модель: ";
	//cin.ignore();
	cin.getline(ModelCar, 50);
	ofile << ModelCar << "\n";

	cout << "\n Год выпуска: ";
	cin >> Year;
	ofile << Year << "\n";

	cout << "\n Пробег: ";
	cin >> Mileage;
	ofile << Mileage << "\n";

	cout << "\n Мощность (л.с.): ";
	cin >> Horse;
	ofile << Horse << "\n";

	cout << "\n Объем двигателя (л): ";
	cin >> Liters;
	ofile << Liters << "\n";

	cout << "\n Цена (руб): ";
	cin >> Price;
	ofile << Price << "\n";
}

Audi::~Audi()
{
	ofile.close();
}