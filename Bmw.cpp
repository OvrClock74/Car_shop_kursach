#include "pch.h"
#include "Bmw.h"

using namespace std;

Bmw::Bmw()
{
	ofile.open("bmw.txt", ios_base::app);
	ofile << "BMW\n";
	data();
}

void Bmw::data()
{
	cout << "\n ������: ";
	//cin.ignore();
	cin.getline(ModelCar, 50);
	ofile << ModelCar << "\n";

	cout << "\n ��� �������: ";
	cin >> Year;
	ofile << Year << "\n";

	cout << "\n ������: ";
	cin >> Mileage;
	ofile << Mileage << "\n";

	cout << "\n �������� (�.�.): ";
	cin >> Horse;
	ofile << Horse << "\n";

	cout << "\n ����� ��������� (�): ";
	cin >> Liters;
	ofile << Liters << "\n";

	cout << "\n ���� (���): ";
	cin >> Price;
	ofile << Price << "\n";
}

Bmw::~Bmw()
{
	ofile.close();
}