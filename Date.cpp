#include "Date.h"
#include "DateInterval.h"
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
	default: return 0;
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

Date::Date(unsigned int Y, Month M, unsigned int D) : Date(Y, M, D, 0, 0, 0) { }

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
	year = day = hour = min = sec = 0;
	mon = M;
	try {
		if (Y > 9999) throw 9999;
		year = Y;
		*this = (*this).add_days(D);
		*this = (*this).add_hours(h);
		*this = (*this).add_minutes(m);
		*this = (*this).add_seconds(s);
		if (year > 9999) throw 9999;
	}
	catch (int i) {
		std::cerr << "Date year overflow, it must be not more than " << i << ", press any key to quit" << std::endl;
		std::cin.get();
		exit(1);
	}
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

DateInterval Date::get_interval(const Date& another_d) const {
	return DateInterval(int(year) - int(another_d.year), int(mon) - int(another_d.mon), \
		int(day) - int(another_d.day), int(hour) - int(another_d.hour), int(min) - int(another_d.min), int(sec) - int(another_d.sec));
}

Date Date::add_years(int Y) const {
	Date result(*this);
	try {
		result.year += Y;
		if (result.year > 9999) throw 9999;
	}
	catch (int i) {
		std::cerr << "Date year overflow, it must be not more than " << i << ", press ENTER to quit" << std::endl;
		std::cin.get();
		exit(1);
	}
	return result;
}

Date Date::add_months(int M) const {
	Date result(*this);
	if (M != 0)
	{
		if (M > 0) {
			result = result.add_years((M + int(result.mon) == 13) ? 1 : (M / 12));
			result.mon = ((int(result.mon) + M) % 12) ? (Month(((int(result.mon) + M) % 12))) : Month::December;
		}
		else {
			M *= (-1);
			result = result.add_years(-((int(result.mon) <= (M % 12)) ? 1 : (M / 12)));
			if (int(result.mon) > (M % 12))
				result.mon = Month(int(result.mon) - (M % 12));
			else if (int(result.mon) == (M % 12)) 	
				result.mon = Month::December;			
			else
				result.mon = (Month(12 + int(result.mon) - M));
		};
	}
	return result;
}

Date Date::add_days(int D) const {
	Date result(*this);
	if (D != 0) {
		unsigned int days_in_cur_month = days_in_month(result.year, result.mon);
		if (D > 0) {
			if (result.day + D <= days_in_cur_month) result.day += D;
			else {
				result = result.add_months(1);
				result.day = 1;
				D -= days_in_cur_month - result.day;
				while (D > (days_in_cur_month = days_in_month(result.year, result.mon))) {
					result = result.add_months(1);
					D -= days_in_cur_month;
				}
				result.day = ((D  % days_in_cur_month) == 0) ? days_in_cur_month : (D % days_in_cur_month);
			}
		}
		else {
			D *= (-1);
			if (result.day > D) result.day -= D;
			else {
				D -= result.day;
				result = result.add_months(-1);
				result.day = days_in_month(result.year, result.mon);
				while (D > (days_in_cur_month = days_in_month(result.year, result.mon))) {
					result = result.add_months(-1);
					D -= days_in_cur_month;
				}
				if ((days_in_cur_month - D) != 0)
					result.day = days_in_cur_month - D;
				else {
					result = result.add_months(-1);
					result.day = days_in_month(result.year, result.mon);
				}
			}
		}
	}
	return result;
}

Date Date::add_hours(int h)  const {
	Date result(*this);
	if (h >= 0) {
		result = result.add_days((int(result.hour) + h) / 24);
		result.hour = (int(result.hour) + h) % 24;
	}
	else {
		h *= (-1);
		if (result.hour >= h) result.hour -= h;
		else {
			h -= result.hour + 1;
			result = result.add_days(-(1 + h/24));
			result.hour = (23 - (h % 24));
		}
	}
	return result;
}

