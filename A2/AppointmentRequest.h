//
// Created by soma on 20/05/25.
//

#ifndef APPOINTMENTREQUEST_H
#define APPOINTMENTREQUEST_H

#include <iostream>
#include <string>

/**
 * AppointmentRequest Class
 * Represents a request for an appointment in the medical clinic system.
 * Stores the patient's name, doctor's name, and the requested day for the appointment.
 * Provides methods to get and set these attributes, and a destructor for cleanup.
 */

class AppointmentRequest {
private:
	std::string patient_name, doctor_name, day;

public:
	// Default constructor
	AppointmentRequest();

	// Parameterized constructor
	AppointmentRequest(const std::string &p_name, const std::string &d_name, const std::string &day);

	// Getter methods
	std::string get_patient_name() const;
	std::string get_doctor_name() const;
	std::string get_day() const;

	// Setter methods
	void set_patient_name(const std::string &p_name);
	void set_doctor_name(const std::string &d_name);
	void set_day(const std::string &day);

	// Destructor
	~AppointmentRequest();
};


#endif // APPOINTMENTREQUEST_H
