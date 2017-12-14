#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Calendar.h"
#include "Date.h"
#include "DateInterval.h"

TEST_CASE("add_years1", "test1")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2100, Month::January, 1, 0, 0, 0);
	REQUIRE(input.add_years(100) == exp);
}

TEST_CASE("add_years2", "test2")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1900, Month::January, 1, 0, 0, 0);
	REQUIRE(input.add_years(-100) == exp);
}

TEST_CASE("add_years3", "test3")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2100, Month::January, 1, 0, 0, 0);
	REQUIRE(input.add_years(100) == exp);
}


TEST_CASE("add_months1", "test4")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::February, 1, 0, 0, 0);
	REQUIRE(input.add_months(1) == exp);
}

TEST_CASE("add_months2", "test5")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 1, 0, 0, 0);
	REQUIRE(input.add_months(-1) == exp);
}

TEST_CASE("add_months3", "test6")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2002, Month::January, 1, 0, 0, 0);
	REQUIRE(input.add_months(24) == exp);
}

TEST_CASE("add_months4", "test7")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::July, 1, 0, 0, 0);
	REQUIRE(input.add_months(-6) == exp);
}

TEST_CASE("add_days1", "test8")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 2, 0, 0, 0);
	REQUIRE(input.add_days(1) == exp);
}

TEST_CASE("add_days2", "test9")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 31, 0, 0, 0);
	REQUIRE(input.add_days(-1) == exp);
}

TEST_CASE("add_days3", "test10")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::February, 1, 0, 0, 0);
	REQUIRE(input.add_days(31) == exp);
}

TEST_CASE("add_days4", "test11")
{
	Date input(2000, Month::February, 1, 0, 0, 0);
	Date exp(2000, Month::February, 28, 0, 0, 0);
	REQUIRE(input.add_days(27) == exp);
}

TEST_CASE("add_days5", "test12")
{
	Date input(2000, Month::February, 1, 0, 0, 0);
	Date exp(2000, Month::February, 29, 0, 0, 0);
	REQUIRE(input.add_days(28) == exp);
}

TEST_CASE("add_days6", "test13")
{
	Date input(2000, Month::February, 1, 0, 0, 0);
	Date exp(2000, Month::March, 1, 0, 0, 0);
	REQUIRE(input.add_days(29) == exp);
}

TEST_CASE("add_days7", "test14")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2001, Month::May, 15, 0, 0, 0);
	REQUIRE(input.add_days(500) == exp);
}

TEST_CASE("add_days8", "test15")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1998, Month::August, 19, 0, 0, 0);
	REQUIRE(input.add_days(-500) == exp);
}

TEST_CASE("add_hours1", "test16")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 1, 1, 0, 0);
	REQUIRE(input.add_hours(1) == exp);
}

TEST_CASE("add_hours2", "test17")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 31, 23, 0, 0);
	REQUIRE(input.add_hours(-1) == exp);
}

TEST_CASE("add_hours3", "test18")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 2, 0, 0, 0);
	REQUIRE(input.add_hours(24) == exp);
}

TEST_CASE("add_hours4", "test19")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 31, 0, 0, 0);
	REQUIRE(input.add_hours(-24) == exp);
}

TEST_CASE("add_hours5", "test20")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 21, 20, 0, 0);
	REQUIRE(input.add_hours(500) == exp);
}

TEST_CASE("add_hours6", "test21")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 11, 4, 0, 0);
	REQUIRE(input.add_hours(-500) == exp);
}


TEST_CASE("add_minutes1", "test22")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 1, 0, 1, 0);
	REQUIRE(input.add_minutes(1) == exp);
}

TEST_CASE("add_minutes2", "test23")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 31, 23, 59, 0);
	REQUIRE(input.add_minutes(-1) == exp);
}

TEST_CASE("add_minutes3", "test24")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 1, 1, 0, 0);
	REQUIRE(input.add_minutes(60) == exp);
}

TEST_CASE("add_minutes4", "test25")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 31, 23, 00, 0);
	REQUIRE(input.add_minutes(-60) == exp);
}

TEST_CASE("add_minutes5", "test26")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 4, 11, 20, 0);
	REQUIRE(input.add_minutes(5000) == exp);
}

TEST_CASE("add_minutes6", "test27")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 28, 12, 40, 0);
	REQUIRE(input.add_minutes(-5000) == exp);
}

TEST_CASE("add_seconds1", "test28")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 1, 0, 0, 1);
	REQUIRE(input.add_seconds(1) == exp);
}

TEST_CASE("add_seconds2", "test29")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 31, 23, 59, 59);
	REQUIRE(input.add_seconds(-1) == exp);
}

TEST_CASE("add_seconds3", "test30")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 1, 0, 1, 0);
	REQUIRE(input.add_seconds(60) == exp);
}
TEST_CASE("add_seconds4", "test31")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 31, 23, 59, 0);
	REQUIRE(input.add_seconds(-60) == exp);
}

TEST_CASE("add_seconds5", "test32")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(2000, Month::January, 1, 2, 46, 40);
	REQUIRE(input.add_seconds(10000) == exp);
}

TEST_CASE("add_seconds6", "test33")
{
	Date input(2000, Month::January, 1, 0, 0, 0);
	Date exp(1999, Month::December, 31, 21, 13, 20);
	REQUIRE(input.add_seconds(-10000) == exp);
}

TEST_CASE("operator+=1", "test34")
{
	Date output(2000, Month::January, 1, 0, 0, 0);
	DateInterval intv(0, 0, 11, 10, 9, 0);
	Date exp(2000, Month::January, 12, 10, 9, 0);
	output += intv;
	REQUIRE(output == exp);
}

TEST_CASE("operator-=1", "test35")
{
	Date output(2000, Month::January, 1, 0, 0, 0);
	DateInterval intv(0, 0, 11, 10, 9, 0);
	Date exp(1999, Month::December, 20, 13, 51, 0);
	output -= intv;
	REQUIRE(output == exp);
}
