#include "stdafx.h"
#include "iostream"

using namespace std;

class parametrs
{
protected:
	float speed;
	int course;
	int transmission;
public:
	float ret_speed();
	int ret_course();
	int ret_transmission();
};

class rudders: public parametrs
{
public:
	rudders();
	~rudders();
	void accelerator(float);
	void brake(float);
	void helm(int);
	void gearbox(int);
};

class devices: public parametrs
{
public:
	devices();
	~devices();
	void true_speed(float);
	void true_course(int);
	void true_transmission(int);
	void stop();
	void speedometer();
	void navigator();
	void gear_lever();
};

class car
{
private:
	rudders a;
	devices b;
public:
	void change_speed_up();
	void change_speed_down();
	void change_course();
	void change_transmission();
	void stop_car();
	void see_speed();
	void see_course();
	void see_transmission();
};

class human
{
public:
	void see_parametrs(car &);
	void change_parametrs(car &);
};
