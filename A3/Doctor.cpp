//
// Created by soma on 26/05/25.
//

#include "Doctor.h"

Doctor::Doctor() : Person(), id(0), patients{} {
	std::cout << "Doctor object created successfully \n";
}

Doctor::Doctor(int id, Date dob, const std::string name) : Person(name, dob), id(id) {};


int Doctor::get_id() const {
	return this->id;
}

Patient* Doctor::get_patient(int i) const {
	return this->patients[i];
}

void Doctor::set_id(int new_id) {
	this->id = new_id;
}

void Doctor::add_patient(Patient* new_patient) {
	for (auto &p: this->patients) {
		if (p == nullptr) {
			p = new_patient;
			std::cout << "Patient added to doctor successfully \n";
			return;
		}
	}
}

void Doctor::remove_patient(Patient* pat) {
	for (int i = 0; i < 50; i++) {
		if (patients[i]->get_medical_insurance_number() == pat->get_medical_insurance_number()) {
			patients[i] == nullptr;
			return;
		}
	}

	std::cout << "Did not find the patient to remove from the doctor's array\n";
}

Doctor::~Doctor() {
	for (int i = 0; i < 50; i++) {
		if (patients[i] != nullptr) {
			delete patients[i];
		}
	}
	std::cout << "Doctor object destroyed successfully \n";
}