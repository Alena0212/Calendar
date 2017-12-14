#include "Date.h"
#include "DateInterval.h"
#include "Calendar.h"

DateInterval::DateInterval(int Y, int M, int D, int h, int m, int s) {
	 years = Y;
	 months = M;
	 days = D;
	 hours = h;
	 minutes = m;
	 seconds = s;
}

DateInterval::DateInterval(Date& one, Date& another) {
	years = int(one.get_year()) - int(another.get_year());
	months = int(one.get_month()) - int(another.get_month());
	days = int(one.get_day()) - int(another.get_day());
	hours = int(one.get_hour()) - int(another.get_hour());
	minutes = int(one.get_minutes()) - int(another.get_minutes());
	seconds = int(one.get_seconds()) - int(another.get_seconds());
}

DateInterval::DateInterval(const DateInterval& intv) {
	years = intv.years;
	months = intv.months;
	days = intv.days;
	hours = intv.hours;
	minutes = intv.minutes;
	seconds = intv.seconds;
}

const DateInterval& DateInterval::operator= (const DateInterval& intv) {
	if (this != &intv) {
		years = intv.years;
		months = intv.months;
		days = intv.days;
		hours = intv.hours;
		minutes = intv.minutes;
		seconds = intv.seconds;
	}
	return *this;
}

int DateInterval::get_years() const {
	return years;
}

int DateInterval::get_months() const {
	return months;
}

int DateInterval::get_days() const {
	return days;
}

int DateInterval::get_hours() const {
	return hours;
}

int DateInterval::get_minutes() const {
	return minutes;
}

int DateInterval::get_seconds() const {
	return seconds;
}