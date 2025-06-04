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
	// Constructors
	RealEstateAgent(const std::string &name, const Date &dob, int employee_id, const Date &employment_date) :
		Person(name, dob), employee_id(employee_id), employment_date(employment_date) {
		for (int i = 0; i < 20; i++) {
			properties[i] = nullptr;
		}
	}

	// Getter methods
	int get_employee_id() const { 
		return employee_id; 
	}
	Date get_employment_date() const { 
		return employment_date; 
	}

	// Setter methods
	void set_employee_id(const int employee_id) { 
		this->employee_id = employee_id; 
	}
	void set_employment_date(const Date &employment_date) { 
		this->employment_date = employment_date; 
	}

	bool add_property(Property* prop) {
		for (int i = 0; i < 20; i++) {
			if (properties[i] == nullptr) {
				properties[i] = prop;
				return true;
			}
		}
		return false;
	}

	bool remove_property(Property* prop) {
		for (int i = 0; i < 20; i++) {
			if (properties[i] != nullptr && properties[i]->get_unique_id() == prop->get_unique_id()) {
				properties[i] = nullptr;
				return true;
			}
		}
		return false;
	}
};

#endif //REALESTATEAGENT_H
