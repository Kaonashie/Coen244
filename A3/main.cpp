//
// Created by soma on 12/05/25.
//

#include "main.h"

#include "HospitalManager.h"
#include "Patient.h"

int main() {

	// Initializing the doctors, patients and a HospitalManager
	auto doctor_1 = new Doctor(0, Date(02, 11, 1996), "Rioux");
	auto patient_1 = new Patient("Soma", Date(02, 12, 2002), "100", doctor_1->get_name(), Date());
	auto patient_2 = new Patient("James", Date(05, 9, 2005), "1001", doctor_1->get_name(), Date());
	auto manager_1 = new HospitalManager();

	// Inserting a doctor and admitting a patient
	manager_1->insert_doctor(*doctor_1);
	manager_1->admit_patient(*patient_1);

	// Printing all the doctor's patient info and all the hospital manager's patient info
	std::cout << "\n=== After First Admission ===\n";
	manager_1->print_patient_info_doc("Rioux");
	manager_1->print_all_patients();

	// Admitting second patient.
	manager_1->admit_patient(*patient_2);

	// Printing all patient info after admitting patient
	std::cout << "\n=== After Second Admission ===\n\n";
	manager_1->print_all_patients();

	// Discharging both patients
	manager_1->discharge_patient(*patient_1);
	manager_1->discharge_patient(*patient_2);

	// Clear memory
	delete manager_1;
	std::cout << "Program finished." << std::endl;
	return 0;
}
