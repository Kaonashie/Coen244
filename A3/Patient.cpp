//
// Created by soma on 26/05/25.
//

#include "Patient.h"
/**
 * Default constructor
 */
Patient::Patient() : Person(), date_admitted(Date()), bed_number(0) {}

/**
 * Parameterized constructor
 *
 * @param name name of the Person
 * @param dob date of birth of the Person
 * @param min medical insurance number
 * @param d_name doctor's name
 * @param date_admitted date_admitted to the hospital
 * @param bed_number bed number
 */
Patient::Patient(std::string name, const Date &dob, std::string min, std::string d_name, const Date &date_admitted,
				 int bed_number) :
	medical_insurance_number(min), doctor_name(d_name), Person(name, dob), date_admitted(date_admitted),
	bed_number(bed_number) {};

/**
 * Gets the medical insurance number of the patient
 *
 * @return medical insurance number as a string
 */
std::string Patient::get_medical_insurance_number() const { return this->medical_insurance_number; }

/**
 * Gets the patient's doctor's name.
 *
 * @return doctor's name as a string
 */
std::string Patient::get_doctor_name() const { return this->doctor_name; }

/**
 * Gets the date at which the patient was admitted.
 *
 * @return date admitted as a Date object
 */
Date Patient::get_date_admitted() const { return this->date_admitted; }

/**
 * Gets the patient's bed number.
 *
 * @return patient's bed number as an integer
 */
int Patient::get_bed_number() const { return this->bed_number; }

/**
 * Sets a new medical insurance number.
 *
 * @param new_min new medical insurance number value as an int.
 * @return Patient* to allow cascading.
 */
Patient *Patient::set_medical_insurance_number(const std::string &new_min) {
	this->medical_insurance_number = new_min;
	return this;
}

/**
 * Sets a new doctor name
 *
 * @param new_name new doctor's name as a string.
 * @return Patient* to allow cascading.
 */
Patient *Patient::set_doctor_name(const std::string &new_name) {
	this->doctor_name = new_name;
	return this;
}

/**
 * Sets a new date of admission.
 *
 * @param new_date_admitted new date of admission, as a Date object.
 * @return Patient* to allow cascading.
 */
Patient *Patient::set_date_admitted(Date &new_date_admitted) {
	this->date_admitted = new_date_admitted;
	return this;
}

/**
 * Sets a new bed number.
 * @param new_bed_number new bed number, as an int
 * @return Patient* to allow cascading.
 */
Patient *Patient::set_bed_number(int new_bed_number) {
	this->bed_number = new_bed_number;
	return this;
}

void Patient::print_info() const {
	Person::print_info();
	std::cout << "Medical information number : " << this->get_medical_insurance_number() << "\n"
			  << "Bed number : " << this->get_bed_number() << "\n\n";
}

Patient::~Patient() { std::cout << "Patient object successfully destroyed\n"; }
