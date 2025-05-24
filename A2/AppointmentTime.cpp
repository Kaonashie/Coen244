//
// Created by soma on 20/05/25.
//

#include "AppointmentTime.h"

AppointmentTime::AppointmentTime() {
	this->day = "";
	this->hour = 0;
	this->minute = 0;
}

AppointmentTime::AppointmentTime(const std::string &day, int h, int m) {
	this->day = day;
	this->hour = h;
	this->minute = m;
}

std::string AppointmentTime::get_day() const {
	return this->day;
}

int AppointmentTime::get_hour() const {
	return this->hour;
}

int AppointmentTime::get_minute() const {
	return this->minute;
}

void AppointmentTime::set_day(const std::string &day) {
	this->day = day;
}

void AppointmentTime::set_hour(int h) {
	this->hour = h;
}

void AppointmentTime::set_minute(int m) {
	this->minute = m;
}

std::ostream &operator<<(std::ostream &os, const AppointmentTime &at) {
	os << at.get_day() << " at " << at.get_hour() << "h " << at.get_minute() << "m \n";
	return os;
}

AppointmentTime::~AppointmentTime() {
	std::cout << "AppointmentTime object destroyed successfully \n";
}
