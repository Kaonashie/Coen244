//
// Created by soma on 20/05/25.
//

#include "AppointmentRequest.h"

AppointmentRequest::AppointmentRequest() {
	this->doctor_name = "";
	this->patient_name = "";
	this->day = "";
}

AppointmentRequest::AppointmentRequest(const std::string &p_name, const std::string &d_name, const std::string &day) {
	this->doctor_name = d_name;
	this->patient_name = p_name;
	this->day = day;
}

std::string AppointmentRequest::get_patient_name() const { return this->patient_name; }

std::string AppointmentRequest::get_doctor_name() const { return this->doctor_name; }

std::string AppointmentRequest::get_day() const { return this->day; }

void AppointmentRequest::set_doctor_name(const std::string &d_name) { this->doctor_name = d_name; }

void AppointmentRequest::set_patient_name(const std::string &p_name) { this->patient_name = p_name; }

void AppointmentRequest::set_day(const std::string &day) { this->day = day; }

AppointmentRequest::~AppointmentRequest() { std::cout << "AppointmentRequest object destroyed successfully \n"; }
