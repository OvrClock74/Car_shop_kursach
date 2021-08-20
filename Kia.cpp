#include "pch.h"
#include "Kia.h"

using namespace std;

Kia::Kia()
{
	ofile.open("kia.txt", ios_base::app);
	ofile << "KIA\n";
	data();
}

void Kia::data()
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

Kia::~Kia()
{
	ofile.close();
}