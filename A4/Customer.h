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
	Customer();
	Customer(const std::string &name, const Date &dob) : Person(name, dob) {}
	std::string get_social_insurance_number() const { return social_insurance_number; }
	void set_social_insurance_number(const std::string &social_insurance_number);
};



#endif //CUSTOMER_H
