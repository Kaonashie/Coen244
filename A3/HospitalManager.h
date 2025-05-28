//
// Created by soma on 26/05/25.
//

#ifndef HOSPITALMANAGER_H
#define HOSPITALMANAGER_H
#include <array>
#include <iostream>

#include "Doctor.h"
#include "Patient.h"


class HospitalManager {
private:
	Doctor* doctors[20]{};
	Patient* patients[101]{};
	int total_free_beds;

public:
	HospitalManager();

	Doctor* get_doctor(int index) const {return doctors[index];}
	Patient* get_patient(int index) const {return patients[index];}
	int get_free_beds() const {return total_free_beds;}

	void insert_doctor(Doctor &new_doc) ;
	int admit_patient(Patient &new_pat) ;
	void discharge_patient(Patient &pat) ;

	int get_bed_number(const std::string &patient_name);
	void print_patient_info() const;
	~HospitalManager();
};



#endif //HOSPITALMANAGER_H
