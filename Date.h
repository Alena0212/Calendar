#pragma once
#include "Date.h"
#include "DateInterval.h"
#include "Calendar.h"

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
	DateInterval get_interval(const Date& another_d) const;
	Date add_years(int Y) const;
	Date add_months(int M) const;
	Date add_days(int D) const;
	Date add_hours(int h) const;
	Date add_minutes(int m) const;
	Date add_seconds(int s) const;
	Date  operator+ (const DateInterval &intv) const;
	Date& operator+=(const DateInterval &intv);
	Date  operator- (const DateInterval &intv) const;
	Date& operator-=(const DateInterval &intv);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator==(const Date& date) const;
	std::string format_date(std::string format);
	};


bool is_leap(unsigned int Y);
unsigned int days_in_month(unsigned int Y, Month M);

std::ostream& operator<<(std::ostream& out, const Date& date);