//
// Created by soma on 20/05/25.
//

#include "AppointmentRequest.h"

// Default constructor
AppointmentRequest::AppointmentRequest() {
	this->doctor_name = "";
	this->patient_name = "";
	this->day = "";
}

/**
 * Parameterized constructor
 * Initializes an AppointmentRequest object with specified patient name, doctor name, and day
 * 
 * @param p_name Patient's name
 * @param d_name Doctor's name
 * @param day Day of the week for the appointment
 */
AppointmentRequest::AppointmentRequest(const std::string &p_name, const std::string &d_name, const std::string &day) {
	this->doctor_name = d_name;
	this->patient_name = p_name;
	this->day = day;
}

/**
 * Retrieves the patient's name from the appointment request
 * 
 * @return Patient's name as a string
 */
std::string AppointmentRequest::get_patient_name() const { return this->patient_name; }

/**
 * Retrieves the doctor's name from the appointment request
 * 
 * @return Doctor's name as a string
 */
std::string AppointmentRequest::get_doctor_name() const { return this->doctor_name; }

/**
 * Retrieves the day of the week for the appointment request
 * 
 * @return Day of the week as a string
 */
std::string AppointmentRequest::get_day() const { return this->day; }

/**
 * Sets the patient's name for the appointment request
 * 
 * @param p_name Patient's name to set
 */
void AppointmentRequest::set_doctor_name(const std::string &d_name) { this->doctor_name = d_name; }

/**
 * Sets the patient's name for the appointment request
 * 
 * @param p_name Patient's name to set
 */
void AppointmentRequest::set_patient_name(const std::string &p_name) { this->patient_name = p_name; }

/**
 * Sets the day of the week for the appointment request
 * 
 * @param day Day of the week to set
 */
void AppointmentRequest::set_day(const std::string &day) { this->day = day; }

/**
 * Destructor
 * Cleans up resources used by the AppointmentRequest object
 */
AppointmentRequest::~AppointmentRequest() { std::cout << "AppointmentRequest object destroyed successfully \n"; }
