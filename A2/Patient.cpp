//
// Created by soma on 20/05/25.
//

#include "Patient.h"

/**
 * Default constructor
 * Initializes a patient with empty values
 */
Patient::Patient() {
	this->date_of_birth = nullptr;
	this->appointment_time = nullptr; // Default constructor
	this->name = "";
	this->doctor_name = "";
	this->medical_insurance_number = "";
}

/**
 * Parameterized constructor
 * Creates a patient with complete information
 * 
 * @param dob Pointer to the patient's date of birth
 * @param appt_time Pointer to the patient's appointment time
 * @param name Patient's name
 * @param d_name Doctor's name assigned to the patient
 * @param med_ins_num Patient's medical insurance number
 */
Patient::Patient(Date *dob, AppointmentTime *appt_time, const std::string &name, const std::string &d_name,
				 const std::string &med_ins_num) {
	this->date_of_birth = dob;
	this->appointment_time = appt_time;
	this->name = name;
	this->doctor_name = d_name;
	this->medical_insurance_number = med_ins_num;
}

/**
 * Retrieves the patient's date of birth
 * 
 * @return Pointer to the Date object representing the patient's date of birth 
 */
const Date *Patient::get_date_of_birth() const { return this->date_of_birth; }

/**
 * Retrieves the patient's appointment time
 * 
 * @return Pointer to the AppointmentTime object representing the patient's appointment time
 */
const AppointmentTime *Patient::get_appointment_time() const { return this->appointment_time; }

/**
 * Retrieves the patient's name
 * 
 * @return The patient's name as a string
 */
std::string Patient::get_name() const { return this->name; }

/**
 * Retrieves the doctor assigned to the patient
 * 
 * @return The doctor's name as a string
 */
std::string Patient::get_doctor_name() const { return this->doctor_name; }

/**
 * Retrieves the patient's medical insurance number
 * 
 * @return The patient's medical insurance number
 */
std::string Patient::get_medical_insurance_number() const { return this->medical_insurance_number; }


/**
 * Sets the patient's date of birth
 * 
 * @param dob Pointer to Date object representing date of birth
 * @return Reference to this patient for method chaining
 */
Patient &Patient::set_date_of_birth(Date *dob) {
	this->date_of_birth = dob;
	return *this;
}

/**
 * Sets the patient's appointment time
 * Note: Patient is only allowed one appointment at a time
 * 
 * @param new_appt_time Pointer to AppointmentTime object
 * @return Reference to this patient for method chaining
 */
Patient &Patient::set_appointment_time(AppointmentTime *new_appt_time) {
	// if (this->appointment_time != nullptr && this->appointment_time != new_appt_time) {
	//     delete this->appointment_time; // Delete old appointment if it exists and is different
	// }
	this->appointment_time = new_appt_time;
	return *this;
}

/**
 * Sets the doctor assigned to the patient
 * 
 * @param d_name Name of the doctor
 * @return Reference to this patient for method chaining
 */
Patient &Patient::set_doctor_name(const std::string &d_name) {
	this->doctor_name = d_name;
	return *this;
}

/**
 * Sets the patient's name
 * 
 * @param name The patient's name
 * @return Reference to this patient for method chaining
 */
Patient &Patient::set_name(const std::string &name) {
	this->name = name;
	return *this;
}

/**
 * Sets the patient's medical insurance number
 * 
 * @param med_ins_num Medical insurance number
 * @return Reference to this patient for method chaining
 */
Patient &Patient::set_medical_insurance_number(const std::string &med_ins_num) {
	this->medical_insurance_number = med_ins_num;
	return *this;
}

/**
 * Destructor
 * Cleans up memory used by the patient object
 * Note: date_of_birth is not deleted since it might be shared between patients
 */
Patient::~Patient() {
	// date_of_birth is potentially shared as per main.cpp, so Patient should not delete it.
	// delete date_of_birth;
	if (appointment_time != nullptr) {
		// delete appointment_time; // Patient owns and deletes its specific AppointmentTime object.
		this->appointment_time = nullptr; // Good practice.
	}
	std::cout << "Patient object destroyed successfully \n";
}
