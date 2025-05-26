//
// Created by soma on 20/05/25.
//

#ifndef DATE_H
#define DATE_H
#include <iostream>

/**
 * Date Class
 * Represents a date with month, day, and year attributes.
 * Provides methods to get and set date components, and to output the date in a formatted string.
 */

class Date {
private:
	int month, day, year;

public:
	// Default constructor
	Date();

	// Parameterized constructor
	Date(int m, int d, int y);

	// Getter methods
	int get_month() const;
	int get_day() const;
	int get_year() const;

	// Setter methods
	void set_month(int m);
	void set_day(int d);
	void set_year(int y);

	// Overloaded output operator for Date class
	friend std::ostream &operator<<(std::ostream &os, const Date &dt);

	// Destructor
	~Date();
};


#endif // DATE_H
