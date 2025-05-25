//
// Created by soma on 20/05/25.
//

#ifndef APPOINTMENTTIME_H
#define APPOINTMENTTIME_H

#include <iostream>
#include <string>

/**
 * AppointmentTime Class
 * Represents a specific time for an appointment in the medical clinic system.
 * Stores the day of the week, hour, and minute of the appointment.
 * Provides methods to get and set these attributes, and an overloaded output operator for easy printing.
 */
class AppointmentTime {
private:
	std::string day;
	int hour, minute;

public:
	// Default constructor
	AppointmentTime();

	// Parameterized constructor
	AppointmentTime(const std::string &day, int h, int m);

	// Getter methods
	std::string get_day() const;
	int get_hour() const;
	int get_minute() const;

	// Setter methods
	void set_day(const std::string &day);
	void set_hour(int h);
	void set_minute(int m);

	// Overloaded output operator
	friend std::ostream &operator<<(std::ostream &os, const AppointmentTime &at);
	
	// Destructor
	~AppointmentTime();
};


#endif // APPOINTMENTTIME_H
