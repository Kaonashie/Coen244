//
// Created by soma on 20/05/25.
//

#include "Date.h"

// Constructors
Date::Date() {
    this->month = 0;
    this->day = 0;
    this->year = 0;
}

Date::Date(int m, int d, int y) {
    this->month = m;
    this->day = d;
    this->year = y;
}

// Getter methods
int Date::get_month() const { return this->month; }

int Date::get_day() const { return this->day; }

int Date::get_year() const { return this->year; }

// Setter methods
void Date::set_month(int m) { this->month = m; }

void Date::set_day(int d) { this->day = d; }

void Date::set_year(int y) { this->year = y; }

// Print function
void Date::print_info() const { std::cout << day << " " << month << " " << year << "\n"; }

// Operator overload
std::ostream &operator<<(std::ostream &os, const Date &dt) {
    os << dt.day << "/" << dt.month << "/" << dt.year;
    return os;
}

// Destructor
Date::~Date() { std::cout << "Date object destroyed successfully \n"; }
