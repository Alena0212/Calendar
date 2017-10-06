#include "Date.h"
#include "Calendar.h"

Date::Date(){
	time_t cur_time;
	struct tm *utc_time;
	time(&cur_time);
	utc_time = gmtime(&cur_time);
	year = utc_time->tm_year + 1900;
	mon = Month(utc_time->tm_mon);
	day = utc_time->tm_mday;
	hour = utc_time->tm_hour;
	min = utc_time->tm_min;
	sec = utc_time->tm_sec;
};

Date::Date(unsigned int Y, Month M, unsigned int D) {
	year = Y;
	mon = M;
	day = D;
	hour = 0;
	min = 0;
	sec = 0;
};

Date::Date(unsigned int h, unsigned int m, unsigned int s) {
	time_t cur_time;
	struct tm *cur_date;
	time(&cur_time);
	cur_date = gmtime(&cur_time);
	year = cur_date->tm_year + 1900;
	mon = Month(cur_date->tm_mon);
	day = cur_date->tm_mday;
	hour = h;
	min = m;
	sec = s;
};

Date::Date(unsigned int Y, Month M, unsigned int D, unsigned int h, unsigned int m, unsigned int s) {
	year = Y;
	mon = M;
	day = D;
	hour = h;
	min = m;
	sec = s;
};

Date::Date(const Date &date) {
	year = date.year;
	mon = date.mon;
	day = date.day;
	hour = date.hour;
	min = date.min;
	sec = date.sec;
};

unsigned int Date::get_year() {
	return year;
};

unsigned int Date::get_month() {
	return mon;
};

unsigned int Date::get_day() {
	return day;
};

unsigned int Date::get_hour() {
	return hour;
};

unsigned int Date::get_minutes() {
	return min;
};

unsigned int Date::get_seconds() {
	return sec;
};

Date Date::add_years(unsigned int Y) const {
	Date result(*this);
	result.year += Y;
	return result;
};

//
//Date Date::add_months(Month M) const {
//
//};
//
//Date Date::add_days(unsigned int D) const {
//
//};
//
//Date Date::add_hours(unsigned int h)  const {
//
//};
//
//Date Date::add_minutes(unsigned int m) const {
//
//};
//
//Date Date::add_seconds(unsigned int s) const {
//
//};