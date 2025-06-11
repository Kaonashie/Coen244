//
// Created by soma on 02/06/25.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"

class Customer: public Person {
private:
	std::string social_insurance_number;

public:
	// Constructors
	Customer(std::string name = "", Date dob = Date(0, 0, 0), std::string social_insurance_number = "");

	// Getter methods
	std::string get_social_insurance_number() const;

	// Setter methods
	void set_social_insurance_number(const std::string &social_insurance_number);

	~Customer();
};

#endif //CUSTOMER_H
