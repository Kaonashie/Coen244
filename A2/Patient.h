//
// Created by soma on 20/05/25.
//

#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include "AppointmentTime.h"
#include "Date.h"

/**
 * Patient Class
 * Represents a patient in the medical clinic system.
 * Stores patient's personal information, doctor assignment, and appointment details.
 * Each patient can have only one doctor appointment per week.
 */
class Patient {
private:
	Date *date_of_birth;
	AppointmentTime *appointment_time;
	std::string name, doctor_name, medical_insurance_number;

public:
	// Default constructor - initializes a patient with empty values
	Patient();
	
	// Parameterized constructor - creates a patient with all required information
	Patient(Date *dob, AppointmentTime *appt_time, const std::string &name, const std::string &d_name,
			const std::string &med_ins_num);

	// Getter methods - provide access to private member data
	const Date *get_date_of_birth() const;
	const AppointmentTime *get_appointment_time() const;
	std::string get_name() const;
	std::string get_doctor_name() const;
	std::string get_medical_insurance_number() const;

	// Setter methods - update private member data and return reference for method chaining
	Patient &set_date_of_birth(Date *dob);
	Patient &set_appointment_time(AppointmentTime *appt_time);
	Patient &set_name(const std::string &name);
	Patient &set_doctor_name(const std::string &d_name);
	Patient &set_medical_insurance_number(const std::string &med_ins_num);

	// Destructor - releases memory resources used by the patient
	~Patient();
};


#endif // PATIENT_H
