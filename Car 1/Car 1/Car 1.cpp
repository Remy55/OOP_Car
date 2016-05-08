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
		cout << "Выберите действие: 1 - посмотреть прибоную панель, 2 - задействовать контроллеры, 3 - остановить автомобиль, 0 - выйти из автомобиля" << endl;
		cin >> h;
		switch (h)
		{
		case 1: me.see_parametrs(&McLaren); break;
		case 2: me.change_parametrs(&McLaren); break;
		case 3: McLaren.stop_car(); break;
		case 0: cout << "Вы покинули автомобиль" << endl; break;
		default: cout << "Не верно, повторите попытку" << endl; break;
		}
	}
	while (h != 0);
	cin.get();
	cin.get();
	return (0);
}
