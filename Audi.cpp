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

Audi::~Audi()
{
	ofile.close();
}