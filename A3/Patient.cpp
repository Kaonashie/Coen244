//
// Created by soma on 26/05/25.
//

#include "Patient.h"

Patient::Patient() : date_admitted(Date()), bed_number(0), Person(){  }
 Patient::Patient(std::string &min, std::string &name, Date &date_admitted, int bed_number) {
	this->medical_insurance_number = min;
	this->doctor_name = name;
	this->date_admitted = date_admitted;
	this->bed_number = bed_number;
}


std::string Patient::get_medical_insurance_number() const { return this->medical_insurance_number; }
std::string Patient::get_doctor_name() const{return this->doctor_name; }
Date Patient::get_date_admitted() const{return this->date_admitted; }
int Patient::get_bed_number() const{return this->bed_number; }

Patient* Patient::set_medical_insurance_number(const std::string &new_min) {
	this->medical_insurance_number = new_min;
	return this;
}

Patient* Patient::set_doctor_name(const std::string &new_name) {
	this->doctor_name = new_name;
	return this;
}

Patient* Patient::set_date_admitted(Date &new_date_admitted) {
	this->date_admitted = new_date_admitted;
	return this;
}
Patient* Patient::set_bed_number(int new_bed_number) {
	this->bed_number = new_bed_number;
	return this;
}

 Patient::~Patient() {  }
