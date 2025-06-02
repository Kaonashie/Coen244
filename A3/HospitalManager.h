//
// Created by soma on 26/05/25.
//

#ifndef HOSPITALMANAGER_H
#define HOSPITALMANAGER_H
#include <array>
#include <iostream>

#include "Doctor.h"
#include "Patient.h"

/**
 * HospitalManager Class
 * Represents a hospital with an array of patients, doctors and how many free beds are available.
 * Provides methods to get, set and print members, as well as to print a specific patient's info or all patients info.
 */
class HospitalManager {
private:
	Doctor *doctors[20]{};
	Patient *patients[101]{};
	int total_free_beds;

public:
	// Constructor
	HospitalManager();

	// Getters
	Doctor *get_doctor(int index) const { return doctors[index]; }
	Patient *get_patient(int index) const { return patients[index]; }
	int get_free_beds() const { return total_free_beds; }

	// Setters
	void insert_doctor(Doctor &new_doc);
	int admit_patient(Patient &new_pat);
	void discharge_patient(Patient &pat);

	// Utility functions
	int get_bed_number(const std::string &patient_name) const;
	void print_patient_info(std::string doc_name) const;
	void print_all_patients() const;

	// Destructor
	~HospitalManager();
};

#endif // HOSPITALMANAGER_H
