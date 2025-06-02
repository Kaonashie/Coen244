//
// Created by soma on 26/05/25.
//

#include "Doctor.h"

/**
 * Default constructor.
 */
Doctor::Doctor() : Person(), id(0), patients{} { std::cout << "Doctor object created successfully \n"; }

Doctor::Doctor(int id, Date dob, const std::string name) : Person(name, dob), id(id) {};

/**
 * Gets the doctor's id.
 * @return id as an int.
 */
int Doctor::get_id() const { return this->id; }

/**
 * Gets a patient at index i of the array of patients
 * @param i index of the patient to retrieve
 * @return patient as a Patient object.
 */
Patient *Doctor::get_patient(int i) const { return this->patients[i]; }

/**
 * Sets a new id
 * @param new_id new id to set, as int
 */
void Doctor::set_id(int new_id) { this->id = new_id; }

/**
 * Adds a new patient to the patient array.
 * @param new_patient new patient to add
 */
void Doctor::add_patient(Patient *new_patient) {
	for (auto &p: this->patients) {
		if (p == nullptr) {
			p = new_patient;
			std::cout << "Patient added to doctor successfully \n";
			return;
		}
	}
}

/**
 * Removes a patient from the array.
 * @param pat patient to remove from the array
 */
void Doctor::remove_patient(Patient *pat) {
	for (int i = 0; i < 50; i++) {
		if (patients[i] != nullptr && patients[i]->get_medical_insurance_number() == pat->get_medical_insurance_number()) {
			patients[i] = nullptr;
			return;
		}
	}

	std::cout << "Did not find the patient to remove from the doctor's array\n";
}

/**
 * Prints information about the doctor
 */
void Doctor::print_info() const {
	Person::print_info();
	std::cout << "ID: " << id << "\n";
}

/**
 * Destructor.
 */
Doctor::~Doctor() { std::cout << "Doctor object destroyed successfully \n"; }
