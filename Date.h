#pragma once
#include <iostream>

enum class Month {
	January = 1, February, March, April, May, June,
	July, August, September, October, November, December
};

class Date {
private:
	unsigned int year;
	unsigned int day;
	Month mon;
	unsigned int hour;
	unsigned int min;
	unsigned int sec;
public:
	Date();
	Date(unsigned int Y, Month M, unsigned int D); 
	Date(unsigned int h, unsigned int m, unsigned int s); 
	Date(unsigned int Y, Month M, unsigned int D, unsigned int h, unsigned int m, unsigned int s);
	Date(const Date& date);
	const Date& operator= (const Date& date);
	unsigned int get_year() const;
	unsigned int get_month() const;
	unsigned int get_day() const;
	unsigned int get_hour() const;
	unsigned int get_minutes() const;
	unsigned int get_seconds() const;
	Date add_years(unsigned int Y) const;
	Date add_months(unsigned int M) const;
	Date add_days(unsigned int D) const;
	Date add_hours(unsigned int h) const;
	Date add_minutes(unsigned int m) const;
	Date add_seconds(unsigned int s) const;
};


bool is_leap(unsigned int Y);
unsigned int days_in_month(unsigned int Y, Month M);

std::ostream& operator<<(std::ostream& out, const Date& date);