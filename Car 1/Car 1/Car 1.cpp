#include "stdafx.h"
#include "header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int h;
	car McLaren;
	human me;
	do 
	{
		cout << "�������� ��������: 1 - ���������� �������� ������, 2 - ������������� �����������, 3 - ���������� ����������, 0 - ����� �� ����������" << endl;
		cin >> h;
		switch (h)
		{
		case 1: me.see_parametrs(&McLaren); break;
		case 2: me.change_parametrs(&McLaren); break;
		case 3: McLaren.stop_car(); break;
		case 0: cout << "�� �������� ����������" << endl; break;
		default: cout << "�� �����, ��������� �������" << endl; break;
		}
	}
	while (h != 0);
	cin.get();
	cin.get();
	return (0);
}
