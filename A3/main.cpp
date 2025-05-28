//
// Created by soma on 12/05/25.
//

#include "main.h"

#include "HospitalManager.h"
#include "Patient.h"

int main() {
	auto patient_1 = new Patient("Soma", Date(02, 12, 2002), "100", "", Date(), 0);

	auto doctor_1 = new Doctor(0, Date(02, 11, 1996), "Rioux");
	auto manager_1 = new HospitalManager();
	doctor_1->add_patient(patient_1);
	manager_1->admit_patient(*patient_1);
	manager_1->insert_doctor(*doctor_1);
	manager_1->discharge_patient(*patient_1);
    return 0;
}