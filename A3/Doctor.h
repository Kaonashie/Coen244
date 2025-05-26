//
// Created by soma on 26/05/25.
//

#ifndef DOCTOR_H
#define DOCTOR_H
#include <array>
#include <iostream>

#include "Patient.h"
#include "Person.h"


class Doctor : public Person {
private:
	int id;
	std::array<Patient*, 50> patients;
public:
	Doctor();
	Doctor(int id, std::array<Patient*, 50> patients);

	int get_id() const;
	std::array<Patient*, 50> get_patients() const;

	void set_id(int new_id);
	void set_patients(std::array<Patient*, 50> new_patients);

	~Doctor();
};



#endif //DOCTOR_H
