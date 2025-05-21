//
// Created by soma on 20/05/25.
//

#ifndef APPOINTMENTTIME_H
#define APPOINTMENTTIME_H

#include <iostream>
#include <string>

class AppointmentTime {
private:
	std::string day;
	int hour, minute;

public:
	AppointmentTime();
	AppointmentTime(const std::string &day, int h, int m);

	std::string get_day() const;
	int get_hour() const;
	int get_minute() const;

	void set_day(const std::string &day);
	void set_hour(int h);
	void set_minute(int m);

	friend std::ostream &operator<<(std::ostream &os,const AppointmentTime &at);
	~AppointmentTime();
};


#endif // APPOINTMENTTIME_H
