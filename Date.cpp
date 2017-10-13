#include "Date.h"
#include "Calendar.h"

bool is_leap(unsigned int Y) {
	if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0)) return true;
    return false;
}

unsigned int days_in_month(unsigned int Y, Month M) {
	switch (M) {
	case Month::January: return 31;
	case Month::February: return (is_leap(Y) ? 29 : 28);
	case Month::March: return 31;
	case Month::April: return 30;
	case Month::May: return 31;
	case Month::June: return 30;
	case Month::July: return 31;
	case Month::August: return 31;
	case Month::September: return 30;
	case Month::October: return 31;
	case Month::November: return 30;
	case Month::December: return 31;
	}
}

Date::Date() {
	time_t cur_time;
	struct tm *utc_time;
	time(&cur_time);
	utc_time = gmtime(&cur_time);
	year = utc_time->tm_year + 1900;
	mon = Month(utc_time->tm_mon + 1);
	day = utc_time->tm_mday;
	hour = utc_time->tm_hour;
	min = utc_time->tm_min;
	sec = utc_time->tm_sec;
}

Date::Date(unsigned int Y, Month M, unsigned int D) {
	year = Y;
	mon = M;
	day = D;
	hour = 0;
	min = 0;
	sec = 0;
}

Date::Date(unsigned int h, unsigned int m, unsigned int s) {
	time_t cur_time;
	struct tm *cur_date;
	time(&cur_time);
	cur_date = gmtime(&cur_time);
	year = cur_date->tm_year + 1900;
	mon = Month(cur_date->tm_mon + 1);
	day = cur_date->tm_mday;
	hour = h;
	min = m;
	sec = s;
}

Date::Date(unsigned int Y, Month M, unsigned int D, unsigned int h, unsigned int m, unsigned int s) {
	year = Y;
	mon = M;
	day = D;
	hour = h;
	min = m;
	sec = s;
}

Date::Date(const Date& date) {
	year = date.year;
	mon = date.mon;
	day = date.day;
	hour = date.hour;
	min = date.min;
	sec = date.sec;
}

const Date& Date::operator= (const Date& date) {
	if (this != &date) {
		year = date.year;
		mon = date.mon;
		day = date.day;
		hour = date.hour;
		min = date.min;
		sec = date.sec;
	}
	return *this;
}

unsigned int Date::get_year() const {
	return year;
}

unsigned int Date::get_month() const {
	return int(mon);
}

unsigned int Date::get_day() const {
	return day;
}

unsigned int Date::get_hour() const {
	return hour;
}

unsigned int Date::get_minutes() const {
	return min;
}

unsigned int Date::get_seconds() const {
	return sec;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out.fill('0');
	out.width(4);
	out << date.get_year() << '-';
	out.width(2);
	out << date.get_month() << '-';
	out.width(2);
	out << date.get_day() << ' ';
	out.width(2);
	out << date.get_hour() << ':';
	out.width(2);
	out << date.get_minutes() << ':';
	out.width(2);
	out << date.get_seconds() << std::endl;
	return out;
}

Date Date::add_years(unsigned int Y) const {
	Date result(*this);
	result.year += Y;
	return result;
}

Date Date::add_months(unsigned int M) const {
	Date result(*this);
	result.mon = Month((int(mon) + M) % 12);
	result.year += (int(mon) + M) / 12;
	return result;
}

Date Date::add_days(unsigned int D) const {
	
	Date result(*this);
	unsigned int days_in_cur_month;
	while (D > (days_in_cur_month = days_in_month(result.year, result.mon)))
	{
		result = result.add_months(1);
		D -= days_in_cur_month;
	}
	result.day += D;
	return result;
}

//Date Date::add_hours(unsigned int h)  const {
//
//}
//
//Date Date::add_minutes(unsigned int m) const {
//
//}
//
//Date Date::add_seconds(unsigned int s) const {
//
//}