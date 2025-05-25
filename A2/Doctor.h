//
// Created by soma on 20/05/25.
//

#ifndef DOCTOR_H
#define DOCTOR_H
#include <array>
#include <iostream>
#include <string>
#include "Patient.h"


/**
 * Doctor Class
 * Represents a doctor in the medical clinic scheduling system.
 * Manages the doctor's weekly schedule using a 2D appointment array.
 * The appointments array uses 5 days (Mon-Fri) with 12 time slots per day
 * (9:00-12:00 and 14:00-17:00, with 30-minute intervals).
 */
class Doctor {
private:
	std::string name;

	// 2D array for appointments: 5 days × 12 slots per day
	// First index (0-4): days of the week (Mon-Fri)
	// Second index (0-11): time slots (6 morning, 6 afternoon)
	/**
	*	I prefer to use std::array here as I find it more readable but c-style arrays could've been used
	*	like this : Patient* appointments[5][12];
	 */
	std::array<std::array<Patient *, 12>, 5> appointments{};

public:
	// Default constructor - initializes a doctor with empty appointment slots
	Doctor();

	// Getter methods
	std::string get_name() const;
	std::array<std::array<Patient *, 12>, 5> get_appointments() const;

	// Setter methods with method chaining capability
	Doctor &set_name(const std::string &name);
	Doctor &set_appointments(std::array<std::array<Patient *, 12>, 5> &appointments);

	// Destructor
	~Doctor();
};


#endif // DOCTOR_H
