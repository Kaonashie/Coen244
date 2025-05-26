//
// Created by soma on 20/05/25.
//

#include "Date.h"

// Default constructor
Date::Date() {
	this->month = 0;
	this->day = 0;
	this->year = 0;
}
/**
 * Parameterized constructor
 * Initializes a Date object with specified month, day, and year
 * @param m Month of the date
 * @param d Day of the date
 * @param y Year of the date
 */
Date::Date(int m, int d, int y) {
	this->month = m;
	this->day = d;
	this->year = y;
}

// Getter methods
/**
 * Gets the month of the date object
 * @return Month as an integer
 */
int Date::get_month() const { return this->month; }

/**
 * Gets the day of the date object
 * @return Day as an integer
 */
int Date::get_day() const { return this->day; }

/**
 * Gets the year of the date object
 * @return Year as an integer
 */
int Date::get_year() const { return this->year; }

// Setter methods
/**
 * Sets the month of the date object
 * @param m Month to set
 */
void Date::set_month(int m) { this->month = m; }

/**
 * Sets the day of the date object
 * @param d Day to set
 */
void Date::set_day(int d) { this->day = d; }

/**
 * Sets the year of the date object
 * @param y Year to set
 */
void Date::set_year(int y) { this->year = y; }

/**
 * Overloaded output operator for Date class
 * Formats the date as "day/month/year"
 * 
 * @param os Output stream to write to
 * @param dt Date object to format
 * @return Reference to the output stream
 */
std::ostream &operator<<(std::ostream &os, const Date &dt) {
	os << dt.day << "/" << dt.month << "/" << dt.year;
	return os;
}

// Destructor
Date::~Date() { std::cout << "Date object destroyed successfully \n"; }
