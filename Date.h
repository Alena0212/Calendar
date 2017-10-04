#pragma once

class Date {
private:
	unsigned int year;
	enum Month {
		January = 0, February, March, April, May, June, 
		July, August, September, October, November, December 
	} mon;
	unsigned int day;
	unsigned int hour;
	unsigned int min;
	unsigned int sec;
public:
	Date();
	//Date(unsigned int Y, Month M, unsigned int D); 
	//Date(unsigned int h, unsigned int m, unsigned int s); not certain how to distinguish these two constructors
	Date(unsigned int Y, unsigned int M, unsigned int D, unsigned int h, unsigned int m, unsigned int s);
	unsigned int get_year();
	unsigned int get_month();
	unsigned int get_day();
	unsigned int get_hour();
	unsigned int get_minutes();
	unsigned int get_seconds();
	Date add_years(unsigned int Y) const;
	Date add_months(unsigned int M) const;
	Date add_days(unsigned int D) const;
	Date add_hours(unsigned int h) const;
	Date add_minutes(unsigned int m) const;
	Date add_seconds(unsigned int s) const;
};