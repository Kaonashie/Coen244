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
	Patient* patients[50]{};
public:
	Doctor();
	Doctor(int id, Date dob, const std::string name);

	int get_id() const;
	Patient* get_patient(int i) const;

	void set_id(int new_id);
	void add_patient(Patient* new_patient);
	void remove_patient(Patient* pat);

	~Doctor();
};



#endif //DOCTOR_H
