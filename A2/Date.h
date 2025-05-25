//
// Created by soma on 20/05/25.
//

#ifndef DATE_H
#define DATE_H
#include <iostream>


class Date {
private:
	int month, day, year;

public:
	Date();
	Date(int m, int d, int y);

	int get_month() const;
	int get_day() const;
	int get_year() const;

	void set_month(int m);
	void set_day(int d);
	void set_year(int y);
	friend std::ostream &operator<<(std::ostream &os, const Date &dt);

	~Date();
};


#endif // DATE_H
