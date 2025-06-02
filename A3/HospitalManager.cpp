//
// Created by soma on 26/05/25.
//

#include "HospitalManager.h"

/**
 * Default constructor.
 */
HospitalManager::HospitalManager() : total_free_beds(100) {
	for (int i = 0; i < 20; i++) {
		doctors[i] = nullptr;
	}

	for (int i = 0; i < 101; i++) {
		patients[i] = nullptr;
	}
}

/**
 * Inserts a doctors in the array.
 * @param new_doc new doctor to insert in the array
 */
void HospitalManager::insert_doctor(Doctor &new_doc) {
	for (int i = 0; i < 20; i++) {
		if (doctors[i] == nullptr) {
			doctors[i] = &new_doc;
			std::cout << "Doctor added\n";
			return;
		}
	}
	std::cout << "All doctor slots are taken\n";
}

/**
 * Adds a new patient to the array and sets the patient's bed number.
 * @param new_pat new patient to insert into the array
 * @return bed number, 0 if no beds available.
 */
int HospitalManager::admit_patient(Patient &new_pat) {
	if (total_free_beds == 0) {
		std::cout << "No free beds available\n";
		return 0;
	}

	for (int i = 0; i < 20; i++) {
		if (doctors[i] != nullptr) {
			if (new_pat.get_doctor_name() == doctors[i]->get_name()) {
				doctors[i]->add_patient(&new_pat);
			}
		}
	}

	for (int i = 1; i < 101; i++) {
		if (patients[i] == nullptr) {
			patients[i] = &new_pat;
			patients[i]->set_bed_number(i);
			total_free_beds--;
			return i;
		}
	}
	return 0;
}

/**
 * removes a patient from the patient array, removes the patient from the doctor's array.
 * @param pat patient to remove from the hospital
 */
void HospitalManager::discharge_patient(Patient &pat) {
	for (int i = 0; i < 20; i++) {
		if (doctors[i] != nullptr) {
			if (pat.get_doctor_name() == doctors[i]->get_name()) {
				doctors[i]->remove_patient(&pat);
			}
		}
	}
	if (patients[pat.get_bed_number()]->get_medical_insurance_number() == pat.get_medical_insurance_number()) {
		std::cout << "Successfully discharged patient " << pat.get_name() << "\n";
		delete patients[pat.get_bed_number()];
		patients[pat.get_bed_number()] = nullptr;
		total_free_beds++;
	}
}

/**
 * Returns a patient's bed number
 * @param patient_name patient's name
 * @return bed number, 0 if no bed number found
 */
int HospitalManager::get_bed_number(const std::string &patient_name) const {
	for (int i = 1; i < 101; i++) {
		if (patients[i] != nullptr && patients[i]->get_name() == patient_name) {
			return i;
		}
	}
	return 0;
}

/**
 * Prints all of a doctors patient information
 * @param doc_name doctor's name
 */
void HospitalManager::print_patient_info_doc(std::string doc_name) const {
	for (int i = 0; i < 20; i++) {
		if (doctors[i] != nullptr && doctors[i]->get_name() == doc_name) {
			std::cout << "\nDr." << doctors[i]->get_name() << "'s patient information\n";
			for (int j = 0; j < 50; j++) {
				if (doctors[i]->get_patient(j) != nullptr) {
					Patient *pat = doctors[i]->get_patient(j);
					pat->print_info();
				}
			}
			std::cout << "-----------------------\n\n";
		}
	}
}

/**
 * Prints all the information of the patients in the hospital
 */
void HospitalManager::print_all_patients() const {
	std::cout << "Printing all hospital patient information\n";
	for (int i = 0; i < 101; i++) {
		if (patients[i] != nullptr) {
			patients[i]->print_info();
		}
	}
}

/**
 * Destructor, deletes all the patients and the doctors.
 */
HospitalManager::~HospitalManager() {
	for (int i = 0; i < 20; i++) {
		if (doctors[i] != nullptr) {
			delete doctors[i];
			doctors[i] = nullptr;
		}
	}

	for (int i = 0; i < 101; i++) {
		if (patients[i] != nullptr) {
			delete patients[i];
			patients[i] = nullptr;
		}
	}

	std::cout << "HospitalManager object destroyed successfully\n";
}
