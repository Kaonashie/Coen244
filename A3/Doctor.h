//
// Created by soma on 26/05/25.
//

#ifndef DOCTOR_H
#define DOCTOR_H
#include <array>
#include <iostream>

#include "Patient.h"
#include "Person.h"

/**
 * Doctor class.
 * Represents a doctor, derived from a Person, with an id and an array of it's patients.
 * Provides functions to get, set and print member variables as well as to add and remove patients from the array.
 */
class Doctor : public Person {
private:
	int id;
	Patient *patients[50]{};

public:
	// Constructors
	Doctor();
	Doctor(int id, Date dob, const std::string name);

	// Getters
	int get_id() const;
	Patient *get_patient(int i) const;

	// Setters
	void set_id(int new_id);
	void add_patient(Patient *new_patient);
	void remove_patient(Patient *pat);

	// Print
	void print_info() const;

	// Destructor
	~Doctor();
};


#endif // DOCTOR_H