Date Date::add_minutes(int m) const {
	Date result(*this);
	if (m >= 0) {
		result = result.add_hours((int(result.min) + m) / 60);
		result.min = (int(result.min) + m) % 60;
	}
	else {
		m *= (-1);
		if (result.min >= m) result.min -= m;
		else {
			m -= result.min + 1;
			result = result.add_hours(-(1 + m / 60));
			result.min = (59 - (m % 60));
		}
	}
	return result;
}

Date Date::add_seconds(int s) const {
	Date result(*this); 
	if (s >= 0) {
		result = result.add_minutes((int(result.sec) + s) / 60);
		result.sec = (int(result.sec) + s) % 60;
	}
	else {
		s *= (-1);
		s -= result.sec + 1;
		result = result.add_minutes(-(1 + s / 60));
		result.sec = (59 - (s % 60));
	}
	return result;
}

bool Date::operator==(const Date& date) const {
	return ((year == date.year) && (mon == date.mon) && (day == date.day) && (hour == date.hour) && (min == date.min) && (sec == date.sec));
}

Date Date::operator+(const DateInterval &intv) const {
	Date result(*this);
	result = result.add_years(intv.get_years());
	result = result.add_months(intv.get_months());
	result = result.add_days(intv.get_days());
	result = result.add_hours(intv.get_hours());
	result = result.add_minutes(intv.get_minutes());
	result = result.add_seconds(intv.get_seconds());
	return result;
}

Date& Date::operator+=(const DateInterval &intv) {
	(*this) = (*this) + intv;
	return *this;
}

Date Date::operator-(const DateInterval &intv) const {
	Date result = *this;
	result = result.add_years(-intv.get_years());
	result = result.add_months(-intv.get_months());
	result = result.add_days(-intv.get_days());
	result = result.add_hours(-intv.get_hours());
	result = result.add_minutes(-intv.get_minutes());
	result = result.add_seconds(-intv.get_seconds());
	return result;
}

Date& Date::operator-=(const DateInterval &intv) {
	(*this) = (*this) - intv;
	return *this;
}

Date& Date::operator++() {
	*this = (*this).add_seconds(1);
	return *this;
}

Date Date::operator++(int) {
	Date d(*this);
	++(*this);
	return d;
}

Date& Date::operator--() {
	*this = (*this).add_seconds(-1);
	return *this;
}

Date Date::operator--(int) {
	Date d(*this);
	--(*this);
	return d;
}

std::string Date::format_date(std::string format) {
	std::string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	std::string cur_sign = "\0";
	std::stringstream out("\0");
	int i = 0;
	while (i <= format.size() - 1) {
	    cur_sign += format[i];
		if (i <=  format.size() - 2) cur_sign += format[i + 1];
		if (i <=  format.size() - 3) cur_sign += format[i + 2];
		if (i <= format.size() - 4) cur_sign += format[i + 3];
	    if (cur_sign == "YYYY") {
				out.fill('0');
				out.width(4);
				out << year;
				cur_sign = "\0";
				i += 4;
				continue;
			}
		if (i <= format.size() - 4)	cur_sign.erase(cur_sign.size() - 1);
		if (cur_sign == "MMM") {
				out << months[int(mon) - 1];
				cur_sign = "\0";
				i += 3;
				continue;
			}
		if (i <= format.size() - 3) cur_sign.erase(cur_sign.size() - 1);
		if (cur_sign == "MM") {
			out.fill('0');
			out.width(2);
			out << int(mon);
			cur_sign = "\0";
			i += 2;
			continue;
			}
		if (cur_sign == "DD") {
			out.fill('0');
			out.width(2);
			out << day;
			cur_sign = "\0";
			i += 2;
			continue;
			}
		if (cur_sign == "hh") {
				out.fill('0');
				out.width(2);
				out << hour;
				cur_sign = "\0";
				i += 2;
				continue;
			}
		if (cur_sign == "mm") {
				out.fill('0');
				out.width(2);
				out << min;
				cur_sign = "\0";
				i += 2;
				continue;
			}
		if (cur_sign == "ss") {
				out.fill('0');
				out.width(2);
				out << sec;
				cur_sign = "\0";
				i += 2;
				continue;
			}	
	    out << format[i];
		cur_sign = "\0";
		i++;
	}
	return out.str();
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

