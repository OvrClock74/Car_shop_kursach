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
	cout << " �������� ��� ����� ������?\n ";
	cin >> YesNo;
	if (!strcmp(YesNo, "��������") || !strcmp(YesNo, "��������")) Enter();
	else if (!strcmp(YesNo, "�����") || !strcmp(YesNo, "�����")) Find();
	else
	{
		cout << "\n ������ ������� ���������?\n ";
		cin >> YesNo;
		if (!strcmp(YesNo, "���") || (!strcmp(YesNo, "���")))
		{
			Start();
		}
		else exit(0);
	}
}

void Hello::Enter()
{
	Hat();
	cout << " ���������� ������\n\n ������� ���������� ������� ����� ������: ";
	cin.ignore();
	cin.getline(NameCar, 50);
	if (!strcmp(NameCar, "kia") || !strcmp(NameCar, "KIA")) { Car *car = new Kia; delete car; } // delete �����������, �� ����!
	else if (!strcmp(NameCar, "bmw") || !strcmp(NameCar, "BMW")) { Car *car = new Bmw; delete car; }
	else if (!strcmp(NameCar, "audi") || !strcmp(NameCar, "Audi")) { Car *car = new Audi; delete car; }
	else {
		cout << "\n\n ���� ��� ��� ��������� ������ �����, �� � ������ ������� �� ����������� �������!";
		Exit();
	}

	Hat();
	cout << "   ������ ������� ���������!";
	Exit();
}

void Hello::NoCars()
{
	ifile.close();
	cout << "\n � ���������, ��� �� ����� ������ ������ �����.";
	cout << "\n\n ������ ����� ������ ������ �����?\n ";
	cin >> YesNo;
	if (!strcmp(YesNo, "��") || !strcmp(YesNo, "��"))
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
		cout << "\n ������: " << NameCar;

		ifile >> NameCar;
		cout << "\n ��� �������: " << NameCar;

		ifile >> NameCar;
		cout << "\n ������ (��): " << NameCar;

		ifile >> NameCar;
		cout << "\n �������� (�.�.): " << NameCar;

		ifile >> NameCar;
		cout << "\n ����� ���������: " << NameCar;

		ifile >> NameCar;
		cout << "\n ����: " << NameCar << "\n\n";

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
		cout << endl << " " << i / 7 << " �����(�/�) ��������� � �������.\n"; // �� 7 ������ ��� 7 ���������� ������, ��������� ��� ���������� ����������
		cout << "\n ������ ���������� �������������� ���� �����?\n ";
		cin >> YesNo;
		if (!strcmp(YesNo, "��") || !strcmp(YesNo, "��"))
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
	cout << " ������ ����� ����� ������ �����?\n ";
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
	else cout << "\n � ���������, �� ������ ������ ��� ����� �������� ���� �����.";
	Exit();
}

void Hello::Exit()
{
	ifile.close();
	cout << "\n\n ������ ��������� � ������� ����?  ";
	cin >> YesNo;
	if (!strcmp(YesNo, "��") || !strcmp(YesNo, "��")) { Start(); }
	else exit(0);
}

Hello::~Hello()
{

}