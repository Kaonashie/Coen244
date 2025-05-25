//
// Created by soma on 20/05/25.
//

#ifndef APPOINTMENTREQUEST_H
#define APPOINTMENTREQUEST_H

#include <iostream>
#include <string>

class AppointmentRequest {
private:
	std::string patient_name, doctor_name, day;

public:
	AppointmentRequest();
	AppointmentRequest(const std::string &p_name, const std::string &d_name, const std::string &day);

	std::string get_patient_name() const;
	std::string get_doctor_name() const;
	std::string get_day() const;

	void set_patient_name(const std::string &p_name);
	void set_doctor_name(const std::string &d_name);
	void set_day(const std::string &day);

	~AppointmentRequest();
};


#endif // APPOINTMENTREQUEST_H
