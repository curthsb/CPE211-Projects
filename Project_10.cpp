// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 10
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project_10.h"

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************
	// default constructor.  initializes date to 01/01/1900.
Date::Date()
{
	month = 1;
	day = 1;
	year = 1900;
}

	// 3-parameter constructor.  initializes date to user-specified values.
Date::Date(int initMonth, int initDay, int initYear)
{
	month = initMonth;
	day = initDay;
	year = initYear;
}

	// 2-parameter constructor.  initializes date to first day of user-specified month and year.
Date::Date(int initMonth, int initYear)
{
	month = initMonth;
	day = 1;
	year = initYear;
}

// ************** TRANSFORMERS **************
	// sets date to user-specified values.
	// assumes input is within correct ranges.
void Date::SetDate(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

	// increments the day value by one.
	// checks for overflow and corrects as necessary.
void Date::IncrementDate()
{
		// number of days in each month.  corresponding index is (month - 1).
	int maxDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	day++;

		// check for day overflow.  If so, reset day to 1 and increment month.
	if (day > maxDays[month - 1])
	{
		day = 1;
		month++;
	}
		// check for month overflow.  If so, reset month to 1 and increment year.
	if (month > 12)
	{
		month = 1;
		year++;
	}
}

// ************** OBSERVERS *******************

void Date::WriteNumberFormat() const
{
		// output date in "MM/DD/YYYY" format.  Fills single-digit values with leading '0' as necessary.
	cout << setw(2) << setfill('0') << month << "/" << setw(2) << day << "/" << setw(4) << year << endl;
}

void Date::WriteNameFormat() const
{
		// string values for month names.  corresponding index is (month - 1).
	string name[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
		// output date in "MonthName DD, YYYY" format.  Pulls month name from the string array. 
	cout << name[month - 1] << " " << day << ", " << year << endl;
}

bool Date::SameDate(Date otherDate) const
{
		// compares two Date objects for identical day, month, and year values.
		// returns true if all values match, false otherwise
	if((month == otherDate.month) && (day == otherDate.day) && (year == otherDate.year))
		return 1;
	
	return 0;
}