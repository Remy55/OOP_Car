#include "stdafx.h"
#include "header.h"

float parametrs::ret_speed()
{
	return speed;
}

int parametrs::ret_course()
{
	return course;
}

int parametrs::ret_transmission()
{
	return transmission;
}

rudders::rudders()
{
	speed = 0;
	course = 0;
	transmission = 0;
}

rudders::~rudders()
{

}

void rudders::accelerator(float a)
{
	speed = transmission*4*a;
}

void rudders::brake(float a)
{
	speed = (-1)*8*a;
}

void rudders::helm(int a)
{
	course = a;
}

void rudders::gearbox(int a)
{
	transmission = a;
}

devices::devices()
{
	speed = 0;
	course = 0;
	transmission = 0;
}

devices::~devices()
{

}

void devices::true_speed(float a)
{
	speed = speed + a;
	if (speed > 250) speed = 250;
	if (speed < 0) speed = 0;
}

void devices::true_course(int a)
{
	course = course + a;
	if (course < -180) course = 360 - course;
	if (course > 180) course = course - 360;
}

void devices::true_transmission(int a)
{
	transmission = transmission + a;
	if (transmission > 6) transmission = 6;
	if (transmission < 0) transmission = 0;
}

void devices::stop()
{
	speed = 0;
	transmission = 0;
}

void devices::speedometer()
{
	if (speed > 0) cout << "Ваша скорость: " << speed << " км/час" << endl;
	if (speed == 0) cout << "Вы остановились" << endl;
}

void devices::navigator()
{
	if ((course < 0) && (course > (-180))) cout << "Ваше направление: на " << (-1)*course << " левее от первоначального" << endl;
	if ((course > 0) && (course < 180)) cout << "Ваше направление: на " << course << " правее от первоначального" << endl;
	if (course == 0) cout << "Ваше направление вовпадает с первоначальным" << endl;
	if ((course == 180) || (course == (-180))) cout << "Ваше направление противоположно первоначальному" << endl; 
}

void devices::gear_lever()
{
	if (transmission > 0) cout << "Автомобиль находится на " << transmission << " передаче" << endl;
	if (transmission == 0) cout << "Автомобиль находится на нейтральной передаче" << endl;
}

void car::change_speed_up()
{
	float t;
	cout << "Как долго вы будете давить на педать" << endl;
	cin >> t;
	a.accelerator(t);
	b.true_speed(a.ret_speed());
}

void car::change_speed_down()
{
	float t;
	cout << "Как долго вы будете давить на педать" << endl;
	cin >> t;
	a.brake(t);
	b.true_speed(a.ret_speed());
}

void car::change_course()
{
	int c, var;
	cout << "Вы хотите повернуть налево или направо? Введите 1 - если налево, 2 - если направо" << endl;
	cin >> var;
	cout << "На сколько вы хотите изменит курс?" << endl;
	cin >> c;
	if (var == 1) a.helm(-c);
	if (var == 2) a.helm(c);
	b.true_course(a.ret_course());
}

void car::change_transmission()
{
	int c, var;
	cout << "Вы хотите повысить или понизить передачу? Ведите 1 - если повысить, 2 - если понизить" << endl;
	cin >> var;
	cout << "На сколько вы хотите изменить передачу?" << endl;
	cin >> c;
	if (var == 1) a.gearbox(c);
	if (var == 2) a.gearbox(-c);
	b.true_transmission(a.ret_transmission());
}

void car::stop_car()
{
	b.stop();
}

void car::see_speed()
{
	b.speedometer();
}

void car::see_course()
{
	b.navigator();
}

void car::see_transmission()
{
	b.gear_lever();
}

void human::see_parametrs(car& d)
{
	int var;
	cout << "Какой параметр вы хотите посмотреть? 1 - скорость, 2 - направление, 3 - передачу" << endl;
	cin >> var;
	switch (var)
	{
	case 1: d.see_speed(); break;
	case 2: d.see_course(); break;
	case 3: d.see_transmission(); break;
	default: cout << "Не верно, попробуйте ещё раз" << endl; break;
	}
}

void human::change_parametrs(car& d)
{
	int var;
	cout << "Что вы хотите использовать? 1 - педаль газа, 2 - педать тормоза 3 - руль, 4 - коробку передач" << endl;
	cin >> var;
	switch (var)
	{
	case 1: d.change_speed_up(); break;
	case 2: d.change_speed_down(); break;
	case 3: d.change_course(); break;
	case 4: d.change_transmission(); break;
	default: cout << "Не верно, попробуйте ещё раз" << endl; break;
	}
}
