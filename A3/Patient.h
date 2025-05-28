//
// Created by soma on 26/05/25.
//

#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"


class Patient : public Person {
private:
	std::string medical_insurance_number;
	std::string doctor_name;
	Date date_admitted;
	int bed_number;
public:
	Patient();
	Patient(std::string name, Date dob, std::string min, std::string d_name, Date date_admitted, int bed_number = 0);

	std::string get_medical_insurance_number() const;
	std::string get_doctor_name() const;
	Date get_date_admitted() const;
	int get_bed_number() const;

	Patient* set_medical_insurance_number(const std::string &new_min);
	Patient* set_doctor_name(const std::string &new_name);
	Patient* set_date_admitted(Date &new_date_admitted);
	Patient* set_bed_number(int new_bed_number);

	~Patient();
};



#endif //PATIENT_H
