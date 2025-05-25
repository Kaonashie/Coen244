//
// Created by soma on 20/05/25.
//

#include "Doctor.h"

/**
 * Default constructor
 * Initializes a doctor with an empty name and all appointment slots set to nullptr
 */
Doctor::Doctor() : name("") { // Initialize name in the initializer list
	for (auto &day: appointments) {
		for (auto &hour: day) {
			hour = nullptr; // Initialize each appointment pointer to nullptr
		}
	}
}

/**
 * Retrieves the name of the doctor
 * 
 * @return Doctor's name as a string
 */
std::string Doctor::get_name() const { return this->name; }

/**
 * Retrieves the doctor's appointments
 * 
 * @return 2D array of pointers to Patient objects representing appointments
 */
std::array<std::array<Patient *, 12>, 5> Doctor::get_appointments() const { return this->appointments; }

/**
 * Sets the name of the doctor
 * 
 * @param name Doctor's name to set
 * @return Reference to the current Doctor object for method chaining
 */
Doctor &Doctor::set_name(const std::string &name) {
	this->name = name;
	return *this;
}

/**
 * Sets the doctor's appointments
 * 
 * @param appointments 2D array of pointers to Patient objects representing appointments
 * @return Reference to the current Doctor object for method chaining
 */
Doctor &Doctor::set_appointments(std::array<std::array<Patient *, 12>, 5> &appointments) {
	this->appointments = appointments;
	return *this;
}

/**
 * Default destructor
 */
Doctor::~Doctor() { std::cout << "Doctor object destroyed successfully \n"; }