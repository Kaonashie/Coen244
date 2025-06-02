//
// Created by soma on 02/06/25.
//

#ifndef REALESTATEAGENT_H
#define REALESTATEAGENT_H
#include "Person.h"
#include "Property.h"


class RealEstateAgent: public Person {
private:
	int employee_id;
	Date employment_date;
	Property *properties[20];

public:

	RealEstateAgent(const std::string &name, const Date &dob, int employee_id, const Date &employment_date) :
		Person(name, dob), employee_id(employee_id), employment_date(employment_date) {}


	Date get_employment_date() const { return employment_date; }
	int get_employee_id() const { return employee_id; }

	void set_employee_id(const int employee_id) { this->employee_id = employee_id; }
	void set_employment_date(const Date &employment_date) { this->employment_date = employment_date; }
};



#endif //REALESTATEAGENT_H
