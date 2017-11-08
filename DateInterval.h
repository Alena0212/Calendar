#pragma once
#include "Calendar.h"

class DateInterval {
private:
	int years;
	int months;
	int days;
	int hours;
	int minutes;
	int seconds;
public:
	DateInterval(int Y, int M, int D, int h, int m, int s);
	DateInterval(const DateInterval& intv);
	const DateInterval& operator= (const DateInterval& intv);
	int get_years() const;
	int get_months() const;
	int get_days() const;
	int get_hours() const;
	int get_minutes() const;
	int get_seconds() const;
};
