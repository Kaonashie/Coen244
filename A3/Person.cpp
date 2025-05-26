//
// Created by soma on 26/05/25.
//

#include "Person.h"
Person::Person(): date_of_birth(Date()) {}

Person::Person(std::string name, Date dob) {
	this->name = name;
	this->date_of_birth = dob;
}

std::string Person::get_name() const { return this->name; }

Date Person::get_date_of_birth() const { return this->date_of_birth; }

Person *Person::set_name(const std::string &new_name) {
	this->name = new_name;
	return this;
}

Person *Person::set_date_of_birth(Date &new_dob) {
	this->date_of_birth = new_dob;
	return this;
}

Person::~Person() {
	std::cout << "Person object successfully destroyed.\n";
}
