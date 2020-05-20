#include "Clock.h"

Clock::Clock() : h(0), m(0), s(0)
{
}

Clock::Clock(int hour, int minute, int second)
	: h(hour), m(minute), s(second)
{
}

Clock::Clock(Clock& c)
{
	h = c.h;
	m = c.m;
	s = c.s;
}

Clock::~Clock()
{
}

void Clock::SetTime(int h, int m, int s)
{
	this->h = h;
	this->m = m;
	this->s = s;
}

Clock Clock::operator+=(const int second)
{
	s += second;
	while (s > 59)
	{
		s -= 60;
		m++;
		if (m == 60)
		{
			m = 0;
			h++;
			if (h == 24) h = 0;
		}
	}
	return *this;
}

Clock Clock::operator-=(int second)
{
	s -= second % 60;
	while (s < 0)
	{
		s += 60;
		m--;
		while(m < 0)
		{
			m += 60;
			h--; 
			if (h < 0) h = 23;
		}
	}
	m -= second / 60;
	while (m < 0)
	{
		m += 60;
		h--;
		if (h < 0) h = 23;
	}
	return *this;
}

time_t convert(Clock c)
{
	struct tm f = tm();
	f.tm_hour = c.h;
	f.tm_min = c.m;
	f.tm_sec = c.s;
	f.tm_year = 120;
	return mktime(&f);
}

time_t badTime()
{
	return time_t(-1);
}

int findDif(Clock m1, Clock m2)
{
	time_t t1 = convert(m1);
	time_t t2 = convert(m2);
	if ((t1 == badTime()) || (t2 == badTime()))
	{
		cerr << "cannot create structure time_t" << endl;
		return -1;
	}
	int sec = difftime(t2, t1);
	return abs(sec);
}

Clock Clock::operator+(Clock m)
{
	Clock zero(0,0,0);
	int difference1 = findDif(*this, zero);
	int difference2 = findDif(m, zero);
	zero += difference1 + difference2;
	/*result.s = s + m1.s;
	if (result.s > 59)
	{
		result.s -= 60;
		result.m++;
		if (result.m == 60)
		{
			result.h++;
			result.m = 0;
			if (result.h == 24) result.h = 0;
		}
	}
	result.m = m + m1.m;
	if (result.m > 59)
	{
		result.m -= 60;
		result.h++;
		if (result.h == 24) result.h = 0;
	}
	result.h = h + m1.h;
	if (result.h > 23)
	{
		result.h -= 24;
		if (result.h == 24) result.h = 0;
	
	}*/
	return zero;
}

Clock Clock::operator-(Clock m)
{
	Clock zero(0, 0, 0);
	int difference1 = findDif(*this, zero);
	int difference2 = findDif(m, zero);
	zero += abs(difference1 - difference2);
	return zero;
}

ostream& operator<<(ostream& out, Clock& c)
{
	out << c.h << ':' << c.m << ':' << c.s;
	return out;
}

istream& operator>>(istream& in, Clock& c)
{
	in >> c.h >> c.m >> c.s;
	return in;
}
