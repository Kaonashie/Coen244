//
// Created by soma on 26/05/25.
//

#include "HospitalManager.h"

HospitalManager::HospitalManager() : total_free_beds(100) {
	for (int i = 0; i < 20; i++) {
		doctors[i] = nullptr;
	}

	for (int i = 0; i < 101; i++) {
		patients[i] = nullptr;
	}
}

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

int HospitalManager::get_bed_number(const std::string &patient_name) const {
	for (int i = 1; i < 101; i++) {
		if (patients[i] != nullptr && patients[i]->get_name() == patient_name) {
			return i;
		}
	}
	return 0;
}


void HospitalManager::print_patient_info(std::string doc_name) const {
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

void HospitalManager::print_all_patients() const {
	std::cout << "Printing all hospital patient information\n";
	for (int i = 0; i < 101; i++) {
		if (patients[i] != nullptr) {
			patients[i]->print_info();
		}
	}
}


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
