//
// Created by soma on 20/05/25.
//

#include "AppointmentTime.h"

// Default constructor
AppointmentTime::AppointmentTime() {
	this->day = "";
	this->hour = 0;
	this->minute = 0;
}

/**
 * Parameterized constructor
 * Initializes an AppointmentTime object with specified day, hour, and minute
 * 
 * @param day Day of the week for the appointment
 * @param h Hour of the appointment (0-23)
 * @param m Minute of the appointment (0-59)
 */
AppointmentTime::AppointmentTime(const std::string &day, int h, int m) {
	this->day = day;
	this->hour = h;
	this->minute = m;
}

/**
 * Retrieves the day of the appointment
 * @return Day of the week as a string
 */
std::string AppointmentTime::get_day() const { return this->day; }

/**
 * Retrieves the hour of the appointment
 * @return Hour of the appointment (0-23)
 */
int AppointmentTime::get_hour() const { return this->hour; }

/**
 * Retrieves the minute of the appointment
 * @return Minute of the appointment (0-59)
 */
int AppointmentTime::get_minute() const { return this->minute; }


/**
 * Sets the day of the appointment
 * 
 * @param day Day of the week to set
 */
void AppointmentTime::set_day(const std::string &day) { this->day = day; }

/**
 * Sets the hour of the appointment
 * 
 * @param h Hour of the appointment (0-23)
 */
void AppointmentTime::set_hour(int h) { this->hour = h; }

/**
 * Sets the minute of the appointment
 * 
 * @param m Minute of the appointment (0-59)
 */
void AppointmentTime::set_minute(int m) { this->minute = m; }


/**
 * Overloaded output operator for AppointmentTime class
 * 
 * @param os Output stream to write to
 * @param at AppointmentTime object to output
 * @return Reference to the output stream
 */
std::ostream &operator<<(std::ostream &os, const AppointmentTime &at) {
	os << at.get_day() << " at " << at.get_hour() << "h " << at.get_minute() << "m \n";
	return os;
}

/**
 * Destructor for AppointmentTime class
 */
AppointmentTime::~AppointmentTime() { std::cout << "AppointmentTime object destroyed successfully \n"; }