#pragma once
#include <iostream>
#include "atltime.h"
#include <ctime>
#include <cstdlib>
using namespace std;

class Clock
{
	int h;
	int m;
	int s;
public:
	Clock();
	Clock(int hour, int minute, int second);
	Clock(Clock& c);
	~Clock();
	void SetTime(int h, int m, int s);
	Clock operator+=(int seconds);
	Clock operator-=(int seconds);
	Clock operator+(Clock m1);
	Clock operator-(Clock m1);
	friend ostream& operator<<(ostream& out, Clock& c);
	friend istream& operator>>(istream& in, Clock& c);
	friend time_t convert(Clock c);
};

int findDif(Clock m1, Clock m2);
time_t badTime();



