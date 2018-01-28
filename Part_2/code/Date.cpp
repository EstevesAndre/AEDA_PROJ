#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(unsigned int y, unsigned int m, unsigned int d)
{
	if (!monthDayCheck(y, m, d))
		throw InvalidDate<unsigned int>(y, m, d);

	year = y;
	month = m;
	day = d;
}

void Date::setYear(unsigned int y)
{
	year = y;
}

void Date::setMonth(unsigned int m)
{
	month = m;
}

void Date::setDay(unsigned int d)
{
	day = d;
}

void Date::setDate(unsigned int y, unsigned int m, unsigned int d)
{
	year = y;
	month = m;
	day = d;
}

unsigned int Date::getYear() const
{
	return year;
}

unsigned int Date::getMonth() const
{
	return month;
}

unsigned int Date::getDay() const
{
	return day;
}


void Date::show() const
{
	if (year < 10)
	{
		cout << "000";
	}
	else if (year < 100)
	{
		cout << "00";
	}
	else if (year < 1000)
	{
		cout << "0";
	}

	cout << year << "/";

	if (month < 10)
	{
		cout << "0";
	}

	cout << month << "/";

	if (day < 10)
	{
		cout << "0";
	}

	cout << day;
}


bool Date::anobissexto(unsigned int y)
{
	if (y % 400 == 0)
		return true;
	else if (y % 4 == 0 && y % 10 != 0)
		return true;
	else
		return false;
}

bool Date::monthDayCheck(unsigned int y, unsigned int m, unsigned int d)
{
	unsigned int n_days;

	switch (m)
	{
	case 1:
	{
		n_days = 31;
		break;
	}
	case 2:
	{
		if (Date::anobissexto(y))
			n_days = 29;
		else
			n_days = 28;
		break;
	}
	case 3:
	{
		n_days = 31;
		break;
	}
	case 4:
	{
		n_days = 30;
		break;
	}
	case 5:
	{
		n_days = 31;
		break;
	}
	case 6:
	{
		n_days = 30;
		break;
	}
	case 7:
	{
		n_days = 31;
		break;
	}
	case 8:
	{
		n_days = 31;
		break;
	}
	case 9:
	{
		n_days = 30;
		break;
	}
	case 10:
	{
		n_days = 31;
		break;
	}
	case 11:
	{
		n_days = 30;
		break;
	}
	case 12:
	{
		n_days = 31;
		break;
	}
	default:
	{
		return false;
	}
	}

	if (d <= n_days)
		return true;
	else
		return false;
}

bool Date::operator == (const Date & d2) const
{
	return ((year == d2.getYear()) && (month == d2.getMonth()) && (day == d2.getDay()));
}

bool Date::operator < (const Date & d2) const
{
	if (year < d2.getYear())
		return true;
	else if (year > d2.getYear())
		return false;
	else if (month < d2.getMonth())
		return true;
	else if (month > d2.getMonth())
		return false;
	else if (day < d2.getDay())
		return true;
	else
		return false;
}
